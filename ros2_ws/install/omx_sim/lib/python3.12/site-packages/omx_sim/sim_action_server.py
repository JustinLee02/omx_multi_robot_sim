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
import math

# Add the sim_manager path
sys.path.insert(0, os.path.expanduser("~/omx_multi_robot_sim/robotis_omx"))
from sim_manager import (
    SimManager, update_robot_motion, start_waypoints,
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
            "~/omx_multi_robot_sim/robotis_omx/multi_robot_scene.xml"
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
                for _, robot in self.sim.robots.items():
                    update_robot_motion(robot, sim_time)

                
                self.sim.update_held_objects()
                mujoco.mj_step(self.sim.model, self.sim.data)

            self._viewer.sync()
            time.sleep(max(0, self.sim.model.opt.timestep - 0.0001))

        self._sim_running = False

    def _make_result(self, action_type, goal_handle, success, message):
        result = action_type.Result()
        result.success = bool(success)
        result.message = message
        if success:
            goal_handle.succeed()
        else:
            goal_handle.abort()
        return result

    def _normalize_angle(self, angle):
        return float(angle) % (2.0 * math.pi)

    def _angular_distance(self, a, b):
        diff = abs(self._normalize_angle(a) - self._normalize_angle(b))
        return min(diff, 2.0 * math.pi - diff)

    def _validate_joint_request(self, robot_id, joints, duration):
        if robot_id not in self.sim.robots:
            return "FAIL_INVALID_ROBOT"

        if len(joints) != 6:
            return "FAIL_INVALID_JOINTS"

        if not all(math.isfinite(value) for value in joints):
            return "FAIL_INVALID_JOINTS"

        if not math.isfinite(duration) or duration <= 0.0:
            return "FAIL_INVALID_DURATION"

        robot = self.sim.robots[robot_id]
        ctrlrange = self.sim.model.actuator_ctrlrange
        ctrllimited = getattr(self.sim.model, 'actuator_ctrllimited', None)

        for joint_index, value in enumerate(joints):
            actuator_index = robot.actuator_offset + joint_index
            lower, upper = ctrlrange[actuator_index]
            limited = True if ctrllimited is None else bool(ctrllimited[actuator_index])

            if limited and (value < lower or value > upper):
                self.get_logger().warn(
                    f"Robot {robot_id} joint[{joint_index}]={value:.6f} is outside "
                    f"ctrlrange [{lower:.6f}, {upper:.6f}]"
                )
                return "FAIL_CTRL_RANGE"

        return None

    def _infer_target_from_joint1(self, robot_id, joint1):
        robot = self.sim.robots[robot_id]
        measured = self._normalize_angle(joint1)

        candidates = []
        for cell_number, zone_id in enumerate(robot.adjacent_zones, start=1):
            ref_j1 = self._normalize_angle(robot.zone_direction_joint1(zone_id))
            candidates.append({
                "cell": cell_number,
                "zone": zone_id,
                "ref_j1": ref_j1,
                "distance": self._angular_distance(measured, ref_j1),
            })

        best = min(candidates, key=lambda item: item["distance"])
        return best

    def _start_motion(self, robot_id, joints, duration, status_name, action_name, target_zone, on_complete):
        robot = self.sim.robots[robot_id]

        with self._sim_lock:
            if robot.status != "IDLE":
                return False, "FAIL_BUSY"

            robot.status = status_name
            robot.current_target_zone = target_zone
            robot._last_action_ok = True
            robot._last_action_msg = "SUCCESS"

            waypoints = [
                {
                    "name": f"{action_name} R{robot_id}",
                    "ctrl": joints,
                    "duration": duration,
                }
            ]

            start_waypoints(robot, waypoints, self.sim.data.time, on_complete)

        return True, "STARTED"

    def input_joint(self, goal_handle, action_type, action_name, status_name):
        robot_id = goal_handle.request.robot_id
        joints = [float(v) for v in goal_handle.request.joints]
        duration = float(goal_handle.request.duration)

        validation_error = self._validate_joint_request(robot_id, joints, duration)
        if validation_error is not None:
            return self._make_result(action_type, goal_handle, False, validation_error)

        infer = self._infer_target_from_joint1(robot_id, joints[0])
        cell_number = infer["cell"]
        target_zone = infer["zone"]
        ref_j1 = infer["ref_j1"]
        distance = infer["distance"]

        self.get_logger().info(
            f"{action_name} request: Robot {robot_id} -> "
            f"cell={cell_number}, zone={target_zone}, "
            f"measured_j1={self._normalize_angle(joints[0]):.3f}, "
            f"ref_j1={ref_j1:.3f}, dist={distance:.3f}, "
            f"joints={joints}, duration={duration:.3f}s"
        )

        robot = self.sim.robots[robot_id]

        
        if action_name == "Place":
            if robot.holding_object is None:
                return self._make_result(action_type, goal_handle, False, "FAIL_NOT_HOLDING")
            if target_zone in self.sim.zone_objects:
                return self._make_result(action_type, goal_handle, False, "FAIL_TARGET_ZONE_OCCUPIED")

        def on_complete():
            post_ok = True
            post_msg = "SUCCESS"

            if action_name == "Pick":
                if robot.holding_object is not None:
                    post_ok = False
                    post_msg = "FAIL_ALREADY_HOLDING"
                else:
                    conflict = self.sim.check_collision(robot_id, target_zone)
                    if conflict is not None:
                        post_ok = False
                        post_msg = "FAIL_COLLISION"
                    else:
                        obj_name = self.sim.zone_objects.get(target_zone)
                        if obj_name is None:
                            post_ok = False
                            post_msg = "FAIL_NO_OBJECT"
                        else:
                            self.sim.attach_object(robot_id, obj_name)
                            self.get_logger().info(
                                f"Pick attach: Robot {robot_id} attached '{obj_name}' "
                                f"from cell {cell_number} / zone {target_zone}"
                            )

            elif action_name == "Place":
                if robot.holding_object is None:
                    post_ok = False
                    post_msg = "FAIL_NOT_HOLDING"
                elif target_zone in self.sim.zone_objects:
                    post_ok = False
                    post_msg = "FAIL_TARGET_ZONE_OCCUPIED"
                else:
                    conflict = self.sim.check_collision(robot_id, target_zone)
                    if conflict is not None:
                        post_ok = False
                        post_msg = "FAIL_COLLISION"
                    else:
                        ok = self.sim.detach_object(robot_id, target_zone)
                        if not ok:
                            post_ok = False
                            post_msg = "FAIL_DETACH"
                        else:
                            self.get_logger().info(
                                f"Place detach: Robot {robot_id} detached to "
                                f"cell {cell_number} / zone {target_zone}"
                            )

            robot._last_action_ok = post_ok
            robot._last_action_msg = post_msg
            robot.status = "IDLE"
            robot.current_target_zone = None

        started, message = self._start_motion(
            robot_id=robot_id,
            joints=joints,
            duration=duration,
            status_name=status_name,
            action_name=action_name,
            target_zone=target_zone,
            on_complete=on_complete,
        )
        if not started:
            return self._make_result(action_type, goal_handle, False, message)

        while robot.status != "IDLE":
            feedback = action_type.Feedback()
            feedback.status = f"{robot.status}:cell={cell_number}:zone={target_zone}"
            goal_handle.publish_feedback(feedback)
            time.sleep(0.1)

        post_ok = getattr(robot, "_last_action_ok", True)
        post_msg = getattr(robot, "_last_action_msg", "SUCCESS")

        self.get_logger().info(
            f"{action_name} result: Robot {robot_id} -> cell={cell_number}, zone={target_zone}, {post_msg}"
        )
        return self._make_result(action_type, goal_handle, post_ok, post_msg)

    def execute_pick(self, goal_handle):
        """Execute Pick action with direct joints + attach."""
        return self.input_joint(goal_handle, Pick, "Pick", "PICKING")

    def execute_place(self, goal_handle):
        """Execute Place action with direct joints + detach."""
        return self.input_joint(goal_handle, Place, "Place", "PLACING")

    def execute_reach(self, goal_handle):
        """Execute Reach action with direct joints only."""
        return self.input_joint(goal_handle, Reach, "Reach", "REACHING")

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
