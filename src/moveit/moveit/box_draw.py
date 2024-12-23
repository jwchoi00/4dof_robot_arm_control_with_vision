import rclpy
from rclpy.node import Node
from sensor_msgs.msg import CompressedImage
from moveit_interfaces.msg import DetectionArray
import cv2
import numpy as np

class ImageDisplayNode(Node):
    def __init__(self):
        super().__init__('image_display_node')
        
        # Subscribe to the compressed image topic
        self.image_subscription = self.create_subscription(
            CompressedImage,
            'compressed_image',  # Topic name to get the compressed image
            self.image_callback,
            10
        )

        # Subscribe to the detection results (DetectionArray) topic
        self.detection_subscription = self.create_subscription(
            DetectionArray,
            'detection_results',  # Topic name for detection results
            self.detection_callback,
            10
        )

        # Camera matrix (K) and distortion coefficients (d)
        self.K = np.array([[1537.87246, 0, 656.024384], [0, 1570.34693, 618.027499], [0, 0, 1]])
        self.d = np.array([0.156609014, -0.487498585, 0.0537193345, 0.00294416872, 3.06628289])
        
        # Initialize empty list to hold detection data
        self.detections = []

    def detection_callback(self, msg):
        # Store detections from the DetectionArray message
        self.detections = [(det.x1, det.y1, det.x2, det.y2, det.center_x, det.center_y, det.confidence, det.class_id) for det in msg.detections]

    def image_callback(self, msg):
        # Convert the byte array to a numpy array
        np_arr = np.frombuffer(msg.data, np.uint8)
        # Decode the image
        frame = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)

        if frame is not None:
            h, w = frame.shape[:2]
            new_K, roi = cv2.getOptimalNewCameraMatrix(self.K, self.d, (w, h), 1, (w, h))
            frame = cv2.undistort(frame, self.K, self.d, None, new_K)
            x, y, w, h = roi
            frame = frame[y:y+h, x:x+w]
            # Loop through the stored detections and draw bounding boxes on the image
            for (x1, y1, x2, y2, center_x, center_y, confidence, class_id) in self.detections:
                # Draw bounding box with green color
                cv2.rectangle(frame, (int(x1), int(y1)), (int(x2), int(y2)), (0, 255, 0), 2)
                cv2.circle(frame, (int((x2+x1)/2), int((y2+y1)/2)), 5, (0, 0, 255), -1)
                # Create a label with both class_id and confidence
                label = f"class_id: {class_id:.2f}, confidence: {confidence:.2f}"
                cv2.putText(frame, label, (int(x1), int(y1) - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)

            # Show the image with bounding boxes
            cv2.imshow("Detected Image", frame)
            cv2.waitKey(1)

def main(args=None):
    rclpy.init(args=args)
    image_display_node = ImageDisplayNode()
    rclpy.spin(image_display_node)
    image_display_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
