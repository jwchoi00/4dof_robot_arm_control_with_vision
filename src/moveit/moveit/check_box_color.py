import rclpy
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage
from std_msgs.msg import String
import cv2
import numpy as np
from ultralytics import YOLO
from moveit_interfaces.msg import DetectionArray, Detection
import json

class CompressedImageSubscriber(Node):
    def __init__(self):
        super().__init__('compressed_image_subscriber')
        # 사전에 생성한 YOLO모델을 불러오기
        self.model = YOLO("/home/g1/ff_ws/src/moveit/resource/best_ver2.pt")

        # Camera 왜곡 보정 파라메터
        self.K = np.array([[1537.87246, 0, 656.024384], [0, 1570.34693, 618.027499], [0, 0, 1]])
        self.d = np.array([0.156609014, -0.487498585, 0.0537193345, 0.00294416872, 3.06628289])

        # 이미지 받아오기
        self.subscription = self.create_subscription(
            CompressedImage,
            'compressed_image',
            self.image_callback,
            10
        )

        # yolo 결과값 전송
        self.detection_publisher = self.create_publisher(DetectionArray, 'detection_results', 10)

    def image_callback(self, msg):
        # numpy array로 변경
        np_arr = np.frombuffer(msg.data, np.uint8)
        # 이미지 풀기
        frame = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)

        if frame is not None:
            self.get_logger().info(f"Received frame of size: {frame.shape}")
            # 카메라 왜곡 보정 풀고 끝트머리 제거
            h, w = frame.shape[:2]
            new_K, roi = cv2.getOptimalNewCameraMatrix(self.K, self.d, (w, h), 1, (w, h))
            frame = cv2.undistort(frame, self.K, self.d, None, new_K)
            x, y, w, h = roi
            frame = frame[y:y+h, x:x+w]
            results = self.model(frame, conf=0.5)  # 정확도 0.5 이상만
            detection_data = []

            # 오브젝트 체크
            for result in results:
                if result.boxes is not None and len(result.boxes) > 0:
                    for box in result.boxes:
                        x1, y1, x2, y2 = box.xyxy[0].tolist()  # box 좌표 넣기
                        center_x = ((x1 + x2) / 2) - (w/2) # 카메라 중심 픽셀 부터 박스 중심 좌표 계산
                        center_y = ((y1 + y2) / 2) - (h/2)
                        confidence = box.conf[0].item()  # 정확도
                        class_id = int(box.cls[0].item())  # class id
                        detection_data.append({
                            'x1': x1, 'y1': y1, 'x2': x2, 'y2': y2, 'center_x': center_x, 'center_y': center_y,
                            'confidence': confidence, 'class_id': class_id
                        })

                        # 박스 그리기
                        cv2.rectangle(frame, (int(x1), int(y1)), (int(x2), int(y2)), (0, 255, 0), 2)
                        label = f"Class: {class_id}, Conf: {confidence:.2f}"
                        cv2.putText(frame, label, (int(x1), int(y1) - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
                else:
                    self.get_logger().info("No detections in the current frame.")

            # 탐지된 객체 정보 보내기
            if detection_data:
                detection_array = DetectionArray()
                for data in detection_data:
                    detection = Detection(
                        x1=data['x1'], y1=data['y1'],
                        x2=data['x2'], y2=data['y2'],
                        center_x=data['center_x'], center_y=data['center_y'],
                        confidence=data['confidence'], class_id=data['class_id']
                    )
                    detection_array.detections.append(detection)
                self.detection_publisher.publish(detection_array)
                self.get_logger().info(f"Published {len(detection_data)} detections.")


def main(args=None):
    rclpy.init(args=args)
    compressed_image_subscriber = CompressedImageSubscriber()
    rclpy.spin(compressed_image_subscriber)
    compressed_image_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
