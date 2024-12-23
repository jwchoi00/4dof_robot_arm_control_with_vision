import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class CommandPublisher(Node):
    def __init__(self):
        super().__init__('command_publisher')
        self.publisher = self.create_publisher(String, 'serial_command', 10)
        self.timer = self.create_timer(2.0, self.publish_command)
        self.led_status = False
    def publish_command(self):
        msg = String()
        if self.led_status == False:
            msg.data = '1060'  # 전송할 명령
            self.led_status = True
        else:
            msg.data = '530'
            self.led_status = False
        self.publisher.publish(msg)
        self.get_logger().info(f'Published: {msg.data}')

def main(args=None):
    rclpy.init(args=args)
    node = CommandPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
