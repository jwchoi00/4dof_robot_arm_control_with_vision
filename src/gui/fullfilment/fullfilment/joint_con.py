import rclpy
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage
import cv2
import numpy as np
from ultralytics import YOLO  # YOLOv8 라이브러리

class ImagePublisher(Node):
    def __init__(self):
        super().__init__('image_publisher')
        self.publisher_image = self.create_publisher(CompressedImage, 'manipulation', 10)

        # YOLOv8 모델 로드
        self.model = YOLO('/home/seongho/manipulation_ws/src/fullfilment/best.pt')  # best.pt 가중치 파일 로드
        self.get_logger().info("YOLOv8 model loaded successfully.")

        # OpenCV VideoCapture 객체 초기화
        self.cap = cv2.VideoCapture(3)  # 카메라 인덱스 0 (기본 웹캠)
        if not self.cap.isOpened():
            self.get_logger().error("Cannot open the camera")
            rclpy.shutdown()
            return

        # 타이머로 주기적으로 프레임 퍼블리시
        self.timer = self.create_timer(0.1, self.publish_image_callback)  # 10 Hz
        self.get_logger().info('Image Publisher Node has been started.')

    def publish_image_callback(self):
        ret, frame = self.cap.read()
        if not ret:
            self.get_logger().error("Failed to capture image from camera")
            return

        # YOLOv8 객체 인식 수행
        results = self.model(frame)  # 객체 인식 실행
        annotated_frame = results[0].plot()  # 결과를 프레임에 시각화

        # 이미지를 JPEG로 압축
        _, buffer = cv2.imencode('.jpg', annotated_frame)
        compressed_image = CompressedImage()
        compressed_image.header.stamp = self.get_clock().now().to_msg()
        compressed_image.format = 'jpeg'
        compressed_image.data = buffer.tobytes()

        # 퍼블리시
        self.publisher_image.publish(compressed_image)
        self.get_logger().info('Published a frame with YOLOv8 detections to the "manipulation" topic.')

    def destroy_node(self):
        super().destroy_node()
        # 카메라 해제
        self.cap.release()
        self.get_logger().info("Camera released.")


def main(args=None):
    rclpy.init(args=args)
    node = ImagePublisher()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
