"""
Multi-Robot Pick-and-Place Simulation Manager
==============================================
Phase 1: Single robot (R5, center) pick-and-place test.

Uses weld constraint to attach object to gripper on pick,
removing the need for friction-based grasping.

Usage:
  cd ~/robotis_mujoco_menagerie/robotis_omx
  python sim_manager.py          # Run pick-and-place demo
  python sim_manager.py --find   # Interactive mode to find waypoints

Requirements:
  pip install mujoco numpy
"""

import mujoco
import mujoco.viewer
import numpy as np
import time
import argparse


# ──────────────────────────────────────────────
# Configuration
# ──────────────────────────────────────────────
SCENE_XML = "multi_robot_scene.xml"
CELL_SIZE = 0.4

# Grid layout helpers
def zone_center(zone_id):
    idx = zone_id - 1
    col = idx % 4
    row = idx // 4
    x = col * CELL_SIZE + CELL_SIZE / 2
    y = (3 - row) * CELL_SIZE + CELL_SIZE / 2
    return x, y

def robot_position(robot_id):
    idx = robot_id - 1
    col = idx % 3
    row = idx // 3
    x = (col + 1) * CELL_SIZE
    y = (3 - row) * CELL_SIZE
    return x, y

def robot_adjacent_zones(robot_id):
    idx = robot_id - 1
    col = idx % 3
    row = idx // 3
    top_left = row * 4 + col + 1
    return [top_left, top_left + 1, top_left + 4, top_left + 4 + 1]


# ──────────────────────────────────────────────
# Robot Controller
# ──────────────────────────────────────────────
class RobotController:
    """Controls a single OMX robot in the simulation."""

    # Actuator indices within each robot (6 actuators per robot)
    J1, J2, J3, J4, J5, GRIP = 0, 1, 2, 3, 4, 5
    ACTUATORS_PER_ROBOT = 6

    # Gripper values
    GRIPPER_OPEN = 0.916
    GRIPPER_CLOSE = 0.0

    def __init__(self, model, data, robot_id):
        self.model = model
        self.data = data
        self.robot_id = robot_id
        self.prefix = f"r{robot_id}_"

        # Find actuator indices for this robot
        self.actuator_offset = (robot_id - 1) * self.ACTUATORS_PER_ROBOT

        # State
        self.holding_object = None
        self.weld_id = None
        self.status = "IDLE"           # IDLE, MOVING, PICKING, PLACING
        self.current_target_zone = None  # Zone the robot is currently reaching for

        # Async waypoint execution state
        self.waypoint_queue = []
        self.current_wp_index = 0
        self.wp_start_time = None
        self.prev_ctrl = None
        self.action_callback = None  # Called when waypoint sequence completes

        # Get robot base position
        self.base_x, self.base_y = robot_position(robot_id)
        self.adjacent_zones = robot_adjacent_zones(robot_id)

        print(f"  Robot {robot_id}: pos=({self.base_x:.2f}, {self.base_y:.2f}), "
              f"zones={self.adjacent_zones}")

    def set_ctrl(self, joint_values):
        """Set all 6 actuator values [J1-J5, Gripper]."""
        for i, val in enumerate(joint_values):
            self.data.ctrl[self.actuator_offset + i] = val

    def get_ctrl(self):
        """Get current control values."""
        return [self.data.ctrl[self.actuator_offset + i] for i in range(6)]

    def get_joint_pos(self):
        """Get current joint positions."""
        positions = []
        for jname in ["Joint1", "Joint2", "Joint3", "Joint4", "Joint5", "Gripper", "Gripper_mimic"]:
            jid = mujoco.mj_name2id(self.model, mujoco.mjtObj.mjOBJ_JOINT, self.prefix + jname)
            if jid >= 0:
                addr = self.model.jnt_qposadr[jid]
                positions.append(self.data.qpos[addr])
        return positions

    def get_gripper_body_id(self):
        """Get the body ID of the gripper link."""
        return mujoco.mj_name2id(self.model, mujoco.mjtObj.mjOBJ_BODY, self.prefix + "link6")

    def get_gripper_pos(self):
        """Get the world position of the gripper."""
        bid = self.get_gripper_body_id()
        return self.data.xpos[bid].copy()

    def zone_direction_joint1(self, zone_id):
        """Calculate Joint1 angle to point toward a zone center."""
        zx, zy = zone_center(zone_id)
        dx = zx - self.base_x
        dy = zy - self.base_y
        return np.arctan2(dy, dx)


