"""
OMX Simulation Action Server
==============================
ROS2 Action Server that receives pick/place/reach commands
and executes them in the MuJoCo simulation.

Architecture (from professor's diagram):
  BT.xml → py_bt_ros → [ROS2 Action] → this node → MuJoCo

Usage:
  ros2 run omx_sim sim_action_server
"""

import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor

from omx_sim_interfaces.action import Pick, Place, Reach
from std_msgs.msg import String

import json
import threading
import time
import sys
import os

# Add the sim_manager path
sys.path.insert(0, os.path.expanduser("~/robotis_mujoco_menagerie/robotis_omx"))
from sim_manager import (
    SimManager, dispatch_pick, dispatch_place,
    update_robot_motion, interpolate_ctrl, start_waypoints,
    make_pick_sequence, make_place_sequence,
    GRIPPER_OPEN, HOME
)
import mujoco
import mujoco.viewer


class SimActionServer(Node):
    """ROS2 node with Action Servers for pick, place, reach."""

    def __init__(self):
        super().__init__('sim_action_server')
        self.get_logger().info("Initializing OMX Simulation Action Server...")

        self.callback_group = ReentrantCallbackGroup()

        # Initialize simulation
        scene_path = os.path.expanduser(
            "~/robotis_mujoco_menagerie/robotis_omx/multi_robot_scene.xml"
        )
        self.sim = SimManager(scene_path)

        # Add all 9 robots
        for rid in range(1, 10):
            self.sim.add_robot(rid)

        # Action Servers
        self._pick_server = ActionServer(
            self, Pick, 'pick',
            execute_callback=self.execute_pick,
            callback_group=self.callback_group
        )

        self._place_server = ActionServer(
            self, Place, 'place',
            execute_callback=self.execute_place,
            callback_group=self.callback_group
        )

        self._reach_server = ActionServer(
            self, Reach, 'reach',
            execute_callback=self.execute_reach,
            callback_group=self.callback_group
        )

        # Simulation thread
        self._sim_lock = threading.Lock()
        self._viewer = None
        self._sim_running = True

        self._sim_thread = threading.Thread(target=self._run_simulation, daemon=True)
        self._sim_thread.start()

        self.get_logger().info("Action servers ready: /pick, /place, /reach")

        # State Publisher (topic for BT condition nodes)
        self._state_pub = self.create_publisher(String, 'sim_state', 10)
        self._state_timer = self.create_timer(1.0, self._publish_state)
        self.get_logger().info("State publisher ready on /sim_state (1Hz)")

    def _run_simulation(self):
        """Run MuJoCo simulation in a separate thread."""
        self._viewer = mujoco.viewer.launch_passive(self.sim.model, self.sim.data)

        while self._sim_running and self._viewer.is_running():
            with self._sim_lock:
                sim_time = self.sim.data.time

                # Update all robot motions
                for rid, robot in self.sim.robots.items():
                    still_moving = update_robot_motion(robot, sim_time)

                    # Attach event
                    if still_moving and hasattr(robot, '_attach_after_wp'):
                        if robot.current_wp_index == robot._attach_after_wp + 1:
                            conflict = self.sim.check_collision(rid, robot._pick_zone)
                            if conflict is not None:
                                self.get_logger().warn(
                                    f"COLLISION: Robot {rid} & Robot {conflict} at Zone {robot._pick_zone}!"
                                )
                                robot._pick_has_object = False
                                other = self.sim.robots[conflict]
                                other._pick_has_object = False
                            elif robot._pick_has_object:
                                obj_name = self.sim.zone_objects.get(robot._pick_zone)
                                if obj_name and robot.holding_object is None:
                                    self.sim.attach_object(rid, obj_name)
                            robot._attach_after_wp = -1

                    # Detach event
                    if still_moving and hasattr(robot, '_detach_after_wp'):
                        if robot.current_wp_index == robot._detach_after_wp + 1:
                            if robot.holding_object is not None:
                                self.sim.detach_object(rid, robot._place_zone)
                            robot._detach_after_wp = -1

                self.sim.update_held_objects()
                mujoco.mj_step(self.sim.model, self.sim.data)

            self._viewer.sync()
            time.sleep(max(0, self.sim.model.opt.timestep - 0.0001))

        self._sim_running = False

    def execute_pick(self, goal_handle):
        """Execute Pick action."""
        robot_id = goal_handle.request.robot_id
        zone_id = goal_handle.request.zone_id

        self.get_logger().info(f"Pick request: Robot {robot_id} → Zone {zone_id}")

        # Dispatch pick
        with self._sim_lock:
            result_str = dispatch_pick(self.sim, robot_id, zone_id)

        if result_str != "STARTED":
            goal_handle.abort()
            result = Pick.Result()
            result.success = False
            result.message = result_str
            return result

        # Wait for completion
        robot = self.sim.robots[robot_id]
        while robot.status != "IDLE":
            # Publish feedback
            feedback = Pick.Feedback()
            feedback.status = robot.status
            goal_handle.publish_feedback(feedback)
            time.sleep(0.1)

        # Check result
        result = Pick.Result()
        if robot.holding_object is not None:
            result.success = True
            result.message = "SUCCESS"
            goal_handle.succeed()
        else:
            result.success = False
            result.message = "FAILED"
            goal_handle.abort()

        self.get_logger().info(f"Pick result: Robot {robot_id} → {result.message}")
        return result

    def execute_place(self, goal_handle):
        """Execute Place action."""
        robot_id = goal_handle.request.robot_id
        zone_id = goal_handle.request.zone_id

        self.get_logger().info(f"Place request: Robot {robot_id} → Zone {zone_id}")

        with self._sim_lock:
            result_str = dispatch_place(self.sim, robot_id, zone_id)

        if result_str != "STARTED":
            goal_handle.abort()
            result = Place.Result()
            result.success = False
            result.message = result_str
            return result

        robot = self.sim.robots[robot_id]
        while robot.status != "IDLE":
            feedback = Place.Feedback()
            feedback.status = robot.status
            goal_handle.publish_feedback(feedback)
            time.sleep(0.1)

        result = Place.Result()
        result.success = True
        result.message = "SUCCESS"
        goal_handle.succeed()

        self.get_logger().info(f"Place result: Robot {robot_id} → Zone {zone_id} SUCCESS")
        return result

    def execute_reach(self, goal_handle):
        """Execute Reach action (move toward zone without picking)."""
        robot_id = goal_handle.request.robot_id
        zone_id = goal_handle.request.zone_id

        self.get_logger().info(f"Reach request: Robot {robot_id} → Zone {zone_id}")

        robot = self.sim.robots[robot_id]

        if robot.status != "IDLE":
            goal_handle.abort()
            result = Reach.Result()
            result.success = False
            result.message = "FAIL_BUSY"
            return result

        if zone_id not in robot.adjacent_zones:
            goal_handle.abort()
            result = Reach.Result()
            result.success = False
            result.message = "FAIL_OUT_OF_REACH"
            return result

        # Build reach-only waypoints (no pick)
        j1 = robot.zone_direction_joint1(zone_id)
        from sim_manager import GRASP_J2, GRASP_J3, GRASP_J4, GRASP_J5
        waypoints = [
            {"name": "Home", "ctrl": HOME, "duration": 1.0},
            {"name": f"Rotate to zone {zone_id}",
             "ctrl": [j1, 0.0, 0.0, 0.0, 0.0, GRIPPER_OPEN], "duration": 1.5},
            {"name": f"Reach zone {zone_id}",
             "ctrl": [j1, GRASP_J2, GRASP_J3, GRASP_J4, GRASP_J5, GRIPPER_OPEN], "duration": 2.0},
            {"name": "Return home",
             "ctrl": HOME, "duration": 2.0},
        ]

        with self._sim_lock:
            robot.status = "REACHING"
            robot.current_target_zone = zone_id

            def on_complete():
                robot.status = "IDLE"
                robot.current_target_zone = None

            start_waypoints(robot, waypoints, self.sim.data.time, on_complete)

        while robot.status != "IDLE":
            feedback = Reach.Feedback()
            feedback.status = robot.status
            goal_handle.publish_feedback(feedback)
            time.sleep(0.1)

        result = Reach.Result()
        result.success = True
        result.message = "SUCCESS"
        goal_handle.succeed()

        self.get_logger().info(f"Reach result: Robot {robot_id} → Zone {zone_id} SUCCESS")
        return result

    def _publish_state(self):
        """Publish simulation state as JSON on /sim_state topic."""
        state = self.sim.get_state()

        msg_data = {
            "zone_objects": {str(k): v for k, v in state["zone_objects"].items()},
            "robot_states": {}
        }
        for rid, rstate in state["robot_states"].items():
            msg_data["robot_states"][str(rid)] = {
                "holding": rstate["holding"],
                "adjacent_zones": rstate["adjacent_zones"],
                "status": rstate["status"],
                "target_zone": rstate["target_zone"],
            }

        msg = String()
        msg.data = json.dumps(msg_data)
        self._state_pub.publish(msg)

    def destroy_node(self):
        self._sim_running = False
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = SimActionServer()

    executor = MultiThreadedExecutor()
    executor.add_node(node)

    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
