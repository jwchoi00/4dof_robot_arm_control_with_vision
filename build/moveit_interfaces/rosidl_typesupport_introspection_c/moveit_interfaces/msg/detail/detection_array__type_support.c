// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from moveit_interfaces:msg/DetectionArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "moveit_interfaces/msg/detail/detection_array__rosidl_typesupport_introspection_c.h"
#include "moveit_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "moveit_interfaces/msg/detail/detection_array__functions.h"
#include "moveit_interfaces/msg/detail/detection_array__struct.h"


// Include directives for member types
// Member `detections`
#include "moveit_interfaces/msg/detection.h"
// Member `detections`
#include "moveit_interfaces/msg/detail/detection__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  moveit_interfaces__msg__DetectionArray__init(message_memory);
}

void moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_fini_function(void * message_memory)
{
  moveit_interfaces__msg__DetectionArray__fini(message_memory);
}

size_t moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__size_function__DetectionArray__detections(
  const void * untyped_member)
{
  const moveit_interfaces__msg__Detection__Sequence * member =
    (const moveit_interfaces__msg__Detection__Sequence *)(untyped_member);
  return member->size;
}

const void * moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__get_const_function__DetectionArray__detections(
  const void * untyped_member, size_t index)
{
  const moveit_interfaces__msg__Detection__Sequence * member =
    (const moveit_interfaces__msg__Detection__Sequence *)(untyped_member);
  return &member->data[index];
}

void * moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__get_function__DetectionArray__detections(
  void * untyped_member, size_t index)
{
  moveit_interfaces__msg__Detection__Sequence * member =
    (moveit_interfaces__msg__Detection__Sequence *)(untyped_member);
  return &member->data[index];
}

void moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__fetch_function__DetectionArray__detections(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const moveit_interfaces__msg__Detection * item =
    ((const moveit_interfaces__msg__Detection *)
    moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__get_const_function__DetectionArray__detections(untyped_member, index));
  moveit_interfaces__msg__Detection * value =
    (moveit_interfaces__msg__Detection *)(untyped_value);
  *value = *item;
}

void moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__assign_function__DetectionArray__detections(
  void * untyped_member, size_t index, const void * untyped_value)
{
  moveit_interfaces__msg__Detection * item =
    ((moveit_interfaces__msg__Detection *)
    moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__get_function__DetectionArray__detections(untyped_member, index));
  const moveit_interfaces__msg__Detection * value =
    (const moveit_interfaces__msg__Detection *)(untyped_value);
  *item = *value;
}

bool moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__resize_function__DetectionArray__detections(
  void * untyped_member, size_t size)
{
  moveit_interfaces__msg__Detection__Sequence * member =
    (moveit_interfaces__msg__Detection__Sequence *)(untyped_member);
  moveit_interfaces__msg__Detection__Sequence__fini(member);
  return moveit_interfaces__msg__Detection__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_message_member_array[1] = {
  {
    "detections",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_interfaces__msg__DetectionArray, detections),  // bytes offset in struct
    NULL,  // default value
    moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__size_function__DetectionArray__detections,  // size() function pointer
    moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__get_const_function__DetectionArray__detections,  // get_const(index) function pointer
    moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__get_function__DetectionArray__detections,  // get(index) function pointer
    moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__fetch_function__DetectionArray__detections,  // fetch(index, &value) function pointer
    moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__assign_function__DetectionArray__detections,  // assign(index, value) function pointer
    moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__resize_function__DetectionArray__detections  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_message_members = {
  "moveit_interfaces__msg",  // message namespace
  "DetectionArray",  // message name
  1,  // number of fields
  sizeof(moveit_interfaces__msg__DetectionArray),
  moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_message_member_array,  // message members
  moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_init_function,  // function to initialize message memory (memory has to be allocated)
  moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_message_type_support_handle = {
  0,
  &moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_moveit_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_interfaces, msg, DetectionArray)() {
  moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_interfaces, msg, Detection)();
  if (!moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_message_type_support_handle.typesupport_identifier) {
    moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &moveit_interfaces__msg__DetectionArray__rosidl_typesupport_introspection_c__DetectionArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
