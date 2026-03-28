import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from omx_sim_interfaces.action import Pick, Reach
from bt_motion_planner import get_pick_sequence

class TestBTNode(Node):
    def __init__(self):
        super().__init__('test_bt_node')
        # Reach와 Pick 클라이언트를 둘 다 준비
        self.reach_client = ActionClient(self, Reach, 'reach')
        self.pick_client = ActionClient(self, Pick, 'pick')

    def send_sequence(self, robot_id, zone_id):
        sequence = get_pick_sequence(robot_id, zone_id)
        
        for step_idx, step in enumerate(sequence):
            action_type = step["action"]
            client = self.pick_client if action_type == "pick" else self.reach_client
            msg = Pick.Goal() if action_type == "pick" else Reach.Goal()
            
            client.wait_for_server()
            msg.robot_id = robot_id
            msg.joints = step["joints"]
            msg.duration = step["duration"]
            
            self.get_logger().info(f"동작 {step_idx+1}/{len(sequence)}: [{action_type.upper()}] 전송 중...")
            future = client.send_goal_async(msg)
            rclpy.spin_until_future_complete(self, future)
            goal_handle = future.result()
            
            if not goal_handle.accepted:
                self.get_logger().error("서버가 명령을 거부했습니다.")
                return
                
            res_future = goal_handle.get_result_async()
            rclpy.spin_until_future_complete(self, res_future)
            if not res_future.result().result.success:
                self.get_logger().error("실행 중 에러가 발생했습니다.")
                return

        self.get_logger().info("모든 Pick 시퀀스가 성공적으로 완료되었습니다!")

def main():
    rclpy.init()
    node = TestBTNode()
    # 테스트: 5번 로봇이 6번 구역의 물체를 잡도록 명령
    node.send_sequence(5, 6)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()