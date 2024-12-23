// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from moveit_interfaces:srv/BoxPosition.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_INTERFACES__SRV__DETAIL__BOX_POSITION__STRUCT_H_
#define MOVEIT_INTERFACES__SRV__DETAIL__BOX_POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/BoxPosition in the package moveit_interfaces.
typedef struct moveit_interfaces__srv__BoxPosition_Request
{
  /// 내 로봇 x 포지션
  double x;
  /// 내 로봇 y 포지션
  double y;
  double z;
  /// 원하는 박스 색깔
  int32_t target_color;
} moveit_interfaces__srv__BoxPosition_Request;

// Struct for a sequence of moveit_interfaces__srv__BoxPosition_Request.
typedef struct moveit_interfaces__srv__BoxPosition_Request__Sequence
{
  moveit_interfaces__srv__BoxPosition_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} moveit_interfaces__srv__BoxPosition_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/BoxPosition in the package moveit_interfaces.
typedef struct moveit_interfaces__srv__BoxPosition_Response
{
  bool is_within_range;
  /// 내 로봇팔이 가야할 X좌표
  double goal_x;
  /// 내 로봇팔이 가야할 Y좌표
  double goal_y;
  /// 내 로봇팔이 가야할 Y좌표
  double goal_z;
} moveit_interfaces__srv__BoxPosition_Response;

// Struct for a sequence of moveit_interfaces__srv__BoxPosition_Response.
typedef struct moveit_interfaces__srv__BoxPosition_Response__Sequence
{
  moveit_interfaces__srv__BoxPosition_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} moveit_interfaces__srv__BoxPosition_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOVEIT_INTERFACES__SRV__DETAIL__BOX_POSITION__STRUCT_H_
