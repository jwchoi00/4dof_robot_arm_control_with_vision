cmake_minimum_required(VERSION 3.8)
project(moveit_interfaces)


if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(geometry_msgs REQUIRED)#geometry_msg 사용을 위한 의존성 추가
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
# 이 줄을 추가하여 srv 파일을 빌드하도록 설정

set(msg_files
  "msg/MultiBoxPosition.msg"
  "msg/Detection.msg"
  "msg/DetectionArray.msg"
)
set(srv_files
  "srv/BoxPosition.srv"
)
set(action_files
  "action/Conveyor.action"
)
rosidl_generate_interfaces(${PROJECT_NAME}
    ${msg_files}
    ${srv_files}
    ${action_files}
    DEPENDENCIES builtin_interfaces geometry_msgs
)
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
