"""
OMX Simulation State Publisher
================================
Publishes the simulation state (zone objects, robot states, collisions)
as a ROS2 topic for BT condition nodes.

Usage:
  ros2 run omx_sim state_publisher
  
Topics published:
  /sim_state (std_msgs/String) - JSON encoded simulation state
"""

import rclpy
from rclpy.node import Node
from std_msgs.msg import String

import json
import sys
import os

sys.path.insert(0, os.path.expanduser("~/robotis_mujoco_menagerie/robotis_omx"))
from sim_manager import SimManager


class StatePublisher(Node):
    """Publishes simulation state as JSON on /sim_state topic."""

    def __init__(self, sim=None):
        super().__init__('state_publisher')

        self.sim = sim

        self.publisher_ = self.create_publisher(String, 'sim_state', 10)
        self.timer = self.create_timer(1.0, self.publish_state)  # 1Hz

        self.get_logger().info("State publisher ready on /sim_state (1Hz)")

    def set_sim(self, sim):
        """Set the simulation reference (called by action server)."""
        self.sim = sim

    def publish_state(self):
        """Publish current simulation state."""
        if self.sim is None:
            return

        state = self.sim.get_state()

        # Convert to JSON-serializable format
        msg_data = {
            "zone_objects": {},
            "robot_states": {},
        }

        for zid, obj_name in state["zone_objects"].items():
            msg_data["zone_objects"][str(zid)] = obj_name

        for rid, rstate in state["robot_states"].items():
            msg_data["robot_states"][str(rid)] = {
                "holding": rstate["holding"],
                "adjacent_zones": rstate["adjacent_zones"],
                "status": rstate["status"],
                "target_zone": rstate["target_zone"],
            }

        msg = String()
        msg.data = json.dumps(msg_data)
        self.publisher_.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = StatePublisher()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
