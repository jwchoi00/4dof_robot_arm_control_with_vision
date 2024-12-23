// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from moveit_interfaces:msg/DetectionArray.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_INTERFACES__MSG__DETAIL__DETECTION_ARRAY__BUILDER_HPP_
#define MOVEIT_INTERFACES__MSG__DETAIL__DETECTION_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "moveit_interfaces/msg/detail/detection_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace moveit_interfaces
{

namespace msg
{

namespace builder
{

class Init_DetectionArray_detections
{
public:
  Init_DetectionArray_detections()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::moveit_interfaces::msg::DetectionArray detections(::moveit_interfaces::msg::DetectionArray::_detections_type arg)
  {
    msg_.detections = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_interfaces::msg::DetectionArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_interfaces::msg::DetectionArray>()
{
  return moveit_interfaces::msg::builder::Init_DetectionArray_detections();
}

}  // namespace moveit_interfaces

#endif  // MOVEIT_INTERFACES__MSG__DETAIL__DETECTION_ARRAY__BUILDER_HPP_
