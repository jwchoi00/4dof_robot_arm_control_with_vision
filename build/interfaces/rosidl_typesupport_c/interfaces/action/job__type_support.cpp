// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from interfaces:action/Job.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "interfaces/action/detail/job__struct.h"
#include "interfaces/action/detail/job__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Job_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Job_Goal_type_support_ids_t;

static const _Job_Goal_type_support_ids_t _Job_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Job_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Job_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Job_Goal_type_support_symbol_names_t _Job_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces, action, Job_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces, action, Job_Goal)),
  }
};

typedef struct _Job_Goal_type_support_data_t
{
  void * data[2];
} _Job_Goal_type_support_data_t;

static _Job_Goal_type_support_data_t _Job_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Job_Goal_message_typesupport_map = {
  2,
  "interfaces",
  &_Job_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_Job_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_Job_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Job_Goal_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Job_Goal_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, interfaces, action, Job_Goal)() {
  return &::interfaces::action::rosidl_typesupport_c::Job_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces/action/detail/job__struct.h"
// already included above
// #include "interfaces/action/detail/job__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Job_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Job_Result_type_support_ids_t;

static const _Job_Result_type_support_ids_t _Job_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Job_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Job_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Job_Result_type_support_symbol_names_t _Job_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces, action, Job_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces, action, Job_Result)),
  }
};

typedef struct _Job_Result_type_support_data_t
{
  void * data[2];
} _Job_Result_type_support_data_t;

static _Job_Result_type_support_data_t _Job_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Job_Result_message_typesupport_map = {
  2,
  "interfaces",
  &_Job_Result_message_typesupport_ids.typesupport_identifier[0],
  &_Job_Result_message_typesupport_symbol_names.symbol_name[0],
  &_Job_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Job_Result_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Job_Result_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, interfaces, action, Job_Result)() {
  return &::interfaces::action::rosidl_typesupport_c::Job_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces/action/detail/job__struct.h"
// already included above
// #include "interfaces/action/detail/job__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Job_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Job_Feedback_type_support_ids_t;

static const _Job_Feedback_type_support_ids_t _Job_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Job_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Job_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Job_Feedback_type_support_symbol_names_t _Job_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces, action, Job_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces, action, Job_Feedback)),
  }
};

typedef struct _Job_Feedback_type_support_data_t
{
  void * data[2];
} _Job_Feedback_type_support_data_t;

static _Job_Feedback_type_support_data_t _Job_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Job_Feedback_message_typesupport_map = {
  2,
  "interfaces",
  &_Job_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_Job_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_Job_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Job_Feedback_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Job_Feedback_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, interfaces, action, Job_Feedback)() {
  return &::interfaces::action::rosidl_typesupport_c::Job_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces/action/detail/job__struct.h"
// already included above
// #include "interfaces/action/detail/job__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Job_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Job_SendGoal_Request_type_support_ids_t;

static const _Job_SendGoal_Request_type_support_ids_t _Job_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Job_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Job_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Job_SendGoal_Request_type_support_symbol_names_t _Job_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces, action, Job_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces, action, Job_SendGoal_Request)),
  }
};

typedef struct _Job_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _Job_SendGoal_Request_type_support_data_t;

static _Job_SendGoal_Request_type_support_data_t _Job_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Job_SendGoal_Request_message_typesupport_map = {
  2,
  "interfaces",
  &_Job_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Job_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Job_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Job_SendGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Job_SendGoal_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, interfaces, action, Job_SendGoal_Request)() {
  return &::interfaces::action::rosidl_typesupport_c::Job_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces/action/detail/job__struct.h"
// already included above
// #include "interfaces/action/detail/job__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Job_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Job_SendGoal_Response_type_support_ids_t;

static const _Job_SendGoal_Response_type_support_ids_t _Job_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Job_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Job_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Job_SendGoal_Response_type_support_symbol_names_t _Job_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces, action, Job_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces, action, Job_SendGoal_Response)),
  }
};

typedef struct _Job_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _Job_SendGoal_Response_type_support_data_t;

static _Job_SendGoal_Response_type_support_data_t _Job_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Job_SendGoal_Response_message_typesupport_map = {
  2,
  "interfaces",
  &_Job_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Job_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Job_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Job_SendGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Job_SendGoal_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, interfaces, action, Job_SendGoal_Response)() {
  return &::interfaces::action::rosidl_typesupport_c::Job_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "interfaces/action/detail/job__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Job_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Job_SendGoal_type_support_ids_t;

static const _Job_SendGoal_type_support_ids_t _Job_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Job_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Job_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Job_SendGoal_type_support_symbol_names_t _Job_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces, action, Job_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces, action, Job_SendGoal)),
  }
};

typedef struct _Job_SendGoal_type_support_data_t
{
  void * data[2];
} _Job_SendGoal_type_support_data_t;

