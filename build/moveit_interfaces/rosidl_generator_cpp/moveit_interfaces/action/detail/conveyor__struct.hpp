// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from moveit_interfaces:action/Conveyor.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_INTERFACES__ACTION__DETAIL__CONVEYOR__STRUCT_HPP_
#define MOVEIT_INTERFACES__ACTION__DETAIL__CONVEYOR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__moveit_interfaces__action__Conveyor_Goal __attribute__((deprecated))
#else
# define DEPRECATED__moveit_interfaces__action__Conveyor_Goal __declspec(deprecated)
#endif

namespace moveit_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Conveyor_Goal_
{
  using Type = Conveyor_Goal_<ContainerAllocator>;

  explicit Conveyor_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->red_box_count = 0l;
      this->blue_box_count = 0l;
      this->purple_box_count = 0l;
    }
  }

  explicit Conveyor_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->red_box_count = 0l;
      this->blue_box_count = 0l;
      this->purple_box_count = 0l;
    }
  }

  // field types and members
  using _red_box_count_type =
    int32_t;
  _red_box_count_type red_box_count;
  using _blue_box_count_type =
    int32_t;
  _blue_box_count_type blue_box_count;
  using _purple_box_count_type =
    int32_t;
  _purple_box_count_type purple_box_count;

  // setters for named parameter idiom
  Type & set__red_box_count(
    const int32_t & _arg)
  {
    this->red_box_count = _arg;
    return *this;
  }
  Type & set__blue_box_count(
    const int32_t & _arg)
  {
    this->blue_box_count = _arg;
    return *this;
  }
  Type & set__purple_box_count(
    const int32_t & _arg)
  {
    this->purple_box_count = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    moveit_interfaces::action::Conveyor_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const moveit_interfaces::action::Conveyor_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<moveit_interfaces::action::Conveyor_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<moveit_interfaces::action::Conveyor_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::action::Conveyor_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::action::Conveyor_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::action::Conveyor_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::action::Conveyor_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<moveit_interfaces::action::Conveyor_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<moveit_interfaces::action::Conveyor_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__moveit_interfaces__action__Conveyor_Goal
    std::shared_ptr<moveit_interfaces::action::Conveyor_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__moveit_interfaces__action__Conveyor_Goal
    std::shared_ptr<moveit_interfaces::action::Conveyor_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Conveyor_Goal_ & other) const
  {
    if (this->red_box_count != other.red_box_count) {
      return false;
    }
    if (this->blue_box_count != other.blue_box_count) {
      return false;
    }
    if (this->purple_box_count != other.purple_box_count) {
      return false;
    }
    return true;
  }
  bool operator!=(const Conveyor_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Conveyor_Goal_

// alias to use template instance with default allocator
using Conveyor_Goal =
  moveit_interfaces::action::Conveyor_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace moveit_interfaces


#ifndef _WIN32
# define DEPRECATED__moveit_interfaces__action__Conveyor_Result __attribute__((deprecated))
#else
# define DEPRECATED__moveit_interfaces__action__Conveyor_Result __declspec(deprecated)
#endif

namespace moveit_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Conveyor_Result_
{
  using Type = Conveyor_Result_<ContainerAllocator>;

  explicit Conveyor_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit Conveyor_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    moveit_interfaces::action::Conveyor_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const moveit_interfaces::action::Conveyor_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<moveit_interfaces::action::Conveyor_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<moveit_interfaces::action::Conveyor_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::action::Conveyor_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::action::Conveyor_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::action::Conveyor_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::action::Conveyor_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<moveit_interfaces::action::Conveyor_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<moveit_interfaces::action::Conveyor_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__moveit_interfaces__action__Conveyor_Result
    std::shared_ptr<moveit_interfaces::action::Conveyor_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__moveit_interfaces__action__Conveyor_Result
    std::shared_ptr<moveit_interfaces::action::Conveyor_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Conveyor_Result_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const Conveyor_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Conveyor_Result_

// alias to use template instance with default allocator
using Conveyor_Result =
  moveit_interfaces::action::Conveyor_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace moveit_interfaces


#ifndef _WIN32
# define DEPRECATED__moveit_interfaces__action__Conveyor_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__moveit_interfaces__action__Conveyor_Feedback __declspec(deprecated)
#endif

namespace moveit_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Conveyor_Feedback_
{
  using Type = Conveyor_Feedback_<ContainerAllocator>;

  explicit Conveyor_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->red_boxes_moved = 0l;
      this->blue_boxes_moved = 0l;
      this->purple_box_moved = 0l;
    }
  }

  explicit Conveyor_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->red_boxes_moved = 0l;
      this->blue_boxes_moved = 0l;
      this->purple_box_moved = 0l;
    }
  }

  // field types and members
  using _red_boxes_moved_type =
    int32_t;
  _red_boxes_moved_type red_boxes_moved;
  using _blue_boxes_moved_type =
    int32_t;
  _blue_boxes_moved_type blue_boxes_moved;
  using _purple_box_moved_type =
    int32_t;
  _purple_box_moved_type purple_box_moved;

  // setters for named parameter idiom
  Type & set__red_boxes_moved(
    const int32_t & _arg)
  {
    this->red_boxes_moved = _arg;
    return *this;
  }
  Type & set__blue_boxes_moved(
    const int32_t & _arg)
  {
    this->blue_boxes_moved = _arg;
    return *this;
  }
  Type & set__purple_box_moved(
    const int32_t & _arg)
  {
    this->purple_box_moved = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    moveit_interfaces::action::Conveyor_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const moveit_interfaces::action::Conveyor_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<moveit_interfaces::action::Conveyor_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<moveit_interfaces::action::Conveyor_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::action::Conveyor_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::action::Conveyor_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::action::Conveyor_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::action::Conveyor_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<moveit_interfaces::action::Conveyor_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<moveit_interfaces::action::Conveyor_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__moveit_interfaces__action__Conveyor_Feedback
    std::shared_ptr<moveit_interfaces::action::Conveyor_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__moveit_interfaces__action__Conveyor_Feedback
    std::shared_ptr<moveit_interfaces::action::Conveyor_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Conveyor_Feedback_ & other) const
  {
    if (this->red_boxes_moved != other.red_boxes_moved) {
      return false;
    }
    if (this->blue_boxes_moved != other.blue_boxes_moved) {
      return false;
    }
    if (this->purple_box_moved != other.purple_box_moved) {
      return false;
    }
    return true;
  }
  bool operator!=(const Conveyor_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Conveyor_Feedback_

// alias to use template instance with default allocator
using Conveyor_Feedback =
  moveit_interfaces::action::Conveyor_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace moveit_interfaces


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "moveit_interfaces/action/detail/conveyor__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__moveit_interfaces__action__Conveyor_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__moveit_interfaces__action__Conveyor_SendGoal_Request __declspec(deprecated)
#endif

namespace moveit_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Conveyor_SendGoal_Request_
{
  using Type = Conveyor_SendGoal_Request_<ContainerAllocator>;

  explicit Conveyor_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit Conveyor_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    moveit_interfaces::action::Conveyor_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const moveit_interfaces::action::Conveyor_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    moveit_interfaces::action::Conveyor_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const moveit_interfaces::action::Conveyor_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<moveit_interfaces::action::Conveyor_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<moveit_interfaces::action::Conveyor_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::action::Conveyor_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::action::Conveyor_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::action::Conveyor_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::action::Conveyor_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<moveit_interfaces::action::Conveyor_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<moveit_interfaces::action::Conveyor_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__moveit_interfaces__action__Conveyor_SendGoal_Request
    std::shared_ptr<moveit_interfaces::action::Conveyor_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__moveit_interfaces__action__Conveyor_SendGoal_Request
    std::shared_ptr<moveit_interfaces::action::Conveyor_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Conveyor_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const Conveyor_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Conveyor_SendGoal_Request_

// alias to use template instance with default allocator
using Conveyor_SendGoal_Request =
  moveit_interfaces::action::Conveyor_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace moveit_interfaces


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__moveit_interfaces__action__Conveyor_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__moveit_interfaces__action__Conveyor_SendGoal_Response __declspec(deprecated)
#endif

namespace moveit_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Conveyor_SendGoal_Response_
{
  using Type = Conveyor_SendGoal_Response_<ContainerAllocator>;

  explicit Conveyor_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit Conveyor_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    moveit_interfaces::action::Conveyor_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const moveit_interfaces::action::Conveyor_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<moveit_interfaces::action::Conveyor_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<moveit_interfaces::action::Conveyor_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::action::Conveyor_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::action::Conveyor_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::action::Conveyor_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::action::Conveyor_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<moveit_interfaces::action::Conveyor_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<moveit_interfaces::action::Conveyor_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__moveit_interfaces__action__Conveyor_SendGoal_Response
    std::shared_ptr<moveit_interfaces::action::Conveyor_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__moveit_interfaces__action__Conveyor_SendGoal_Response
    std::shared_ptr<moveit_interfaces::action::Conveyor_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Conveyor_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const Conveyor_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Conveyor_SendGoal_Response_

// alias to use template instance with default allocator
using Conveyor_SendGoal_Response =
  moveit_interfaces::action::Conveyor_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace moveit_interfaces

namespace moveit_interfaces
{

namespace action
{

struct Conveyor_SendGoal
{
  using Request = moveit_interfaces::action::Conveyor_SendGoal_Request;
  using Response = moveit_interfaces::action::Conveyor_SendGoal_Response;
};

}  // namespace action

}  // namespace moveit_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__moveit_interfaces__action__Conveyor_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__moveit_interfaces__action__Conveyor_GetResult_Request __declspec(deprecated)
#endif

namespace moveit_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Conveyor_GetResult_Request_
{
  using Type = Conveyor_GetResult_Request_<ContainerAllocator>;

  explicit Conveyor_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit Conveyor_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    moveit_interfaces::action::Conveyor_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const moveit_interfaces::action::Conveyor_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<moveit_interfaces::action::Conveyor_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<moveit_interfaces::action::Conveyor_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::action::Conveyor_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::action::Conveyor_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::action::Conveyor_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::action::Conveyor_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<moveit_interfaces::action::Conveyor_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<moveit_interfaces::action::Conveyor_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__moveit_interfaces__action__Conveyor_GetResult_Request
    std::shared_ptr<moveit_interfaces::action::Conveyor_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__moveit_interfaces__action__Conveyor_GetResult_Request
    std::shared_ptr<moveit_interfaces::action::Conveyor_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Conveyor_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const Conveyor_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Conveyor_GetResult_Request_

// alias to use template instance with default allocator
using Conveyor_GetResult_Request =
  moveit_interfaces::action::Conveyor_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace moveit_interfaces


// Include directives for member types
// Member 'result'
// already included above
// #include "moveit_interfaces/action/detail/conveyor__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__moveit_interfaces__action__Conveyor_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__moveit_interfaces__action__Conveyor_GetResult_Response __declspec(deprecated)
#endif

namespace moveit_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Conveyor_GetResult_Response_
{
  using Type = Conveyor_GetResult_Response_<ContainerAllocator>;

  explicit Conveyor_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit Conveyor_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    moveit_interfaces::action::Conveyor_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const moveit_interfaces::action::Conveyor_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    moveit_interfaces::action::Conveyor_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const moveit_interfaces::action::Conveyor_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<moveit_interfaces::action::Conveyor_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<moveit_interfaces::action::Conveyor_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::action::Conveyor_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::action::Conveyor_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::action::Conveyor_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::action::Conveyor_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<moveit_interfaces::action::Conveyor_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<moveit_interfaces::action::Conveyor_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__moveit_interfaces__action__Conveyor_GetResult_Response
    std::shared_ptr<moveit_interfaces::action::Conveyor_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__moveit_interfaces__action__Conveyor_GetResult_Response
    std::shared_ptr<moveit_interfaces::action::Conveyor_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Conveyor_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const Conveyor_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Conveyor_GetResult_Response_

// alias to use template instance with default allocator
using Conveyor_GetResult_Response =
  moveit_interfaces::action::Conveyor_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace moveit_interfaces

namespace moveit_interfaces
{

namespace action
{

struct Conveyor_GetResult
{
  using Request = moveit_interfaces::action::Conveyor_GetResult_Request;
  using Response = moveit_interfaces::action::Conveyor_GetResult_Response;
};

}  // namespace action

}  // namespace moveit_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "moveit_interfaces/action/detail/conveyor__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__moveit_interfaces__action__Conveyor_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__moveit_interfaces__action__Conveyor_FeedbackMessage __declspec(deprecated)
#endif

namespace moveit_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Conveyor_FeedbackMessage_
{
  using Type = Conveyor_FeedbackMessage_<ContainerAllocator>;

  explicit Conveyor_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit Conveyor_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    moveit_interfaces::action::Conveyor_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const moveit_interfaces::action::Conveyor_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    moveit_interfaces::action::Conveyor_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const moveit_interfaces::action::Conveyor_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<moveit_interfaces::action::Conveyor_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<moveit_interfaces::action::Conveyor_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::action::Conveyor_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::action::Conveyor_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      moveit_interfaces::action::Conveyor_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<moveit_interfaces::action::Conveyor_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<moveit_interfaces::action::Conveyor_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<moveit_interfaces::action::Conveyor_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__moveit_interfaces__action__Conveyor_FeedbackMessage
    std::shared_ptr<moveit_interfaces::action::Conveyor_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__moveit_interfaces__action__Conveyor_FeedbackMessage
    std::shared_ptr<moveit_interfaces::action::Conveyor_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Conveyor_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const Conveyor_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Conveyor_FeedbackMessage_

// alias to use template instance with default allocator
using Conveyor_FeedbackMessage =
  moveit_interfaces::action::Conveyor_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace moveit_interfaces

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace moveit_interfaces
{

namespace action
{

struct Conveyor
{
  /// The goal message defined in the action definition.
  using Goal = moveit_interfaces::action::Conveyor_Goal;
  /// The result message defined in the action definition.
  using Result = moveit_interfaces::action::Conveyor_Result;
  /// The feedback message defined in the action definition.
  using Feedback = moveit_interfaces::action::Conveyor_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = moveit_interfaces::action::Conveyor_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = moveit_interfaces::action::Conveyor_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = moveit_interfaces::action::Conveyor_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct Conveyor Conveyor;

}  // namespace action

}  // namespace moveit_interfaces

#endif  // MOVEIT_INTERFACES__ACTION__DETAIL__CONVEYOR__STRUCT_HPP_
