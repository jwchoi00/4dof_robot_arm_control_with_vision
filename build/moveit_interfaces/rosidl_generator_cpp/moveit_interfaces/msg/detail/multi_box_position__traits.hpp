// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from moveit_interfaces:msg/MultiBoxPosition.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_INTERFACES__MSG__DETAIL__MULTI_BOX_POSITION__TRAITS_HPP_
#define MOVEIT_INTERFACES__MSG__DETAIL__MULTI_BOX_POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "moveit_interfaces/msg/detail/multi_box_position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'positions'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace moveit_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MultiBoxPosition & msg,
  std::ostream & out)
{
  out << "{";
  // member: colors
  {
    if (msg.colors.size() == 0) {
      out << "colors: []";
    } else {
      out << "colors: [";
      size_t pending_items = msg.colors.size();
      for (auto item : msg.colors) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: positions
  {
    if (msg.positions.size() == 0) {
      out << "positions: []";
    } else {
      out << "positions: [";
      size_t pending_items = msg.positions.size();
      for (auto item : msg.positions) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MultiBoxPosition & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: colors
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.colors.size() == 0) {
      out << "colors: []\n";
    } else {
      out << "colors:\n";
      for (auto item : msg.colors) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.positions.size() == 0) {
      out << "positions: []\n";
    } else {
      out << "positions:\n";
      for (auto item : msg.positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MultiBoxPosition & msg, bool use_flow_style = false)
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
  const moveit_interfaces::msg::MultiBoxPosition & msg,
  std::ostream & out, size_t indentation = 0)
{
  moveit_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use moveit_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const moveit_interfaces::msg::MultiBoxPosition & msg)
{
  return moveit_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<moveit_interfaces::msg::MultiBoxPosition>()
{
  return "moveit_interfaces::msg::MultiBoxPosition";
}

template<>
inline const char * name<moveit_interfaces::msg::MultiBoxPosition>()
{
  return "moveit_interfaces/msg/MultiBoxPosition";
}

template<>
struct has_fixed_size<moveit_interfaces::msg::MultiBoxPosition>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<moveit_interfaces::msg::MultiBoxPosition>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<moveit_interfaces::msg::MultiBoxPosition>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MOVEIT_INTERFACES__MSG__DETAIL__MULTI_BOX_POSITION__TRAITS_HPP_
