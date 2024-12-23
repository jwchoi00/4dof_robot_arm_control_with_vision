// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from moveit_interfaces:srv/BoxPosition.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_INTERFACES__SRV__DETAIL__BOX_POSITION__BUILDER_HPP_
#define MOVEIT_INTERFACES__SRV__DETAIL__BOX_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "moveit_interfaces/srv/detail/box_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace moveit_interfaces
{

namespace srv
{

namespace builder
{

class Init_BoxPosition_Request_target_color
{
public:
  explicit Init_BoxPosition_Request_target_color(::moveit_interfaces::srv::BoxPosition_Request & msg)
  : msg_(msg)
  {}
  ::moveit_interfaces::srv::BoxPosition_Request target_color(::moveit_interfaces::srv::BoxPosition_Request::_target_color_type arg)
  {
    msg_.target_color = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_interfaces::srv::BoxPosition_Request msg_;
};

class Init_BoxPosition_Request_z
{
public:
  explicit Init_BoxPosition_Request_z(::moveit_interfaces::srv::BoxPosition_Request & msg)
  : msg_(msg)
  {}
  Init_BoxPosition_Request_target_color z(::moveit_interfaces::srv::BoxPosition_Request::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_BoxPosition_Request_target_color(msg_);
  }

private:
  ::moveit_interfaces::srv::BoxPosition_Request msg_;
};

class Init_BoxPosition_Request_y
{
public:
  explicit Init_BoxPosition_Request_y(::moveit_interfaces::srv::BoxPosition_Request & msg)
  : msg_(msg)
  {}
  Init_BoxPosition_Request_z y(::moveit_interfaces::srv::BoxPosition_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_BoxPosition_Request_z(msg_);
  }

private:
  ::moveit_interfaces::srv::BoxPosition_Request msg_;
};

class Init_BoxPosition_Request_x
{
public:
  Init_BoxPosition_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoxPosition_Request_y x(::moveit_interfaces::srv::BoxPosition_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_BoxPosition_Request_y(msg_);
  }

private:
  ::moveit_interfaces::srv::BoxPosition_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_interfaces::srv::BoxPosition_Request>()
{
  return moveit_interfaces::srv::builder::Init_BoxPosition_Request_x();
}

}  // namespace moveit_interfaces


namespace moveit_interfaces
{

namespace srv
{

namespace builder
{

class Init_BoxPosition_Response_goal_z
{
public:
  explicit Init_BoxPosition_Response_goal_z(::moveit_interfaces::srv::BoxPosition_Response & msg)
  : msg_(msg)
  {}
  ::moveit_interfaces::srv::BoxPosition_Response goal_z(::moveit_interfaces::srv::BoxPosition_Response::_goal_z_type arg)
  {
    msg_.goal_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_interfaces::srv::BoxPosition_Response msg_;
};

class Init_BoxPosition_Response_goal_y
{
public:
  explicit Init_BoxPosition_Response_goal_y(::moveit_interfaces::srv::BoxPosition_Response & msg)
  : msg_(msg)
  {}
  Init_BoxPosition_Response_goal_z goal_y(::moveit_interfaces::srv::BoxPosition_Response::_goal_y_type arg)
  {
    msg_.goal_y = std::move(arg);
    return Init_BoxPosition_Response_goal_z(msg_);
  }

private:
  ::moveit_interfaces::srv::BoxPosition_Response msg_;
};

class Init_BoxPosition_Response_goal_x
{
public:
  explicit Init_BoxPosition_Response_goal_x(::moveit_interfaces::srv::BoxPosition_Response & msg)
  : msg_(msg)
  {}
  Init_BoxPosition_Response_goal_y goal_x(::moveit_interfaces::srv::BoxPosition_Response::_goal_x_type arg)
  {
    msg_.goal_x = std::move(arg);
    return Init_BoxPosition_Response_goal_y(msg_);
  }

private:
  ::moveit_interfaces::srv::BoxPosition_Response msg_;
};

class Init_BoxPosition_Response_is_within_range
{
public:
  Init_BoxPosition_Response_is_within_range()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BoxPosition_Response_goal_x is_within_range(::moveit_interfaces::srv::BoxPosition_Response::_is_within_range_type arg)
  {
    msg_.is_within_range = std::move(arg);
    return Init_BoxPosition_Response_goal_x(msg_);
  }

private:
  ::moveit_interfaces::srv::BoxPosition_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_interfaces::srv::BoxPosition_Response>()
{
  return moveit_interfaces::srv::builder::Init_BoxPosition_Response_is_within_range();
}

}  // namespace moveit_interfaces

#endif  // MOVEIT_INTERFACES__SRV__DETAIL__BOX_POSITION__BUILDER_HPP_
