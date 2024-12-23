import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from action_msgs.msg import GoalStatus
from moveit_interfaces.action import Conveyor  # Replace 'your_package_name' with your package name

class ConveyorActionClient(Node):
    def __init__(self):
        super().__init__('conveyor_action_client')

        # Create an Action Client for the Conveyor action
        self._action_client = ActionClient(self, Conveyor, 'conveyor_action')

    def send_goal(self, red_box_count, blue_box_count):
        # Wait for the action server to be available
        self._action_client.wait_for_server()
        
        # Create the goal message
        goal_msg = Conveyor.Goal()
        goal_msg.red_box_count = red_box_count
        goal_msg.blue_box_count = blue_box_count

        # Send the goal to the action server
        self._send_goal_future = self._action_client.send_goal_async(
            goal_msg, feedback_callback=self.feedback_callback
        )
        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected.')
            return

        self.get_logger().info('Goal accepted.')
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.result_callback)

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info(
            f'Red boxes moved: {feedback.red_boxes_moved}, Blue boxes moved: {feedback.blue_boxes_moved}'
        )

    def result_callback(self, future):
        result = future.result().result
        if result.success:
            self.get_logger().info(f'Task completed successfully: {result.message}')
        else:
            self.get_logger().info(f'Task failed: {result.message}')

        # Shutdown the client node after receiving the result
        rclpy.shutdown()

def main():
    rclpy.init()

    # Create the client node
    action_client = ConveyorActionClient()

    # User input for the number of boxes
    red_box_count = int(input('Enter the number of red boxes: '))
    blue_box_count = int(input('Enter the number of blue boxes: '))

    # Send the goal to the server
    action_client.send_goal(red_box_count, blue_box_count)

    # Spin the client node
    rclpy.spin(action_client)

if __name__ == '__main__':
    main()
