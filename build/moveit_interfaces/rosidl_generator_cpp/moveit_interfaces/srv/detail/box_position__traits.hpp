// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from moveit_interfaces:srv/BoxPosition.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_INTERFACES__SRV__DETAIL__BOX_POSITION__TRAITS_HPP_
#define MOVEIT_INTERFACES__SRV__DETAIL__BOX_POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "moveit_interfaces/srv/detail/box_position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace moveit_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const BoxPosition_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << ", ";
  }

  // member: target_color
  {
    out << "target_color: ";
    rosidl_generator_traits::value_to_yaml(msg.target_color, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BoxPosition_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }

  // member: target_color
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_color: ";
    rosidl_generator_traits::value_to_yaml(msg.target_color, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BoxPosition_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace moveit_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use moveit_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const moveit_interfaces::srv::BoxPosition_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  moveit_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use moveit_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const moveit_interfaces::srv::BoxPosition_Request & msg)
{
  return moveit_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<moveit_interfaces::srv::BoxPosition_Request>()
{
  return "moveit_interfaces::srv::BoxPosition_Request";
}

template<>
inline const char * name<moveit_interfaces::srv::BoxPosition_Request>()
{
  return "moveit_interfaces/srv/BoxPosition_Request";
}

template<>
struct has_fixed_size<moveit_interfaces::srv::BoxPosition_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<moveit_interfaces::srv::BoxPosition_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<moveit_interfaces::srv::BoxPosition_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace moveit_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const BoxPosition_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: is_within_range
  {
    out << "is_within_range: ";
    rosidl_generator_traits::value_to_yaml(msg.is_within_range, out);
    out << ", ";
  }

  // member: goal_x
  {
    out << "goal_x: ";
    rosidl_generator_traits::value_to_yaml(msg.goal_x, out);
    out << ", ";
  }

  // member: goal_y
  {
    out << "goal_y: ";
    rosidl_generator_traits::value_to_yaml(msg.goal_y, out);
    out << ", ";
  }

  // member: goal_z
  {
    out << "goal_z: ";
    rosidl_generator_traits::value_to_yaml(msg.goal_z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BoxPosition_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: is_within_range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_within_range: ";
    rosidl_generator_traits::value_to_yaml(msg.is_within_range, out);
    out << "\n";
  }

  // member: goal_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_x: ";
    rosidl_generator_traits::value_to_yaml(msg.goal_x, out);
    out << "\n";
  }

  // member: goal_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_y: ";
    rosidl_generator_traits::value_to_yaml(msg.goal_y, out);
    out << "\n";
  }

  // member: goal_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_z: ";
    rosidl_generator_traits::value_to_yaml(msg.goal_z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BoxPosition_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace moveit_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use moveit_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const moveit_interfaces::srv::BoxPosition_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  moveit_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use moveit_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const moveit_interfaces::srv::BoxPosition_Response & msg)
{
  return moveit_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<moveit_interfaces::srv::BoxPosition_Response>()
{
  return "moveit_interfaces::srv::BoxPosition_Response";
}

template<>
inline const char * name<moveit_interfaces::srv::BoxPosition_Response>()
{
  return "moveit_interfaces/srv/BoxPosition_Response";
}

template<>
struct has_fixed_size<moveit_interfaces::srv::BoxPosition_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<moveit_interfaces::srv::BoxPosition_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<moveit_interfaces::srv::BoxPosition_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<moveit_interfaces::srv::BoxPosition>()
{
  return "moveit_interfaces::srv::BoxPosition";
}

template<>
inline const char * name<moveit_interfaces::srv::BoxPosition>()
{
  return "moveit_interfaces/srv/BoxPosition";
}

template<>
struct has_fixed_size<moveit_interfaces::srv::BoxPosition>
  : std::integral_constant<
    bool,
    has_fixed_size<moveit_interfaces::srv::BoxPosition_Request>::value &&
    has_fixed_size<moveit_interfaces::srv::BoxPosition_Response>::value
  >
{
};

template<>
struct has_bounded_size<moveit_interfaces::srv::BoxPosition>
  : std::integral_constant<
    bool,
    has_bounded_size<moveit_interfaces::srv::BoxPosition_Request>::value &&
    has_bounded_size<moveit_interfaces::srv::BoxPosition_Response>::value
  >
{
};

template<>
struct is_service<moveit_interfaces::srv::BoxPosition>
  : std::true_type
{
};

template<>
struct is_service_request<moveit_interfaces::srv::BoxPosition_Request>
  : std::true_type
{
};

template<>
struct is_service_response<moveit_interfaces::srv::BoxPosition_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MOVEIT_INTERFACES__SRV__DETAIL__BOX_POSITION__TRAITS_HPP_
