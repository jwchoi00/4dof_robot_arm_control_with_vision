// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:action/Conveyor.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__ACTION__DETAIL__CONVEYOR__TRAITS_HPP_
#define INTERFACES__ACTION__DETAIL__CONVEYOR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interfaces/action/detail/conveyor__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Conveyor_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: red_box_count
  {
    out << "red_box_count: ";
    rosidl_generator_traits::value_to_yaml(msg.red_box_count, out);
    out << ", ";
  }

  // member: blue_box_count
  {
    out << "blue_box_count: ";
    rosidl_generator_traits::value_to_yaml(msg.blue_box_count, out);
    out << ", ";
  }

  // member: purple_box_count
  {
    out << "purple_box_count: ";
    rosidl_generator_traits::value_to_yaml(msg.purple_box_count, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Conveyor_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: red_box_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "red_box_count: ";
    rosidl_generator_traits::value_to_yaml(msg.red_box_count, out);
    out << "\n";
  }

  // member: blue_box_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "blue_box_count: ";
    rosidl_generator_traits::value_to_yaml(msg.blue_box_count, out);
    out << "\n";
  }

  // member: purple_box_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "purple_box_count: ";
    rosidl_generator_traits::value_to_yaml(msg.purple_box_count, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Conveyor_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::action::Conveyor_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::action::Conveyor_Goal & msg)
{
  return interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::action::Conveyor_Goal>()
{
  return "interfaces::action::Conveyor_Goal";
}

template<>
inline const char * name<interfaces::action::Conveyor_Goal>()
{
  return "interfaces/action/Conveyor_Goal";
}

template<>
struct has_fixed_size<interfaces::action::Conveyor_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::action::Conveyor_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::action::Conveyor_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Conveyor_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Conveyor_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Conveyor_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::action::Conveyor_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::action::Conveyor_Result & msg)
{
  return interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::action::Conveyor_Result>()
{
  return "interfaces::action::Conveyor_Result";
}

template<>
inline const char * name<interfaces::action::Conveyor_Result>()
{
  return "interfaces/action/Conveyor_Result";
}

template<>
struct has_fixed_size<interfaces::action::Conveyor_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<interfaces::action::Conveyor_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<interfaces::action::Conveyor_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Conveyor_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: red_boxes_moved
  {
    out << "red_boxes_moved: ";
    rosidl_generator_traits::value_to_yaml(msg.red_boxes_moved, out);
    out << ", ";
  }

  // member: blue_boxes_moved
  {
    out << "blue_boxes_moved: ";
    rosidl_generator_traits::value_to_yaml(msg.blue_boxes_moved, out);
    out << ", ";
  }

  // member: purple_box_moved
  {
    out << "purple_box_moved: ";
    rosidl_generator_traits::value_to_yaml(msg.purple_box_moved, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Conveyor_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: red_boxes_moved
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "red_boxes_moved: ";
    rosidl_generator_traits::value_to_yaml(msg.red_boxes_moved, out);
    out << "\n";
  }

  // member: blue_boxes_moved
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "blue_boxes_moved: ";
    rosidl_generator_traits::value_to_yaml(msg.blue_boxes_moved, out);
    out << "\n";
  }

