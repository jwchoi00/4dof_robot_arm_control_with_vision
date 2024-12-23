// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from moveit_interfaces:srv/BoxPosition.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_INTERFACES__SRV__DETAIL__BOX_POSITION__STRUCT_HPP_
#define MOVEIT_INTERFACES__SRV__DETAIL__BOX_POSITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__moveit_interfaces__srv__BoxPosition_Request __attribute__((deprecated))
#else
# define DEPRECATED__moveit_interfaces__srv__BoxPosition_Request __declspec(deprecated)
#endif

namespace moveit_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct BoxPosition_Request_
{
  using Type = BoxPosition_Request_<ContainerAllocator>;

  explicit BoxPosition_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->target_color = 0l;
    }
  }

  explicit BoxPosition_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->target_color = 0l;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _z_type =
    double;
  _z_type z;
  using _target_color_type =
    int32_t;
  _target_color_type target_color;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const double & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__target_color(
    const int32_t & _arg)
  {
    this->target_color = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    moveit_interfaces::srv::BoxPosition_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const moveit_interfaces::srv::BoxPosition_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<moveit_interfaces::srv::BoxPosition_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<moveit_interfaces::srv::BoxPosition_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::srv::BoxPosition_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::srv::BoxPosition_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::srv::BoxPosition_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::srv::BoxPosition_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<moveit_interfaces::srv::BoxPosition_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<moveit_interfaces::srv::BoxPosition_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__moveit_interfaces__srv__BoxPosition_Request
    std::shared_ptr<moveit_interfaces::srv::BoxPosition_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__moveit_interfaces__srv__BoxPosition_Request
    std::shared_ptr<moveit_interfaces::srv::BoxPosition_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BoxPosition_Request_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->target_color != other.target_color) {
      return false;
    }
    return true;
  }
  bool operator!=(const BoxPosition_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BoxPosition_Request_

// alias to use template instance with default allocator
using BoxPosition_Request =
  moveit_interfaces::srv::BoxPosition_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace moveit_interfaces


#ifndef _WIN32
# define DEPRECATED__moveit_interfaces__srv__BoxPosition_Response __attribute__((deprecated))
#else
# define DEPRECATED__moveit_interfaces__srv__BoxPosition_Response __declspec(deprecated)
#endif

namespace moveit_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct BoxPosition_Response_
{
  using Type = BoxPosition_Response_<ContainerAllocator>;

  explicit BoxPosition_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_within_range = false;
      this->goal_x = 0.0;
      this->goal_y = 0.0;
      this->goal_z = 0.0;
    }
  }

  explicit BoxPosition_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_within_range = false;
      this->goal_x = 0.0;
      this->goal_y = 0.0;
      this->goal_z = 0.0;
    }
  }

  // field types and members
  using _is_within_range_type =
    bool;
  _is_within_range_type is_within_range;
  using _goal_x_type =
    double;
  _goal_x_type goal_x;
  using _goal_y_type =
    double;
  _goal_y_type goal_y;
  using _goal_z_type =
    double;
  _goal_z_type goal_z;

  // setters for named parameter idiom
  Type & set__is_within_range(
    const bool & _arg)
  {
    this->is_within_range = _arg;
    return *this;
  }
  Type & set__goal_x(
    const double & _arg)
  {
    this->goal_x = _arg;
    return *this;
  }
  Type & set__goal_y(
    const double & _arg)
  {
    this->goal_y = _arg;
    return *this;
  }
  Type & set__goal_z(
    const double & _arg)
  {
    this->goal_z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    moveit_interfaces::srv::BoxPosition_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const moveit_interfaces::srv::BoxPosition_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<moveit_interfaces::srv::BoxPosition_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<moveit_interfaces::srv::BoxPosition_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::srv::BoxPosition_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::srv::BoxPosition_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::srv::BoxPosition_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::srv::BoxPosition_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<moveit_interfaces::srv::BoxPosition_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<moveit_interfaces::srv::BoxPosition_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__moveit_interfaces__srv__BoxPosition_Response
    std::shared_ptr<moveit_interfaces::srv::BoxPosition_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__moveit_interfaces__srv__BoxPosition_Response
    std::shared_ptr<moveit_interfaces::srv::BoxPosition_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BoxPosition_Response_ & other) const
  {
    if (this->is_within_range != other.is_within_range) {
      return false;
    }
    if (this->goal_x != other.goal_x) {
      return false;
    }
    if (this->goal_y != other.goal_y) {
      return false;
    }
    if (this->goal_z != other.goal_z) {
      return false;
    }
    return true;
  }
  bool operator!=(const BoxPosition_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BoxPosition_Response_

// alias to use template instance with default allocator
using BoxPosition_Response =
  moveit_interfaces::srv::BoxPosition_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace moveit_interfaces

namespace moveit_interfaces
{

namespace srv
{

struct BoxPosition
{
  using Request = moveit_interfaces::srv::BoxPosition_Request;
  using Response = moveit_interfaces::srv::BoxPosition_Response;
};

}  // namespace srv

}  // namespace moveit_interfaces

#endif  // MOVEIT_INTERFACES__SRV__DETAIL__BOX_POSITION__STRUCT_HPP_
