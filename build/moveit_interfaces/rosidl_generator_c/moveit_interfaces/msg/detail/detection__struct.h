// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from moveit_interfaces:msg/Detection.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_INTERFACES__MSG__DETAIL__DETECTION__STRUCT_H_
#define MOVEIT_INTERFACES__MSG__DETAIL__DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Detection in the package moveit_interfaces.
typedef struct moveit_interfaces__msg__Detection
{
  float x1;
  float y1;
  float x2;
  float y2;
  float center_x;
  float center_y;
  float confidence;
  int32_t class_id;
} moveit_interfaces__msg__Detection;

// Struct for a sequence of moveit_interfaces__msg__Detection.
typedef struct moveit_interfaces__msg__Detection__Sequence
{
  moveit_interfaces__msg__Detection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} moveit_interfaces__msg__Detection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOVEIT_INTERFACES__MSG__DETAIL__DETECTION__STRUCT_H_
