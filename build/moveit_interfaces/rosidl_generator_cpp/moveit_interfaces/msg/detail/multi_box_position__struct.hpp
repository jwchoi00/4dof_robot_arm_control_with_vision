// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from moveit_interfaces:msg/MultiBoxPosition.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_INTERFACES__MSG__DETAIL__MULTI_BOX_POSITION__STRUCT_HPP_
#define MOVEIT_INTERFACES__MSG__DETAIL__MULTI_BOX_POSITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'positions'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__moveit_interfaces__msg__MultiBoxPosition __attribute__((deprecated))
#else
# define DEPRECATED__moveit_interfaces__msg__MultiBoxPosition __declspec(deprecated)
#endif

namespace moveit_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MultiBoxPosition_
{
  using Type = MultiBoxPosition_<ContainerAllocator>;

  explicit MultiBoxPosition_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit MultiBoxPosition_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _colors_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _colors_type colors;
  using _positions_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _positions_type positions;

  // setters for named parameter idiom
  Type & set__colors(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->colors = _arg;
    return *this;
  }
  Type & set__positions(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->positions = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    moveit_interfaces::msg::MultiBoxPosition_<ContainerAllocator> *;
  using ConstRawPtr =
    const moveit_interfaces::msg::MultiBoxPosition_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<moveit_interfaces::msg::MultiBoxPosition_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<moveit_interfaces::msg::MultiBoxPosition_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::msg::MultiBoxPosition_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::msg::MultiBoxPosition_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::msg::MultiBoxPosition_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::msg::MultiBoxPosition_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<moveit_interfaces::msg::MultiBoxPosition_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<moveit_interfaces::msg::MultiBoxPosition_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__moveit_interfaces__msg__MultiBoxPosition
    std::shared_ptr<moveit_interfaces::msg::MultiBoxPosition_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__moveit_interfaces__msg__MultiBoxPosition
    std::shared_ptr<moveit_interfaces::msg::MultiBoxPosition_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MultiBoxPosition_ & other) const
  {
    if (this->colors != other.colors) {
      return false;
    }
    if (this->positions != other.positions) {
      return false;
    }
    return true;
  }
  bool operator!=(const MultiBoxPosition_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MultiBoxPosition_

// alias to use template instance with default allocator
using MultiBoxPosition =
  moveit_interfaces::msg::MultiBoxPosition_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace moveit_interfaces

#endif  // MOVEIT_INTERFACES__MSG__DETAIL__MULTI_BOX_POSITION__STRUCT_HPP_