# ──────────────────────────────────────────────
# Simulation Manager
# ──────────────────────────────────────────────
class SimManager:
    """Manages the multi-robot simulation."""

    def __init__(self, scene_xml=SCENE_XML):
        self.model = mujoco.MjModel.from_xml_path(scene_xml)
        self.data = mujoco.MjData(self.model)

        # Initialize
        mujoco.mj_resetData(self.model, self.data)
        mujoco.mj_forward(self.model, self.data)

        # Zone state: which zones have objects
        self.zone_objects = {}  # zone_id -> object body name

        # Find objects in scene
        self._init_objects()

        # Robot controllers
        self.robots = {}

        print("=" * 50)
        print("  Multi-Robot Simulation Manager")
        print("=" * 50)
        print(f"  Actuators: {self.model.nu}")
        print(f"  Bodies: {self.model.nbody}")
        print(f"  Objects: {list(self.zone_objects.items())}")
        print()

    def _init_objects(self):
        """Find all objects and their initial zones."""
        for i in range(self.model.nbody):
            name = mujoco.mj_id2name(self.model, mujoco.mjtObj.mjOBJ_BODY, i)
            if name and name.startswith("obj_zone"):
                zone_id = int(name.replace("obj_zone", ""))
                self.zone_objects[zone_id] = name

    def add_robot(self, robot_id):
        """Add a robot controller."""
        controller = RobotController(self.model, self.data, robot_id)
        self.robots[robot_id] = controller
        return controller

    def attach_object(self, robot_id, object_body_name):
        """Attach an object to a robot's gripper using weld equality constraint.
        
        This is done by modifying the object's position to follow the gripper
        at each timestep (simpler and more reliable than runtime weld).
        """
        robot = self.robots[robot_id]
        robot.holding_object = object_body_name

        # Get object body id and disable its freejoint by setting velocity to zero
        obj_bid = mujoco.mj_name2id(self.model, mujoco.mjtObj.mjOBJ_BODY, object_body_name)

        # Remove from zone tracking
        for zid, oname in list(self.zone_objects.items()):
            if oname == object_body_name:
                del self.zone_objects[zid]
                break

        print(f"  [ATTACH] Robot {robot_id} grabbed {object_body_name}")

    def detach_object(self, robot_id, target_zone_id):
        """Detach object from robot's gripper and place it in target zone."""
        robot = self.robots[robot_id]
        if robot.holding_object is None:
            print(f"  [WARN] Robot {robot_id} not holding anything")
            return False

        obj_name = robot.holding_object
        obj_bid = mujoco.mj_name2id(self.model, mujoco.mjtObj.mjOBJ_BODY, obj_name)

        # Get object's freejoint qpos address
        obj_jnt_name = obj_name + "_joint"
        obj_jid = mujoco.mj_name2id(self.model, mujoco.mjtObj.mjOBJ_JOINT, obj_jnt_name)
        obj_qadr = self.model.jnt_qposadr[obj_jid]

        # Place at zone center
        zx, zy = zone_center(target_zone_id)
        self.data.qpos[obj_qadr:obj_qadr+3] = [zx, zy, 0.015]
        self.data.qpos[obj_qadr+3:obj_qadr+7] = [1, 0, 0, 0]  # quaternion
        self.data.qvel[self.model.jnt_dofadr[obj_jid]:self.model.jnt_dofadr[obj_jid]+6] = 0

        # Update tracking
        self.zone_objects[target_zone_id] = obj_name
        robot.holding_object = None

        print(f"  [DETACH] Robot {robot_id} placed {obj_name} in zone {target_zone_id}")
        return True

    def update_held_objects(self):
        """Move held objects to follow gripper positions. Call each timestep."""
        for rid, robot in self.robots.items():
            if robot.holding_object is not None:
                obj_name = robot.holding_object
                obj_jnt_name = obj_name + "_joint"
                obj_jid = mujoco.mj_name2id(self.model, mujoco.mjtObj.mjOBJ_JOINT, obj_jnt_name)
                obj_qadr = self.model.jnt_qposadr[obj_jid]

                # Get gripper position
                grip_pos = robot.get_gripper_pos()

                # Set object position to gripper position
                self.data.qpos[obj_qadr:obj_qadr+3] = grip_pos
                self.data.qpos[obj_qadr+3:obj_qadr+7] = [1, 0, 0, 0]

                # Zero velocity
                dof_adr = self.model.jnt_dofadr[obj_jid]
                self.data.qvel[dof_adr:dof_adr+6] = 0

    def check_collision(self, robot_id, zone_id):
        """Check if another robot is already reaching for the same zone."""
        for rid, robot in self.robots.items():
            if rid != robot_id and robot.current_target_zone == zone_id:
                return rid  # Return the conflicting robot ID
        return None

    def get_state(self):
        """Get current simulation state for BT condition nodes."""
        state = {
            "zone_objects": dict(self.zone_objects),
            "robot_states": {}
        }
        for rid, robot in self.robots.items():
            state["robot_states"][rid] = {
                "holding": robot.holding_object,
                "adjacent_zones": robot.adjacent_zones,
                "status": robot.status,
                "target_zone": robot.current_target_zone,
            }
        return state


