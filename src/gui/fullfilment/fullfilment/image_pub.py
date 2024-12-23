import rclpy
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage
import cv2
import numpy as np


class ImagePublisher(Node):
    def __init__(self):
        super().__init__('image_publisher_node')
        # Create a publisher for CompressedImage messages
        self.publisher_ = self.create_publisher(CompressedImage, 'manipulation', 10)
        self.timer = self.create_timer(0.1, self.publish_image)  # Publish at 10 Hz
        self.get_logger().info('Image publisher node has been started.')

    def publish_image(self):
        # Create a dummy image using OpenCV (e.g., a gradient or blank image)
        height, width = 480, 640
        image = np.zeros((height, width, 3), dtype=np.uint8)

        # Draw something on the image (e.g., text)
        cv2.putText(image, 'ROS2 Humble', (50, 250), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2, cv2.LINE_AA)

        # Encode the image as JPEG to create a compressed message
        success, encoded_image = cv2.imencode('.jpg', image)
        if not success:
            self.get_logger().error('Failed to encode image!')
            return

        # Create and populate the CompressedImage message
        msg = CompressedImage()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.format = 'jpeg'
        msg.data = encoded_image.tobytes()

        # Publish the message
        self.publisher_.publish(msg)
        self.get_logger().info('Published an image.')


def main(args=None):
    rclpy.init(args=args)
    node = ImagePublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Node interrupted.')
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