static _Job_SendGoal_type_support_data_t _Job_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Job_SendGoal_service_typesupport_map = {
  2,
  "interfaces",
  &_Job_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_Job_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_Job_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Job_SendGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Job_SendGoal_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, interfaces, action, Job_SendGoal)() {
  return &::interfaces::action::rosidl_typesupport_c::Job_SendGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces/action/detail/job__struct.h"
// already included above
// #include "interfaces/action/detail/job__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Job_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Job_GetResult_Request_type_support_ids_t;

static const _Job_GetResult_Request_type_support_ids_t _Job_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Job_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Job_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Job_GetResult_Request_type_support_symbol_names_t _Job_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces, action, Job_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces, action, Job_GetResult_Request)),
  }
};

typedef struct _Job_GetResult_Request_type_support_data_t
{
  void * data[2];
} _Job_GetResult_Request_type_support_data_t;

static _Job_GetResult_Request_type_support_data_t _Job_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Job_GetResult_Request_message_typesupport_map = {
  2,
  "interfaces",
  &_Job_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Job_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Job_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Job_GetResult_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Job_GetResult_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, interfaces, action, Job_GetResult_Request)() {
  return &::interfaces::action::rosidl_typesupport_c::Job_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces/action/detail/job__struct.h"
// already included above
// #include "interfaces/action/detail/job__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Job_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Job_GetResult_Response_type_support_ids_t;

static const _Job_GetResult_Response_type_support_ids_t _Job_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Job_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Job_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Job_GetResult_Response_type_support_symbol_names_t _Job_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces, action, Job_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces, action, Job_GetResult_Response)),
  }
};

typedef struct _Job_GetResult_Response_type_support_data_t
{
  void * data[2];
} _Job_GetResult_Response_type_support_data_t;

static _Job_GetResult_Response_type_support_data_t _Job_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Job_GetResult_Response_message_typesupport_map = {
  2,
  "interfaces",
  &_Job_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Job_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Job_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Job_GetResult_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Job_GetResult_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, interfaces, action, Job_GetResult_Response)() {
  return &::interfaces::action::rosidl_typesupport_c::Job_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "interfaces/action/detail/job__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Job_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Job_GetResult_type_support_ids_t;

static const _Job_GetResult_type_support_ids_t _Job_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Job_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Job_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Job_GetResult_type_support_symbol_names_t _Job_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces, action, Job_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces, action, Job_GetResult)),
  }
};

typedef struct _Job_GetResult_type_support_data_t
{
  void * data[2];
} _Job_GetResult_type_support_data_t;

static _Job_GetResult_type_support_data_t _Job_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Job_GetResult_service_typesupport_map = {
  2,
  "interfaces",
  &_Job_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_Job_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_Job_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Job_GetResult_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Job_GetResult_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, interfaces, action, Job_GetResult)() {
  return &::interfaces::action::rosidl_typesupport_c::Job_GetResult_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "interfaces/action/detail/job__struct.h"
// already included above
// #include "interfaces/action/detail/job__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Job_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Job_FeedbackMessage_type_support_ids_t;

static const _Job_FeedbackMessage_type_support_ids_t _Job_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Job_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Job_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Job_FeedbackMessage_type_support_symbol_names_t _Job_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interfaces, action, Job_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces, action, Job_FeedbackMessage)),
  }
};

typedef struct _Job_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _Job_FeedbackMessage_type_support_data_t;

static _Job_FeedbackMessage_type_support_data_t _Job_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Job_FeedbackMessage_message_typesupport_map = {
  2,
  "interfaces",
  &_Job_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_Job_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_Job_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Job_FeedbackMessage_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Job_FeedbackMessage_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, interfaces, action, Job_FeedbackMessage)() {
  return &::interfaces::action::rosidl_typesupport_c::Job_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "action_msgs/msg/goal_status_array.h"
#include "action_msgs/srv/cancel_goal.h"
#include "interfaces/action/job.h"
// already included above
// #include "interfaces/action/detail/job__type_support.h"

static rosidl_action_type_support_t _interfaces__action__Job__typesupport_c;

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
  rosidl_typesupport_c, interfaces, action, Job)()
{
  // Thread-safe by always writing the same values to the static struct
  _interfaces__action__Job__typesupport_c.goal_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, interfaces, action, Job_SendGoal)();
  _interfaces__action__Job__typesupport_c.result_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, interfaces, action, Job_GetResult)();
  _interfaces__action__Job__typesupport_c.cancel_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, srv, CancelGoal)();
  _interfaces__action__Job__typesupport_c.feedback_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, interfaces, action, Job_FeedbackMessage)();
  _interfaces__action__Job__typesupport_c.status_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, msg, GoalStatusArray)();

  return &_interfaces__action__Job__typesupport_c;
}

#ifdef __cplusplus
}
#endif