# ──────────────────────────────────────────────
# Motion primitives (async)
# ──────────────────────────────────────────────
def interpolate_ctrl(ctrl_start, ctrl_end, alpha):
    """Cosine easing interpolation."""
    alpha = np.clip(alpha, 0.0, 1.0)
    smooth = 0.5 * (1 - np.cos(np.pi * alpha))
    return (1 - smooth) * np.array(ctrl_start) + smooth * np.array(ctrl_end)


def start_waypoints(robot, waypoints, sim_time, callback=None):
    """Start async waypoint execution for a robot."""
    robot.waypoint_queue = waypoints
    robot.current_wp_index = 0
    robot.wp_start_time = sim_time
    robot.prev_ctrl = np.array(robot.get_ctrl())
    robot.action_callback = callback

    if waypoints:
        print(f"  [{sim_time:.1f}s] R{robot.robot_id} >> {waypoints[0]['name']}")


def update_robot_motion(robot, sim_time):
    """Update one robot's motion. Returns True if still moving, False if done."""
    if not robot.waypoint_queue or robot.current_wp_index >= len(robot.waypoint_queue):
        return False

    wp = robot.waypoint_queue[robot.current_wp_index]
    elapsed = sim_time - robot.wp_start_time
    alpha = elapsed / wp["duration"]

    target = np.array(wp["ctrl"])
    robot.set_ctrl(interpolate_ctrl(robot.prev_ctrl, target, alpha))

    if elapsed >= wp["duration"]:
        robot.prev_ctrl = target.copy()
        robot.current_wp_index += 1
        robot.wp_start_time = sim_time

        if robot.current_wp_index >= len(robot.waypoint_queue):
            # Sequence complete
            if robot.action_callback:
                robot.action_callback()
            return False
        else:
            next_wp = robot.waypoint_queue[robot.current_wp_index]
            print(f"  [{sim_time:.1f}s] R{robot.robot_id} >> {next_wp['name']}")

    return True


# ──────────────────────────────────────────────
# High-level actions (async)
# ──────────────────────────────────────────────

# Grasp pose from viewer tuning
GRASP_J2, GRASP_J3, GRASP_J4, GRASP_J5 = 0.38, 0.0, 0.558, 0.0
GRIPPER_OPEN = 0.916
GRIPPER_CLOSE = 0.0
HOME = [0.0, 0.0, 0.0, 0.0, 0.0, GRIPPER_OPEN]


def make_pick_sequence(robot, zone_id):
    """Full pick waypoint sequence: home → rotate → reach → close → lift → home."""
    j1 = robot.zone_direction_joint1(zone_id)
    return [
        {"name": f"Home", "ctrl": HOME, "duration": 1.0},
        {"name": f"Rotate to zone {zone_id}",
         "ctrl": [j1, 0.0, 0.0, 0.0, 0.0, GRIPPER_OPEN], "duration": 1.5},
        {"name": f"Reach zone {zone_id}",
         "ctrl": [j1, GRASP_J2, GRASP_J3, GRASP_J4, GRASP_J5, GRIPPER_OPEN], "duration": 2.0},
        {"name": "Close gripper",
         "ctrl": [j1, GRASP_J2, GRASP_J3, GRASP_J4, GRASP_J5, GRIPPER_CLOSE], "duration": 1.0},
        {"name": "Lift up",
         "ctrl": [j1, 0.1, 0.0, 0.2, 0.0, GRIPPER_CLOSE], "duration": 1.5},
        {"name": "Return home",
         "ctrl": [0.0, 0.0, 0.0, 0.0, 0.0, GRIPPER_CLOSE], "duration": 1.5},
    ]


