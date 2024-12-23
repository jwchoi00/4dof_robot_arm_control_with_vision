// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from moveit_interfaces:action/Conveyor.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_INTERFACES__ACTION__DETAIL__CONVEYOR__STRUCT_H_
#define MOVEIT_INTERFACES__ACTION__DETAIL__CONVEYOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/Conveyor in the package moveit_interfaces.
typedef struct moveit_interfaces__action__Conveyor_Goal
{
  int32_t red_box_count;
  int32_t blue_box_count;
  int32_t purple_box_count;
} moveit_interfaces__action__Conveyor_Goal;

// Struct for a sequence of moveit_interfaces__action__Conveyor_Goal.
typedef struct moveit_interfaces__action__Conveyor_Goal__Sequence
{
  moveit_interfaces__action__Conveyor_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} moveit_interfaces__action__Conveyor_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/Conveyor in the package moveit_interfaces.
typedef struct moveit_interfaces__action__Conveyor_Result
{
  bool success;
  rosidl_runtime_c__String message;
} moveit_interfaces__action__Conveyor_Result;

// Struct for a sequence of moveit_interfaces__action__Conveyor_Result.
typedef struct moveit_interfaces__action__Conveyor_Result__Sequence
{
  moveit_interfaces__action__Conveyor_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} moveit_interfaces__action__Conveyor_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/Conveyor in the package moveit_interfaces.
typedef struct moveit_interfaces__action__Conveyor_Feedback
{
  int32_t red_boxes_moved;
  int32_t blue_boxes_moved;
  int32_t purple_box_moved;
} moveit_interfaces__action__Conveyor_Feedback;

// Struct for a sequence of moveit_interfaces__action__Conveyor_Feedback.
typedef struct moveit_interfaces__action__Conveyor_Feedback__Sequence
{
  moveit_interfaces__action__Conveyor_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} moveit_interfaces__action__Conveyor_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "moveit_interfaces/action/detail/conveyor__struct.h"

/// Struct defined in action/Conveyor in the package moveit_interfaces.
typedef struct moveit_interfaces__action__Conveyor_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  moveit_interfaces__action__Conveyor_Goal goal;
} moveit_interfaces__action__Conveyor_SendGoal_Request;

// Struct for a sequence of moveit_interfaces__action__Conveyor_SendGoal_Request.
typedef struct moveit_interfaces__action__Conveyor_SendGoal_Request__Sequence
{
  moveit_interfaces__action__Conveyor_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} moveit_interfaces__action__Conveyor_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Conveyor in the package moveit_interfaces.
typedef struct moveit_interfaces__action__Conveyor_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} moveit_interfaces__action__Conveyor_SendGoal_Response;

// Struct for a sequence of moveit_interfaces__action__Conveyor_SendGoal_Response.
typedef struct moveit_interfaces__action__Conveyor_SendGoal_Response__Sequence
{
  moveit_interfaces__action__Conveyor_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} moveit_interfaces__action__Conveyor_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Conveyor in the package moveit_interfaces.
typedef struct moveit_interfaces__action__Conveyor_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} moveit_interfaces__action__Conveyor_GetResult_Request;

// Struct for a sequence of moveit_interfaces__action__Conveyor_GetResult_Request.
typedef struct moveit_interfaces__action__Conveyor_GetResult_Request__Sequence
{
  moveit_interfaces__action__Conveyor_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} moveit_interfaces__action__Conveyor_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "moveit_interfaces/action/detail/conveyor__struct.h"

/// Struct defined in action/Conveyor in the package moveit_interfaces.
typedef struct moveit_interfaces__action__Conveyor_GetResult_Response
{
  int8_t status;
  moveit_interfaces__action__Conveyor_Result result;
} moveit_interfaces__action__Conveyor_GetResult_Response;

// Struct for a sequence of moveit_interfaces__action__Conveyor_GetResult_Response.
typedef struct moveit_interfaces__action__Conveyor_GetResult_Response__Sequence
{
  moveit_interfaces__action__Conveyor_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} moveit_interfaces__action__Conveyor_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "moveit_interfaces/action/detail/conveyor__struct.h"

/// Struct defined in action/Conveyor in the package moveit_interfaces.
typedef struct moveit_interfaces__action__Conveyor_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  moveit_interfaces__action__Conveyor_Feedback feedback;
} moveit_interfaces__action__Conveyor_FeedbackMessage;

// Struct for a sequence of moveit_interfaces__action__Conveyor_FeedbackMessage.
typedef struct moveit_interfaces__action__Conveyor_FeedbackMessage__Sequence
{
  moveit_interfaces__action__Conveyor_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} moveit_interfaces__action__Conveyor_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOVEIT_INTERFACES__ACTION__DETAIL__CONVEYOR__STRUCT_H_
