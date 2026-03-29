"""
BT Action Server
================
py_bt_ros로부터 고수준 BT 명령(BTPick/BTPlace/BTReach)을 받아
bt_motion_planner로 joint 시퀀스를 계산한 뒤,
sim_action_server로 낮은 수준의 joint 명령을 전달하는 중간 노드.

Architecture:
  py_bt_ros → [BTPick/BTPlace/BTReach] → this node → [Pick/Place/Reach] → sim_action_server

Usage:
  ros2 run omx_sim bt_action_server
"""

import sys
import os

import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, ActionClient
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor

from omx_sim_interfaces.action import Pick, Place, Reach
from omx_sim_interfaces.action import BTPick, BTPlace, BTReach

# bt_motion_planner 경로 추가
sys.path.append(os.path.expanduser('~/omx_multi_robot_sim/omx_bt_planner'))
from bt_motion_planner import get_pick_sequence, get_place_sequence, get_reach_sequence


class BTActionServer(Node):
    def __init__(self):
        super().__init__('bt_action_server')
        cb = ReentrantCallbackGroup()

        # ── 앞단: py_bt_ros로부터 받는 서버 ──────────────────
        ActionServer(self, BTPick,  'bt/pick',  self._handle_pick,  callback_group=cb)
        ActionServer(self, BTPlace, 'bt/place', self._handle_place, callback_group=cb)
        ActionServer(self, BTReach, 'bt/reach', self._handle_reach, callback_group=cb)

        # ── 뒷단: sim_action_server로 보내는 클라이언트 ───────
        self._pick_client  = ActionClient(self, Pick,  'pick',  callback_group=cb)
        self._place_client = ActionClient(self, Place, 'place', callback_group=cb)
        self._reach_client = ActionClient(self, Reach, 'reach', callback_group=cb)

        self.get_logger().info("BTActionServer ready: bt/pick, bt/place, bt/reach")

    # ── 스텝 하나를 sim_action_server로 전송 ─────────────────
    def _send_step(self, step, robot_id):
        action = step['action']

        client = {'pick': self._pick_client,
                  'place': self._place_client,
                  'reach': self._reach_client}[action]

        goal_type = {'pick': Pick,
                     'place': Place,
                     'reach': Reach}[action]

        client.wait_for_server()

        msg = goal_type.Goal()
        msg.robot_id = robot_id
        msg.joints   = step['joints']
        msg.duration = step['duration']

        future = client.send_goal_async(msg)
        rclpy.spin_until_future_complete(self, future)
        gh = future.result()

        if not gh.accepted:
            return False, 'REJECTED'

        res_future = gh.get_result_async()
        rclpy.spin_until_future_complete(self, res_future)
        result = res_future.result().result

        return result.success, result.message

    # ── 시퀀스 전체 실행 ─────────────────────────────────────
    def _execute_sequence(self, goal_handle, sequence, result_type):
        robot_id = goal_handle.request.robot_id

        for i, step in enumerate(sequence):
            feedback = result_type.Feedback()
            feedback.status = f"STEP_{i+1}/{len(sequence)}:{step['action'].upper()}"
            goal_handle.publish_feedback(feedback)

            ok, msg = self._send_step(step, robot_id)
            if not ok:
                goal_handle.abort()
                r = result_type.Result()
                r.success = False
                r.message = msg
                return r

        goal_handle.succeed()
        r = result_type.Result()
        r.success = True
        r.message = 'OK'
        return r

    # ── 각 Action 핸들러 ─────────────────────────────────────
    def _handle_pick(self, goal_handle):
        self.get_logger().info(
            f"BTPick 수신: robot={goal_handle.request.robot_id}, zone={goal_handle.request.zone_id}"
        )
        seq = get_pick_sequence(goal_handle.request.robot_id,
                                goal_handle.request.zone_id)
        return self._execute_sequence(goal_handle, seq, BTPick)

    def _handle_place(self, goal_handle):
        self.get_logger().info(
            f"BTPlace 수신: robot={goal_handle.request.robot_id}, zone={goal_handle.request.zone_id}"
        )
        seq = get_place_sequence(goal_handle.request.robot_id,
                                 goal_handle.request.zone_id)
        return self._execute_sequence(goal_handle, seq, BTPlace)

    def _handle_reach(self, goal_handle):
        self.get_logger().info(
            f"BTReach 수신: robot={goal_handle.request.robot_id}, zone={goal_handle.request.zone_id}"
        )
        seq = get_reach_sequence(goal_handle.request.robot_id,
                                 goal_handle.request.zone_id)
        return self._execute_sequence(goal_handle, seq, BTReach)


def main(args=None):
    rclpy.init(args=args)
    node = BTActionServer()
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