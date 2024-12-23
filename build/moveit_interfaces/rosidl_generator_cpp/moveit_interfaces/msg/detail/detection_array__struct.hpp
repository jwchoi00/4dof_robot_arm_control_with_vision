// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from moveit_interfaces:msg/DetectionArray.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_INTERFACES__MSG__DETAIL__DETECTION_ARRAY__STRUCT_HPP_
#define MOVEIT_INTERFACES__MSG__DETAIL__DETECTION_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'detections'
#include "moveit_interfaces/msg/detail/detection__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__moveit_interfaces__msg__DetectionArray __attribute__((deprecated))
#else
# define DEPRECATED__moveit_interfaces__msg__DetectionArray __declspec(deprecated)
#endif

namespace moveit_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DetectionArray_
{
  using Type = DetectionArray_<ContainerAllocator>;

  explicit DetectionArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit DetectionArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _detections_type =
    std::vector<moveit_interfaces::msg::Detection_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<moveit_interfaces::msg::Detection_<ContainerAllocator>>>;
  _detections_type detections;

  // setters for named parameter idiom
  Type & set__detections(
    const std::vector<moveit_interfaces::msg::Detection_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<moveit_interfaces::msg::Detection_<ContainerAllocator>>> & _arg)
  {
    this->detections = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    moveit_interfaces::msg::DetectionArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const moveit_interfaces::msg::DetectionArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<moveit_interfaces::msg::DetectionArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<moveit_interfaces::msg::DetectionArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::msg::DetectionArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::msg::DetectionArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::msg::DetectionArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::msg::DetectionArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<moveit_interfaces::msg::DetectionArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<moveit_interfaces::msg::DetectionArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__moveit_interfaces__msg__DetectionArray
    std::shared_ptr<moveit_interfaces::msg::DetectionArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__moveit_interfaces__msg__DetectionArray
    std::shared_ptr<moveit_interfaces::msg::DetectionArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectionArray_ & other) const
  {
    if (this->detections != other.detections) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectionArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectionArray_

// alias to use template instance with default allocator
using DetectionArray =
  moveit_interfaces::msg::DetectionArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace moveit_interfaces

#endif  // MOVEIT_INTERFACES__MSG__DETAIL__DETECTION_ARRAY__STRUCT_HPP_
