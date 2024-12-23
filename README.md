# 4dof_robot_arm_control_with_vision

역할

camera로 부터 영상을 받고 yolo로 box Detecting을 한 후 좌표를 반환하고 그 좌표로 로봇 팔을 기동시켜 박스를 집는 코드

- 목표 박스 수령, 로봇팔 기동

  turtlebot3_box_pick_and_place = moveit.turtlebot3_box_pick_and_place:main

- yolo로 check한 좌표를 받아서 로봇팔 좌표계로 변환 후 반환

  check_box_service = moveit.check_box_service:main

- 로봇 팔에게 목표 갯수 전송
  
  box_send_goal = moveit.box_send_goal:main

- compressed Image를 받아서 yolo에 box 위치 추출
  
  check_box_color = moveit.check_box_color:main

- yolo로 check한 좌표를 받아서 compressed Image에 박스 그려줌

  box_draw = moveit.box_draw:main



