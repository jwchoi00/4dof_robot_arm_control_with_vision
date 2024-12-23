// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from moveit_interfaces:msg/DetectionArray.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_INTERFACES__MSG__DETAIL__DETECTION_ARRAY__STRUCT_H_
#define MOVEIT_INTERFACES__MSG__DETAIL__DETECTION_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'detections'
#include "moveit_interfaces/msg/detail/detection__struct.h"

/// Struct defined in msg/DetectionArray in the package moveit_interfaces.
/**
  * DetectionArray.msg
 */
typedef struct moveit_interfaces__msg__DetectionArray
{
  moveit_interfaces__msg__Detection__Sequence detections;
} moveit_interfaces__msg__DetectionArray;

// Struct for a sequence of moveit_interfaces__msg__DetectionArray.
typedef struct moveit_interfaces__msg__DetectionArray__Sequence
{
  moveit_interfaces__msg__DetectionArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} moveit_interfaces__msg__DetectionArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOVEIT_INTERFACES__MSG__DETAIL__DETECTION_ARRAY__STRUCT_H_
