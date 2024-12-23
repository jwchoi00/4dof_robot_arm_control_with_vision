// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from moveit_interfaces:msg/Detection.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_INTERFACES__MSG__DETAIL__DETECTION__STRUCT_HPP_
#define MOVEIT_INTERFACES__MSG__DETAIL__DETECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__moveit_interfaces__msg__Detection __attribute__((deprecated))
#else
# define DEPRECATED__moveit_interfaces__msg__Detection __declspec(deprecated)
#endif

namespace moveit_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Detection_
{
  using Type = Detection_<ContainerAllocator>;

  explicit Detection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x1 = 0.0f;
      this->y1 = 0.0f;
      this->x2 = 0.0f;
      this->y2 = 0.0f;
      this->center_x = 0.0f;
      this->center_y = 0.0f;
      this->confidence = 0.0f;
      this->class_id = 0l;
    }
  }

  explicit Detection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x1 = 0.0f;
      this->y1 = 0.0f;
      this->x2 = 0.0f;
      this->y2 = 0.0f;
      this->center_x = 0.0f;
      this->center_y = 0.0f;
      this->confidence = 0.0f;
      this->class_id = 0l;
    }
  }

  // field types and members
  using _x1_type =
    float;
  _x1_type x1;
  using _y1_type =
    float;
  _y1_type y1;
  using _x2_type =
    float;
  _x2_type x2;
  using _y2_type =
    float;
  _y2_type y2;
  using _center_x_type =
    float;
  _center_x_type center_x;
  using _center_y_type =
    float;
  _center_y_type center_y;
  using _confidence_type =
    float;
  _confidence_type confidence;
  using _class_id_type =
    int32_t;
  _class_id_type class_id;

  // setters for named parameter idiom
  Type & set__x1(
    const float & _arg)
  {
    this->x1 = _arg;
    return *this;
  }
  Type & set__y1(
    const float & _arg)
  {
    this->y1 = _arg;
    return *this;
  }
  Type & set__x2(
    const float & _arg)
  {
    this->x2 = _arg;
    return *this;
  }
  Type & set__y2(
    const float & _arg)
  {
    this->y2 = _arg;
    return *this;
  }
  Type & set__center_x(
    const float & _arg)
  {
    this->center_x = _arg;
    return *this;
  }
  Type & set__center_y(
    const float & _arg)
  {
    this->center_y = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__class_id(
    const int32_t & _arg)
  {
    this->class_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    moveit_interfaces::msg::Detection_<ContainerAllocator> *;
  using ConstRawPtr =
    const moveit_interfaces::msg::Detection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<moveit_interfaces::msg::Detection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<moveit_interfaces::msg::Detection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::msg::Detection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::msg::Detection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::msg::Detection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::msg::Detection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<moveit_interfaces::msg::Detection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<moveit_interfaces::msg::Detection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__moveit_interfaces__msg__Detection
    std::shared_ptr<moveit_interfaces::msg::Detection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__moveit_interfaces__msg__Detection
    std::shared_ptr<moveit_interfaces::msg::Detection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Detection_ & other) const
  {
    if (this->x1 != other.x1) {
      return false;
    }
    if (this->y1 != other.y1) {
      return false;
    }
    if (this->x2 != other.x2) {
      return false;
    }
    if (this->y2 != other.y2) {
      return false;
    }
    if (this->center_x != other.center_x) {
      return false;
    }
    if (this->center_y != other.center_y) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->class_id != other.class_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const Detection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Detection_

// alias to use template instance with default allocator
using Detection =
  moveit_interfaces::msg::Detection_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace moveit_interfaces

#endif  // MOVEIT_INTERFACES__MSG__DETAIL__DETECTION__STRUCT_HPP_
