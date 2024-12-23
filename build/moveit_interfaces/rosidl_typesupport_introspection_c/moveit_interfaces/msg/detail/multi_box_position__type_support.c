// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from moveit_interfaces:msg/MultiBoxPosition.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "moveit_interfaces/msg/detail/multi_box_position__rosidl_typesupport_introspection_c.h"
#include "moveit_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "moveit_interfaces/msg/detail/multi_box_position__functions.h"
#include "moveit_interfaces/msg/detail/multi_box_position__struct.h"


// Include directives for member types
// Member `colors`
#include "rosidl_runtime_c/string_functions.h"
// Member `positions`
#include "geometry_msgs/msg/point.h"
// Member `positions`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__MultiBoxPosition_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  moveit_interfaces__msg__MultiBoxPosition__init(message_memory);
}

void moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__MultiBoxPosition_fini_function(void * message_memory)
{
  moveit_interfaces__msg__MultiBoxPosition__fini(message_memory);
}

size_t moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__size_function__MultiBoxPosition__colors(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__get_const_function__MultiBoxPosition__colors(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__get_function__MultiBoxPosition__colors(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__fetch_function__MultiBoxPosition__colors(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__get_const_function__MultiBoxPosition__colors(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__assign_function__MultiBoxPosition__colors(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__get_function__MultiBoxPosition__colors(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__resize_function__MultiBoxPosition__colors(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__size_function__MultiBoxPosition__positions(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__get_const_function__MultiBoxPosition__positions(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__get_function__MultiBoxPosition__positions(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__fetch_function__MultiBoxPosition__positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__get_const_function__MultiBoxPosition__positions(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__assign_function__MultiBoxPosition__positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__get_function__MultiBoxPosition__positions(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__resize_function__MultiBoxPosition__positions(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__MultiBoxPosition_message_member_array[2] = {
  {
    "colors",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_interfaces__msg__MultiBoxPosition, colors),  // bytes offset in struct
    NULL,  // default value
    moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__size_function__MultiBoxPosition__colors,  // size() function pointer
    moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__get_const_function__MultiBoxPosition__colors,  // get_const(index) function pointer
    moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__get_function__MultiBoxPosition__colors,  // get(index) function pointer
    moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__fetch_function__MultiBoxPosition__colors,  // fetch(index, &value) function pointer
    moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__assign_function__MultiBoxPosition__colors,  // assign(index, value) function pointer
    moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__resize_function__MultiBoxPosition__colors  // resize(index) function pointer
  },
  {
    "positions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_interfaces__msg__MultiBoxPosition, positions),  // bytes offset in struct
    NULL,  // default value
    moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__size_function__MultiBoxPosition__positions,  // size() function pointer
    moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__get_const_function__MultiBoxPosition__positions,  // get_const(index) function pointer
    moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__get_function__MultiBoxPosition__positions,  // get(index) function pointer
    moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__fetch_function__MultiBoxPosition__positions,  // fetch(index, &value) function pointer
    moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__assign_function__MultiBoxPosition__positions,  // assign(index, value) function pointer
    moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__resize_function__MultiBoxPosition__positions  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__MultiBoxPosition_message_members = {
  "moveit_interfaces__msg",  // message namespace
  "MultiBoxPosition",  // message name
  2,  // number of fields
  sizeof(moveit_interfaces__msg__MultiBoxPosition),
  moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__MultiBoxPosition_message_member_array,  // message members
  moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__MultiBoxPosition_init_function,  // function to initialize message memory (memory has to be allocated)
  moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__MultiBoxPosition_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__MultiBoxPosition_message_type_support_handle = {
  0,
  &moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__MultiBoxPosition_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_moveit_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_interfaces, msg, MultiBoxPosition)() {
  moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__MultiBoxPosition_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__MultiBoxPosition_message_type_support_handle.typesupport_identifier) {
    moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__MultiBoxPosition_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &moveit_interfaces__msg__MultiBoxPosition__rosidl_typesupport_introspection_c__MultiBoxPosition_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
