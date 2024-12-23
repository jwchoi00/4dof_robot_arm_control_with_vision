// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from moveit_interfaces:msg/MultiBoxPosition.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_INTERFACES__MSG__DETAIL__MULTI_BOX_POSITION__STRUCT_H_
#define MOVEIT_INTERFACES__MSG__DETAIL__MULTI_BOX_POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'colors'
#include "rosidl_runtime_c/string.h"
// Member 'positions'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/MultiBoxPosition in the package moveit_interfaces.
typedef struct moveit_interfaces__msg__MultiBoxPosition
{
  rosidl_runtime_c__String__Sequence colors;
  geometry_msgs__msg__Point__Sequence positions;
} moveit_interfaces__msg__MultiBoxPosition;

// Struct for a sequence of moveit_interfaces__msg__MultiBoxPosition.
typedef struct moveit_interfaces__msg__MultiBoxPosition__Sequence
{
  moveit_interfaces__msg__MultiBoxPosition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} moveit_interfaces__msg__MultiBoxPosition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOVEIT_INTERFACES__MSG__DETAIL__MULTI_BOX_POSITION__STRUCT_H_
