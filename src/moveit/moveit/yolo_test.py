from ultralytics import YOLO

# YOLOv8 모델 초기화
model = YOLO("yolov8n.yaml")  # lightweight 모델 사용 (yolov8n, yolov8s 등)

# 훈련 실행
model.train(data="/home/g1/ff_ws/src/moveit/resource/find_boxes.v1i.yolov8/data.yaml", epochs=50, imgsz=640)

# 결과 확인
print("Model training complete!")