def make_place_sequence(robot, zone_id):
    """Full place waypoint sequence: rotate → lower → open → lift → home."""
    j1 = robot.zone_direction_joint1(zone_id)
    return [
        {"name": f"Rotate to zone {zone_id}",
         "ctrl": [j1, 0.0, 0.0, 0.0, 0.0, GRIPPER_CLOSE], "duration": 1.5},
        {"name": f"Lower to zone {zone_id}",
         "ctrl": [j1, GRASP_J2, GRASP_J3, GRASP_J4, GRASP_J5, GRIPPER_CLOSE], "duration": 2.0},
        {"name": "Open gripper",
         "ctrl": [j1, GRASP_J2, GRASP_J3, GRASP_J4, GRASP_J5, GRIPPER_OPEN], "duration": 1.0},
        {"name": "Lift up",
         "ctrl": [j1, 0.1, 0.0, 0.2, 0.0, GRIPPER_OPEN], "duration": 1.5},
        {"name": "Return home",
         "ctrl": HOME, "duration": 1.5},
    ]


# ──────────────────────────────────────────────
# Async action dispatchers
# ──────────────────────────────────────────────
def dispatch_pick(sim, robot_id, zone_id):
    """Start an async pick action. Returns status string.
    Collision is checked at grasp time, not dispatch time.
    Both robots move toward the zone; if collision, both fail."""
    robot = sim.robots[robot_id]

    if robot.status != "IDLE":
        print(f"  [BUSY] Robot {robot_id} is {robot.status}")
        return "FAIL_BUSY"

    if zone_id not in robot.adjacent_zones:
        print(f"  [FAIL] Zone {zone_id} not reachable by Robot {robot_id}")
        return "FAIL_OUT_OF_REACH"

    has_object = zone_id in sim.zone_objects

    print(f"\n{'='*40}")
    print(f"  PICK: Robot {robot_id} → Zone {zone_id} {'(has object)' if has_object else '(empty!)'}")
    print(f"{'='*40}")

    robot.status = "PICKING"
    robot.current_target_zone = zone_id

    waypoints = make_pick_sequence(robot, zone_id)

    attach_after_wp = 3  # after "Close gripper"

    def on_complete():
        robot.status = "IDLE"
        robot.current_target_zone = None
        if robot.holding_object:
            print(f"  [RESULT] Robot {robot_id} pick SUCCESS")
        else:
            print(f"  [RESULT] Robot {robot_id} pick FAILED")

    robot._pick_zone = zone_id
    robot._pick_has_object = has_object
    robot._attach_after_wp = attach_after_wp
    robot.action_callback = on_complete

    start_waypoints(robot, waypoints, sim.data.time, on_complete)
    return "STARTED"


def dispatch_place(sim, robot_id, zone_id):
    """Start an async place action. Returns status string."""
    robot = sim.robots[robot_id]

    if robot.status != "IDLE":
        print(f"  [BUSY] Robot {robot_id} is {robot.status}")
        return "FAIL_BUSY"

    if zone_id not in robot.adjacent_zones:
        print(f"  [FAIL] Zone {zone_id} not reachable by Robot {robot_id}")
        return "FAIL_OUT_OF_REACH"

    if robot.holding_object is None:
        print(f"  [FAIL] Robot {robot_id} not holding anything")
        return "FAIL_NOT_HOLDING"

    # Check if zone already has an object
    if zone_id in sim.zone_objects:
        print(f"  [FAIL] Zone {zone_id} already occupied by {sim.zone_objects[zone_id]}")
        return "FAIL_ZONE_OCCUPIED"

    # Collision check
    conflict = sim.check_collision(robot_id, zone_id)
    if conflict is not None:
        print(f"  [COLLISION] Robot {robot_id} & Robot {conflict} both targeting Zone {zone_id}!")
        return "FAIL_COLLISION"

    print(f"\n{'='*40}")
    print(f"  PLACE: Robot {robot_id} → Zone {zone_id}")
    print(f"{'='*40}")

    robot.status = "PLACING"
    robot.current_target_zone = zone_id

    waypoints = make_place_sequence(robot, zone_id)

    # Detach after "Open gripper" (index 2)
    robot._detach_after_wp = 2
    robot._place_zone = zone_id

    def on_complete():
        robot.status = "IDLE"
        robot.current_target_zone = None
        print(f"  [RESULT] Robot {robot_id} place SUCCESS in zone {zone_id}")

    start_waypoints(robot, waypoints, sim.data.time, on_complete)
    return "STARTED"


