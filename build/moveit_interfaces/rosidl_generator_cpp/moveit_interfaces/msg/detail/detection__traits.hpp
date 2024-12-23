// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from moveit_interfaces:msg/Detection.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_INTERFACES__MSG__DETAIL__DETECTION__TRAITS_HPP_
#define MOVEIT_INTERFACES__MSG__DETAIL__DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "moveit_interfaces/msg/detail/detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace moveit_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Detection & msg,
  std::ostream & out)
{
  out << "{";
  // member: x1
  {
    out << "x1: ";
    rosidl_generator_traits::value_to_yaml(msg.x1, out);
    out << ", ";
  }

  // member: y1
  {
    out << "y1: ";
    rosidl_generator_traits::value_to_yaml(msg.y1, out);
    out << ", ";
  }

  // member: x2
  {
    out << "x2: ";
    rosidl_generator_traits::value_to_yaml(msg.x2, out);
    out << ", ";
  }

  // member: y2
  {
    out << "y2: ";
    rosidl_generator_traits::value_to_yaml(msg.y2, out);
    out << ", ";
  }

  // member: center_x
  {
    out << "center_x: ";
    rosidl_generator_traits::value_to_yaml(msg.center_x, out);
    out << ", ";
  }

  // member: center_y
  {
    out << "center_y: ";
    rosidl_generator_traits::value_to_yaml(msg.center_y, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: class_id
  {
    out << "class_id: ";
    rosidl_generator_traits::value_to_yaml(msg.class_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Detection & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x1: ";
    rosidl_generator_traits::value_to_yaml(msg.x1, out);
    out << "\n";
  }

  // member: y1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y1: ";
    rosidl_generator_traits::value_to_yaml(msg.y1, out);
    out << "\n";
  }

  // member: x2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x2: ";
    rosidl_generator_traits::value_to_yaml(msg.x2, out);
    out << "\n";
  }

  // member: y2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y2: ";
    rosidl_generator_traits::value_to_yaml(msg.y2, out);
    out << "\n";
  }

  // member: center_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_x: ";
    rosidl_generator_traits::value_to_yaml(msg.center_x, out);
    out << "\n";
  }

  // member: center_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_y: ";
    rosidl_generator_traits::value_to_yaml(msg.center_y, out);
    out << "\n";
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }

  // member: class_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "class_id: ";
    rosidl_generator_traits::value_to_yaml(msg.class_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Detection & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace moveit_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use moveit_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const moveit_interfaces::msg::Detection & msg,
  std::ostream & out, size_t indentation = 0)
{
  moveit_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use moveit_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const moveit_interfaces::msg::Detection & msg)
{
  return moveit_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<moveit_interfaces::msg::Detection>()
{
  return "moveit_interfaces::msg::Detection";
}

template<>
inline const char * name<moveit_interfaces::msg::Detection>()
{
  return "moveit_interfaces/msg/Detection";
}

template<>
struct has_fixed_size<moveit_interfaces::msg::Detection>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<moveit_interfaces::msg::Detection>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<moveit_interfaces::msg::Detection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MOVEIT_INTERFACES__MSG__DETAIL__DETECTION__TRAITS_HPP_
