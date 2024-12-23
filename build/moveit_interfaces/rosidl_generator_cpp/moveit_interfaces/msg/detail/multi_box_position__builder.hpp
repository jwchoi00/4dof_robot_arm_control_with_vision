// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from moveit_interfaces:msg/MultiBoxPosition.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_INTERFACES__MSG__DETAIL__MULTI_BOX_POSITION__BUILDER_HPP_
#define MOVEIT_INTERFACES__MSG__DETAIL__MULTI_BOX_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "moveit_interfaces/msg/detail/multi_box_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace moveit_interfaces
{

namespace msg
{

namespace builder
{

class Init_MultiBoxPosition_positions
{
public:
  explicit Init_MultiBoxPosition_positions(::moveit_interfaces::msg::MultiBoxPosition & msg)
  : msg_(msg)
  {}
  ::moveit_interfaces::msg::MultiBoxPosition positions(::moveit_interfaces::msg::MultiBoxPosition::_positions_type arg)
  {
    msg_.positions = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_interfaces::msg::MultiBoxPosition msg_;
};

class Init_MultiBoxPosition_colors
{
public:
  Init_MultiBoxPosition_colors()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MultiBoxPosition_positions colors(::moveit_interfaces::msg::MultiBoxPosition::_colors_type arg)
  {
    msg_.colors = std::move(arg);
    return Init_MultiBoxPosition_positions(msg_);
  }

private:
  ::moveit_interfaces::msg::MultiBoxPosition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_interfaces::msg::MultiBoxPosition>()
{
  return moveit_interfaces::msg::builder::Init_MultiBoxPosition_colors();
}

}  // namespace moveit_interfaces

#endif  // MOVEIT_INTERFACES__MSG__DETAIL__MULTI_BOX_POSITION__BUILDER_HPP_