  // member: purple_box_moved
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "purple_box_moved: ";
    rosidl_generator_traits::value_to_yaml(msg.purple_box_moved, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Conveyor_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::action::Conveyor_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::action::Conveyor_Feedback & msg)
{
  return interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::action::Conveyor_Feedback>()
{
  return "interfaces::action::Conveyor_Feedback";
}

template<>
inline const char * name<interfaces::action::Conveyor_Feedback>()
{
  return "interfaces/action/Conveyor_Feedback";
}

template<>
struct has_fixed_size<interfaces::action::Conveyor_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::action::Conveyor_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::action::Conveyor_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "interfaces/action/detail/conveyor__traits.hpp"

namespace interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Conveyor_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Conveyor_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Conveyor_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::action::Conveyor_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::action::Conveyor_SendGoal_Request & msg)
{
  return interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::action::Conveyor_SendGoal_Request>()
{
  return "interfaces::action::Conveyor_SendGoal_Request";
}

template<>
inline const char * name<interfaces::action::Conveyor_SendGoal_Request>()
{
  return "interfaces/action/Conveyor_SendGoal_Request";
}

template<>
struct has_fixed_size<interfaces::action::Conveyor_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<interfaces::action::Conveyor_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<interfaces::action::Conveyor_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<interfaces::action::Conveyor_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<interfaces::action::Conveyor_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Conveyor_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Conveyor_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Conveyor_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::action::Conveyor_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::action::Conveyor_SendGoal_Response & msg)
{
  return interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::action::Conveyor_SendGoal_Response>()
{
  return "interfaces::action::Conveyor_SendGoal_Response";
}

template<>
inline const char * name<interfaces::action::Conveyor_SendGoal_Response>()
{
  return "interfaces/action/Conveyor_SendGoal_Response";
}

template<>
struct has_fixed_size<interfaces::action::Conveyor_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<interfaces::action::Conveyor_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<interfaces::action::Conveyor_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::action::Conveyor_SendGoal>()
{
  return "interfaces::action::Conveyor_SendGoal";
}

template<>
inline const char * name<interfaces::action::Conveyor_SendGoal>()
{
  return "interfaces/action/Conveyor_SendGoal";
}

template<>
struct has_fixed_size<interfaces::action::Conveyor_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<interfaces::action::Conveyor_SendGoal_Request>::value &&
    has_fixed_size<interfaces::action::Conveyor_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<interfaces::action::Conveyor_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<interfaces::action::Conveyor_SendGoal_Request>::value &&
    has_bounded_size<interfaces::action::Conveyor_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<interfaces::action::Conveyor_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<interfaces::action::Conveyor_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interfaces::action::Conveyor_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Conveyor_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Conveyor_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Conveyor_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::action::Conveyor_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::action::Conveyor_GetResult_Request & msg)
{
  return interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::action::Conveyor_GetResult_Request>()
{
  return "interfaces::action::Conveyor_GetResult_Request";
}

template<>
inline const char * name<interfaces::action::Conveyor_GetResult_Request>()
{
  return "interfaces/action/Conveyor_GetResult_Request";
}

template<>
struct has_fixed_size<interfaces::action::Conveyor_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<interfaces::action::Conveyor_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<interfaces::action::Conveyor_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "interfaces/action/detail/conveyor__traits.hpp"

namespace interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Conveyor_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Conveyor_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Conveyor_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::action::Conveyor_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::action::Conveyor_GetResult_Response & msg)
{
  return interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::action::Conveyor_GetResult_Response>()
{
  return "interfaces::action::Conveyor_GetResult_Response";
}

template<>
inline const char * name<interfaces::action::Conveyor_GetResult_Response>()
{
  return "interfaces/action/Conveyor_GetResult_Response";
}

template<>
struct has_fixed_size<interfaces::action::Conveyor_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<interfaces::action::Conveyor_Result>::value> {};

template<>
struct has_bounded_size<interfaces::action::Conveyor_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<interfaces::action::Conveyor_Result>::value> {};

template<>
struct is_message<interfaces::action::Conveyor_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::action::Conveyor_GetResult>()
{
  return "interfaces::action::Conveyor_GetResult";
}

template<>
inline const char * name<interfaces::action::Conveyor_GetResult>()
{
  return "interfaces/action/Conveyor_GetResult";
}

template<>
struct has_fixed_size<interfaces::action::Conveyor_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<interfaces::action::Conveyor_GetResult_Request>::value &&
    has_fixed_size<interfaces::action::Conveyor_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<interfaces::action::Conveyor_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<interfaces::action::Conveyor_GetResult_Request>::value &&
    has_bounded_size<interfaces::action::Conveyor_GetResult_Response>::value
  >
{
};

template<>
struct is_service<interfaces::action::Conveyor_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<interfaces::action::Conveyor_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interfaces::action::Conveyor_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "interfaces/action/detail/conveyor__traits.hpp"

namespace interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Conveyor_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Conveyor_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Conveyor_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::action::Conveyor_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::action::Conveyor_FeedbackMessage & msg)
{
  return interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::action::Conveyor_FeedbackMessage>()
{
  return "interfaces::action::Conveyor_FeedbackMessage";
}

template<>
inline const char * name<interfaces::action::Conveyor_FeedbackMessage>()
{
  return "interfaces/action/Conveyor_FeedbackMessage";
}

template<>
struct has_fixed_size<interfaces::action::Conveyor_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<interfaces::action::Conveyor_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<interfaces::action::Conveyor_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<interfaces::action::Conveyor_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<interfaces::action::Conveyor_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<interfaces::action::Conveyor>
  : std::true_type
{
};

template<>
struct is_action_goal<interfaces::action::Conveyor_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<interfaces::action::Conveyor_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<interfaces::action::Conveyor_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // INTERFACES__ACTION__DETAIL__CONVEYOR__TRAITS_HPP_
