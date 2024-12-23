import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
from interfaces.action import Job
import time

class JobActionServer(Node):
    def __init__(self):
        super().__init__('JobActionServer')
        self.__action__server = ActionServer(
            self,
            Job,
            'JobAction',
            self.execute_callback
        )
    
    def execute_callback(self, goal_handle):
        self.get_logger().info(f'Received goal : redbox = {goal_handle.request.redbox}, bluebox = {goal_handle.request.bluebox}, goal = {goal_handle.request.goal}')
        
        feedback_msg = Job.Feedback()
        for i in range(0, 101, 10):
            feedback_msg.feedback = str(i)
            print(feedback_msg.feedback)
            goal_handle.publish_feedback(feedback_msg)
            time.sleep(1)

        
        # 결과 메시지를 설정하고 액션이 성공적으로 끝났음을 알림
        result_msg = Job.Result()
        result_msg.success = True  # 성공 여부를 나타내는 값 설정

        goal_handle.succeed()  # 액션 성공 처리

        self.get_logger().info("Action succeeded.")
        return result_msg

def main(args=None):
    rclpy.init(args=args)
    action_server = JobActionServer()
    rclpy.spin(action_server)
    rclpy.shutdown()

if __name__ == '__main__':
    main()