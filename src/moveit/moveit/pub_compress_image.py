import rclpy
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage
import cv2
import numpy as np

class USBCompressorPublisher(Node):

    def __init__(self):
        super().__init__('usb_compressor_publisher')
        self.publisher_ = self.create_publisher(CompressedImage, 'compressed_image', 10)
        self.cap = cv2.VideoCapture(0)  # 0 for the default camera
        
        if not self.cap.isOpened():
            self.get_logger().error('Failed to open the camera!')
            return

        timer_period = 0.01  # Publish rate in seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def timer_callback(self):
        ret, frame = self.cap.read()
        if not ret:
            self.get_logger().error('Failed to capture image')
            return

        # Compress the image to JPEG format
        encode_param = [int(cv2.IMWRITE_JPEG_QUALITY), 30]  # Quality set to 90
        _, encoded_image = cv2.imencode('.jpg', frame, encode_param)

        # Prepare the CompressedImage message
        compressed_image = CompressedImage()
        compressed_image.header.stamp = self.get_clock().now().to_msg()
        compressed_image.format = 'jpeg'
        compressed_image.data = encoded_image.tobytes()

        # Publish the compressed image
        self.publisher_.publish(compressed_image)
        self.get_logger().info('Publishing compressed image')

def main(args=None):
    rclpy.init(args=args)
    usb_compressor_publisher = USBCompressorPublisher()
    rclpy.spin(usb_compressor_publisher)
    usb_compressor_publisher.cap.release()  # Release the camera when done
    usb_compressor_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
