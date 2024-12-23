// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from moveit_interfaces:srv/BoxPosition.idl
// generated code does not contain a copyright notice
#include "moveit_interfaces/srv/detail/box_position__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "moveit_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "moveit_interfaces/srv/detail/box_position__struct.h"
#include "moveit_interfaces/srv/detail/box_position__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _BoxPosition_Request__ros_msg_type = moveit_interfaces__srv__BoxPosition_Request;

static bool _BoxPosition_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _BoxPosition_Request__ros_msg_type * ros_message = static_cast<const _BoxPosition_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: x
  {
    cdr << ros_message->x;
  }

  // Field name: y
  {
    cdr << ros_message->y;
  }

  // Field name: z
  {
    cdr << ros_message->z;
  }

  // Field name: target_color
  {
    cdr << ros_message->target_color;
  }

  return true;
}

static bool _BoxPosition_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _BoxPosition_Request__ros_msg_type * ros_message = static_cast<_BoxPosition_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: x
  {
    cdr >> ros_message->x;
  }

  // Field name: y
  {
    cdr >> ros_message->y;
  }

  // Field name: z
  {
    cdr >> ros_message->z;
  }

  // Field name: target_color
  {
    cdr >> ros_message->target_color;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_moveit_interfaces
size_t get_serialized_size_moveit_interfaces__srv__BoxPosition_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _BoxPosition_Request__ros_msg_type * ros_message = static_cast<const _BoxPosition_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name x
  {
    size_t item_size = sizeof(ros_message->x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name y
  {
    size_t item_size = sizeof(ros_message->y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name z
  {
    size_t item_size = sizeof(ros_message->z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name target_color
  {
    size_t item_size = sizeof(ros_message->target_color);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _BoxPosition_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_moveit_interfaces__srv__BoxPosition_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_moveit_interfaces
size_t max_serialized_size_moveit_interfaces__srv__BoxPosition_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: target_color
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = moveit_interfaces__srv__BoxPosition_Request;
    is_plain =
      (
      offsetof(DataType, target_color) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _BoxPosition_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_moveit_interfaces__srv__BoxPosition_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_BoxPosition_Request = {
  "moveit_interfaces::srv",
  "BoxPosition_Request",
  _BoxPosition_Request__cdr_serialize,
  _BoxPosition_Request__cdr_deserialize,
  _BoxPosition_Request__get_serialized_size,
  _BoxPosition_Request__max_serialized_size
};

static rosidl_message_type_support_t _BoxPosition_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_BoxPosition_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, moveit_interfaces, srv, BoxPosition_Request)() {
  return &_BoxPosition_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "moveit_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "moveit_interfaces/srv/detail/box_position__struct.h"
// already included above
// #include "moveit_interfaces/srv/detail/box_position__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _BoxPosition_Response__ros_msg_type = moveit_interfaces__srv__BoxPosition_Response;

static bool _BoxPosition_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _BoxPosition_Response__ros_msg_type * ros_message = static_cast<const _BoxPosition_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: is_within_range
  {
    cdr << (ros_message->is_within_range ? true : false);
  }

  // Field name: goal_x
  {
    cdr << ros_message->goal_x;
  }

  // Field name: goal_y
  {
    cdr << ros_message->goal_y;
  }

  // Field name: goal_z
  {
    cdr << ros_message->goal_z;
  }

  return true;
}

static bool _BoxPosition_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _BoxPosition_Response__ros_msg_type * ros_message = static_cast<_BoxPosition_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: is_within_range
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_within_range = tmp ? true : false;
  }

  // Field name: goal_x
  {
    cdr >> ros_message->goal_x;
  }

  // Field name: goal_y
  {
    cdr >> ros_message->goal_y;
  }

  // Field name: goal_z
  {
    cdr >> ros_message->goal_z;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_moveit_interfaces
size_t get_serialized_size_moveit_interfaces__srv__BoxPosition_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _BoxPosition_Response__ros_msg_type * ros_message = static_cast<const _BoxPosition_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name is_within_range
  {
    size_t item_size = sizeof(ros_message->is_within_range);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name goal_x
  {
    size_t item_size = sizeof(ros_message->goal_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name goal_y
  {
    size_t item_size = sizeof(ros_message->goal_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name goal_z
  {
    size_t item_size = sizeof(ros_message->goal_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _BoxPosition_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_moveit_interfaces__srv__BoxPosition_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_moveit_interfaces
size_t max_serialized_size_moveit_interfaces__srv__BoxPosition_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: is_within_range
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: goal_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: goal_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: goal_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = moveit_interfaces__srv__BoxPosition_Response;
    is_plain =
      (
      offsetof(DataType, goal_z) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _BoxPosition_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_moveit_interfaces__srv__BoxPosition_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_BoxPosition_Response = {
  "moveit_interfaces::srv",
  "BoxPosition_Response",
  _BoxPosition_Response__cdr_serialize,
  _BoxPosition_Response__cdr_deserialize,
  _BoxPosition_Response__get_serialized_size,
  _BoxPosition_Response__max_serialized_size
};

static rosidl_message_type_support_t _BoxPosition_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_BoxPosition_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, moveit_interfaces, srv, BoxPosition_Response)() {
  return &_BoxPosition_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "moveit_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "moveit_interfaces/srv/box_position.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t BoxPosition__callbacks = {
  "moveit_interfaces::srv",
  "BoxPosition",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, moveit_interfaces, srv, BoxPosition_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, moveit_interfaces, srv, BoxPosition_Response)(),
};

static rosidl_service_type_support_t BoxPosition__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &BoxPosition__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, moveit_interfaces, srv, BoxPosition)() {
  return &BoxPosition__handle;
}

#if defined(__cplusplus)
}
#endif
