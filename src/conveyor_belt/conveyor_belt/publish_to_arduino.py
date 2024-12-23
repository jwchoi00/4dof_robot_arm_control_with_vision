import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32, String
import serial

class ArduinoSerialSender(Node):
    def __init__(self):
        super().__init__('arduino_serial_sender')
        
        # Serial 포트와 속도 설정
        self.serial_port = serial.Serial('/dev/ttyACM0', 115200, timeout=1)
        
        # Subscriber 설정
        self.subscription = self.create_subscription(
            String,
            'serial_command',
            self.send_serial_data,
            10
        )
        self.timer = self.create_timer(1.0, self.read_serial_data)
        self.get_logger().info('Arduino Serial Sender Node Initialized')

    def send_serial_data(self, msg):
        try:
            # ROS 메시지를 Serial로 전송
            self.serial_port.write(f"{msg.data}\n".encode('utf-8'))
            self.get_logger().info(f'Sent to Arduino: {msg.data}')
        except Exception as e:
            self.get_logger().error(f'Error sending data: {str(e)}')

    def read_serial_data(self):
        if self.serial_port.in_waiting > 0:
            received_data = self.serial_port.readline().decode('utf-8').strip()
            self.get_logger().info(f'received_data = {received_data}')

def main(args=None):
    rclpy.init(args=args)
    node = ArduinoSerialSender()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
