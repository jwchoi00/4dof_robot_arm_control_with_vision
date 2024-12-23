// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from moveit_interfaces:srv/BoxPosition.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "moveit_interfaces/srv/detail/box_position__rosidl_typesupport_introspection_c.h"
#include "moveit_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "moveit_interfaces/srv/detail/box_position__functions.h"
#include "moveit_interfaces/srv/detail/box_position__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void moveit_interfaces__srv__BoxPosition_Request__rosidl_typesupport_introspection_c__BoxPosition_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  moveit_interfaces__srv__BoxPosition_Request__init(message_memory);
}

void moveit_interfaces__srv__BoxPosition_Request__rosidl_typesupport_introspection_c__BoxPosition_Request_fini_function(void * message_memory)
{
  moveit_interfaces__srv__BoxPosition_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember moveit_interfaces__srv__BoxPosition_Request__rosidl_typesupport_introspection_c__BoxPosition_Request_message_member_array[4] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_interfaces__srv__BoxPosition_Request, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_interfaces__srv__BoxPosition_Request, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_interfaces__srv__BoxPosition_Request, z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target_color",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_interfaces__srv__BoxPosition_Request, target_color),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers moveit_interfaces__srv__BoxPosition_Request__rosidl_typesupport_introspection_c__BoxPosition_Request_message_members = {
  "moveit_interfaces__srv",  // message namespace
  "BoxPosition_Request",  // message name
  4,  // number of fields
  sizeof(moveit_interfaces__srv__BoxPosition_Request),
  moveit_interfaces__srv__BoxPosition_Request__rosidl_typesupport_introspection_c__BoxPosition_Request_message_member_array,  // message members
  moveit_interfaces__srv__BoxPosition_Request__rosidl_typesupport_introspection_c__BoxPosition_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  moveit_interfaces__srv__BoxPosition_Request__rosidl_typesupport_introspection_c__BoxPosition_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t moveit_interfaces__srv__BoxPosition_Request__rosidl_typesupport_introspection_c__BoxPosition_Request_message_type_support_handle = {
  0,
  &moveit_interfaces__srv__BoxPosition_Request__rosidl_typesupport_introspection_c__BoxPosition_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_moveit_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_interfaces, srv, BoxPosition_Request)() {
  if (!moveit_interfaces__srv__BoxPosition_Request__rosidl_typesupport_introspection_c__BoxPosition_Request_message_type_support_handle.typesupport_identifier) {
    moveit_interfaces__srv__BoxPosition_Request__rosidl_typesupport_introspection_c__BoxPosition_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &moveit_interfaces__srv__BoxPosition_Request__rosidl_typesupport_introspection_c__BoxPosition_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "moveit_interfaces/srv/detail/box_position__rosidl_typesupport_introspection_c.h"
// already included above
// #include "moveit_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "moveit_interfaces/srv/detail/box_position__functions.h"
// already included above
// #include "moveit_interfaces/srv/detail/box_position__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void moveit_interfaces__srv__BoxPosition_Response__rosidl_typesupport_introspection_c__BoxPosition_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  moveit_interfaces__srv__BoxPosition_Response__init(message_memory);
}

void moveit_interfaces__srv__BoxPosition_Response__rosidl_typesupport_introspection_c__BoxPosition_Response_fini_function(void * message_memory)
{
  moveit_interfaces__srv__BoxPosition_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember moveit_interfaces__srv__BoxPosition_Response__rosidl_typesupport_introspection_c__BoxPosition_Response_message_member_array[4] = {
  {
    "is_within_range",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_interfaces__srv__BoxPosition_Response, is_within_range),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_interfaces__srv__BoxPosition_Response, goal_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_interfaces__srv__BoxPosition_Response, goal_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal_z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(moveit_interfaces__srv__BoxPosition_Response, goal_z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers moveit_interfaces__srv__BoxPosition_Response__rosidl_typesupport_introspection_c__BoxPosition_Response_message_members = {
  "moveit_interfaces__srv",  // message namespace
  "BoxPosition_Response",  // message name
  4,  // number of fields
  sizeof(moveit_interfaces__srv__BoxPosition_Response),
  moveit_interfaces__srv__BoxPosition_Response__rosidl_typesupport_introspection_c__BoxPosition_Response_message_member_array,  // message members
  moveit_interfaces__srv__BoxPosition_Response__rosidl_typesupport_introspection_c__BoxPosition_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  moveit_interfaces__srv__BoxPosition_Response__rosidl_typesupport_introspection_c__BoxPosition_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t moveit_interfaces__srv__BoxPosition_Response__rosidl_typesupport_introspection_c__BoxPosition_Response_message_type_support_handle = {
  0,
  &moveit_interfaces__srv__BoxPosition_Response__rosidl_typesupport_introspection_c__BoxPosition_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_moveit_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_interfaces, srv, BoxPosition_Response)() {
  if (!moveit_interfaces__srv__BoxPosition_Response__rosidl_typesupport_introspection_c__BoxPosition_Response_message_type_support_handle.typesupport_identifier) {
    moveit_interfaces__srv__BoxPosition_Response__rosidl_typesupport_introspection_c__BoxPosition_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &moveit_interfaces__srv__BoxPosition_Response__rosidl_typesupport_introspection_c__BoxPosition_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "moveit_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "moveit_interfaces/srv/detail/box_position__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers moveit_interfaces__srv__detail__box_position__rosidl_typesupport_introspection_c__BoxPosition_service_members = {
  "moveit_interfaces__srv",  // service namespace
  "BoxPosition",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // moveit_interfaces__srv__detail__box_position__rosidl_typesupport_introspection_c__BoxPosition_Request_message_type_support_handle,
  NULL  // response message
  // moveit_interfaces__srv__detail__box_position__rosidl_typesupport_introspection_c__BoxPosition_Response_message_type_support_handle
};

static rosidl_service_type_support_t moveit_interfaces__srv__detail__box_position__rosidl_typesupport_introspection_c__BoxPosition_service_type_support_handle = {
  0,
  &moveit_interfaces__srv__detail__box_position__rosidl_typesupport_introspection_c__BoxPosition_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_interfaces, srv, BoxPosition_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_interfaces, srv, BoxPosition_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_moveit_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_interfaces, srv, BoxPosition)() {
  if (!moveit_interfaces__srv__detail__box_position__rosidl_typesupport_introspection_c__BoxPosition_service_type_support_handle.typesupport_identifier) {
    moveit_interfaces__srv__detail__box_position__rosidl_typesupport_introspection_c__BoxPosition_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)moveit_interfaces__srv__detail__box_position__rosidl_typesupport_introspection_c__BoxPosition_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_interfaces, srv, BoxPosition_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, moveit_interfaces, srv, BoxPosition_Response)()->data;
  }

  return &moveit_interfaces__srv__detail__box_position__rosidl_typesupport_introspection_c__BoxPosition_service_type_support_handle;
}