# ──────────────────────────────────────────────
# Main simulation loop
# ──────────────────────────────────────────────
def run_simulation(sim, viewer):
    """Main loop: updates all robots simultaneously."""
    while viewer.is_running():
        sim_time = sim.data.time

        # Update all robot motions
        for rid, robot in sim.robots.items():
            still_moving = update_robot_motion(robot, sim_time)

            # Check for mid-sequence events (attach/detach at specific waypoints)
            if still_moving and hasattr(robot, '_attach_after_wp'):
                if robot.current_wp_index == robot._attach_after_wp + 1 and robot._pick_has_object:
                    if robot.holding_object is None:
                        obj_name = sim.zone_objects.get(robot._pick_zone)
                        if obj_name:
                            sim.attach_object(rid, obj_name)
                    robot._attach_after_wp = -1  # Don't trigger again

            if still_moving and hasattr(robot, '_detach_after_wp'):
                if robot.current_wp_index == robot._detach_after_wp + 1:
                    if robot.holding_object is not None:
                        sim.detach_object(rid, robot._place_zone)
                    robot._detach_after_wp = -1  # Don't trigger again

        # Update held objects
        sim.update_held_objects()

        # Step simulation
        mujoco.mj_step(sim.model, sim.data)
        viewer.sync()
        time.sleep(max(0, sim.model.opt.timestep - 0.0001))


# ──────────────────────────────────────────────
# Interactive waypoint finder
# ──────────────────────────────────────────────
def find_waypoints_mode(sim):
    """Interactive mode to find joint values using the viewer."""
    robot = sim.add_robot(5)

    print("\n" + "=" * 50)
    print("  INTERACTIVE WAYPOINT FINDER")
    print("=" * 50)
    print("  Use the MuJoCo viewer Control panel to move joints.")
    print("  Robot 5 actuators are indices 24-29")
    print(f"  R5 adjacent zones: {robot.adjacent_zones}")
    print("  Press Ctrl+C to exit.")
    print("=" * 50)

    with mujoco.viewer.launch_passive(sim.model, sim.data) as viewer:
        while viewer.is_running():
            mujoco.mj_step(sim.model, sim.data)
            viewer.sync()
            time.sleep(sim.model.opt.timestep)


# ──────────────────────────────────────────────
# Demo scenarios
# ──────────────────────────────────────────────
def demo_single(sim):
    """Demo: Single robot (R5) picks zone 6, places zone 11."""
    sim.add_robot(5)

    print("\n" + "=" * 50)
    print("  DEMO: Robot 5 picks zone 6 → places zone 11")
    print("=" * 50)

    with mujoco.viewer.launch_passive(sim.model, sim.data) as viewer:
        # Wait for viewer
        for _ in range(200):
            mujoco.mj_step(sim.model, sim.data)
            viewer.sync()
            time.sleep(sim.model.opt.timestep)

        # Pick
        dispatch_pick(sim, 5, 6)
        # Run until pick completes
        while sim.robots[5].status != "IDLE":
            run_one_step(sim, viewer)

        # Place
        dispatch_place(sim, 5, 11)
        while sim.robots[5].status != "IDLE":
            run_one_step(sim, viewer)

        print(f"\n  Final state: {sim.get_state()['zone_objects']}")
        print("  Demo complete. Close viewer to exit.")

        while viewer.is_running():
            sim.update_held_objects()
            mujoco.mj_step(sim.model, sim.data)
            viewer.sync()
            time.sleep(sim.model.opt.timestep)


