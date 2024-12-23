// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from moveit_interfaces:msg/Detection.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_INTERFACES__MSG__DETAIL__DETECTION__BUILDER_HPP_
#define MOVEIT_INTERFACES__MSG__DETAIL__DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "moveit_interfaces/msg/detail/detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace moveit_interfaces
{

namespace msg
{

namespace builder
{

class Init_Detection_class_id
{
public:
  explicit Init_Detection_class_id(::moveit_interfaces::msg::Detection & msg)
  : msg_(msg)
  {}
  ::moveit_interfaces::msg::Detection class_id(::moveit_interfaces::msg::Detection::_class_id_type arg)
  {
    msg_.class_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_interfaces::msg::Detection msg_;
};

class Init_Detection_confidence
{
public:
  explicit Init_Detection_confidence(::moveit_interfaces::msg::Detection & msg)
  : msg_(msg)
  {}
  Init_Detection_class_id confidence(::moveit_interfaces::msg::Detection::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_Detection_class_id(msg_);
  }

private:
  ::moveit_interfaces::msg::Detection msg_;
};

class Init_Detection_center_y
{
public:
  explicit Init_Detection_center_y(::moveit_interfaces::msg::Detection & msg)
  : msg_(msg)
  {}
  Init_Detection_confidence center_y(::moveit_interfaces::msg::Detection::_center_y_type arg)
  {
    msg_.center_y = std::move(arg);
    return Init_Detection_confidence(msg_);
  }

private:
  ::moveit_interfaces::msg::Detection msg_;
};

class Init_Detection_center_x
{
public:
  explicit Init_Detection_center_x(::moveit_interfaces::msg::Detection & msg)
  : msg_(msg)
  {}
  Init_Detection_center_y center_x(::moveit_interfaces::msg::Detection::_center_x_type arg)
  {
    msg_.center_x = std::move(arg);
    return Init_Detection_center_y(msg_);
  }

private:
  ::moveit_interfaces::msg::Detection msg_;
};

class Init_Detection_y2
{
public:
  explicit Init_Detection_y2(::moveit_interfaces::msg::Detection & msg)
  : msg_(msg)
  {}
  Init_Detection_center_x y2(::moveit_interfaces::msg::Detection::_y2_type arg)
  {
    msg_.y2 = std::move(arg);
    return Init_Detection_center_x(msg_);
  }

private:
  ::moveit_interfaces::msg::Detection msg_;
};

class Init_Detection_x2
{
public:
  explicit Init_Detection_x2(::moveit_interfaces::msg::Detection & msg)
  : msg_(msg)
  {}
  Init_Detection_y2 x2(::moveit_interfaces::msg::Detection::_x2_type arg)
  {
    msg_.x2 = std::move(arg);
    return Init_Detection_y2(msg_);
  }

private:
  ::moveit_interfaces::msg::Detection msg_;
};

class Init_Detection_y1
{
public:
  explicit Init_Detection_y1(::moveit_interfaces::msg::Detection & msg)
  : msg_(msg)
  {}
  Init_Detection_x2 y1(::moveit_interfaces::msg::Detection::_y1_type arg)
  {
    msg_.y1 = std::move(arg);
    return Init_Detection_x2(msg_);
  }

private:
  ::moveit_interfaces::msg::Detection msg_;
};

class Init_Detection_x1
{
public:
  Init_Detection_x1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Detection_y1 x1(::moveit_interfaces::msg::Detection::_x1_type arg)
  {
    msg_.x1 = std::move(arg);
    return Init_Detection_y1(msg_);
  }

private:
  ::moveit_interfaces::msg::Detection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_interfaces::msg::Detection>()
{
  return moveit_interfaces::msg::builder::Init_Detection_x1();
}

}  // namespace moveit_interfaces

#endif  // MOVEIT_INTERFACES__MSG__DETAIL__DETECTION__BUILDER_HPP_