def demo_multi(sim):
    """Demo: Multiple robots act simultaneously.
    
    Scenario:
    - R1 picks zone 1, places zone 2
    - R5 picks zone 6, places zone 11
    - R9 picks zone 16, places zone 15
    - R1 and R2 both try zone 2 (collision test)
    """
    for rid in range(1, 10):
        sim.add_robot(rid)

    print("\n" + "=" * 50)
    print("  DEMO: Multi-robot simultaneous actions")
    print("=" * 50)
    print(f"  Initial objects: {sim.get_state()['zone_objects']}")
    print()

    with mujoco.viewer.launch_passive(sim.model, sim.data) as viewer:
        # Wait for viewer
        for _ in range(200):
            mujoco.mj_step(sim.model, sim.data)
            viewer.sync()
            time.sleep(sim.model.opt.timestep)

        # === Phase 1: Three robots pick simultaneously ===
        print("\n>>> PHASE 1: Simultaneous picks")
        dispatch_pick(sim, 1, 1)    # R1 picks zone 1 (red box)
        dispatch_pick(sim, 5, 6)    # R5 picks zone 6 (blue box)
        dispatch_pick(sim, 9, 16)   # R9 picks zone 16 (orange box)

        # Run until all complete
        while any(sim.robots[rid].status != "IDLE" for rid in [1, 5, 9]):
            if not run_one_step(sim, viewer):
                return

        print(f"\n  After picks: {sim.get_state()['zone_objects']}")

        # === Phase 2: Three robots place simultaneously ===
        print("\n>>> PHASE 2: Simultaneous places")
        dispatch_place(sim, 1, 2)    # R1 places zone 2
        dispatch_place(sim, 5, 11)   # R5 places zone 11
        dispatch_place(sim, 9, 15)   # R9 places zone 15

        while any(sim.robots[rid].status != "IDLE" for rid in [1, 5, 9]):
            if not run_one_step(sim, viewer):
                return

        print(f"\n  After places: {sim.get_state()['zone_objects']}")

        # === Phase 3: Collision test ===
        print("\n>>> PHASE 3: Collision test (R1 & R2 both target zone 2)")
        dispatch_pick(sim, 1, 2)     # R1 reaches for zone 2
        dispatch_pick(sim, 2, 2)     # R2 also reaches for zone 2 → both move, collision at grasp

        while any(sim.robots[rid].status != "IDLE" for rid in [1, 2]):
            if not run_one_step(sim, viewer):
                return

        print(f"\n  Final state: {sim.get_state()['zone_objects']}")
        print("  Demo complete. Close viewer to exit.")

        while viewer.is_running():
            sim.update_held_objects()
            mujoco.mj_step(sim.model, sim.data)
            viewer.sync()
            time.sleep(sim.model.opt.timestep)


def run_one_step(sim, viewer):
    """Run one simulation step with all robot updates. Returns False if viewer closed."""
    if not viewer.is_running():
        return False

    sim_time = sim.data.time
    for rid, robot in sim.robots.items():
        still_moving = update_robot_motion(robot, sim_time)

        # Check for attach event (after "Close gripper" waypoint)
        if still_moving and hasattr(robot, '_attach_after_wp'):
            if robot.current_wp_index == robot._attach_after_wp + 1:
                # Collision check at grasp time
                conflict = sim.check_collision(rid, robot._pick_zone)
                if conflict is not None:
                    # COLLISION: both robots fail
                    print(f"  [COLLISION] Robot {rid} & Robot {conflict} collided at Zone {robot._pick_zone}!")
                    print(f"  [COLLISION] Both robots return empty-handed.")
                    robot._pick_has_object = False  # Force fail
                    # Also force the other robot to fail
                    other = sim.robots[conflict]
                    other._pick_has_object = False
                elif robot._pick_has_object:
                    obj_name = sim.zone_objects.get(robot._pick_zone)
                    if obj_name and robot.holding_object is None:
                        sim.attach_object(rid, obj_name)
                robot._attach_after_wp = -1  # Don't trigger again

        # Check for detach event (after "Open gripper" waypoint)
        if still_moving and hasattr(robot, '_detach_after_wp'):
            if robot.current_wp_index == robot._detach_after_wp + 1:
                if robot.holding_object is not None:
                    sim.detach_object(rid, robot._place_zone)
                robot._detach_after_wp = -1

    sim.update_held_objects()
    mujoco.mj_step(sim.model, sim.data)
    viewer.sync()
    time.sleep(max(0, sim.model.opt.timestep - 0.0001))
    return True


# ──────────────────────────────────────────────
# Main
# ──────────────────────────────────────────────
if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Multi-Robot Simulation Manager")
    parser.add_argument("--find", action="store_true", help="Interactive waypoint finder mode")
    parser.add_argument("--single", action="store_true", help="Single robot demo (R5)")
    parser.add_argument("--multi", action="store_true", help="Multi-robot demo (9 robots)")
    args = parser.parse_args()

    sim = SimManager()

    if args.find:
        find_waypoints_mode(sim)
    elif args.single:
        demo_single(sim)
    elif args.multi:
        demo_multi(sim)
    else:
        # Default: multi-robot demo
        demo_multi(sim)
