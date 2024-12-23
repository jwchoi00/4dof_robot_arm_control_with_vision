// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from moveit_interfaces:action/Conveyor.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_INTERFACES__ACTION__DETAIL__CONVEYOR__BUILDER_HPP_
#define MOVEIT_INTERFACES__ACTION__DETAIL__CONVEYOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "moveit_interfaces/action/detail/conveyor__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace moveit_interfaces
{

namespace action
{

namespace builder
{

class Init_Conveyor_Goal_blue_box_count
{
public:
  explicit Init_Conveyor_Goal_blue_box_count(::moveit_interfaces::action::Conveyor_Goal & msg)
  : msg_(msg)
  {}
  ::moveit_interfaces::action::Conveyor_Goal blue_box_count(::moveit_interfaces::action::Conveyor_Goal::_blue_box_count_type arg)
  {
    msg_.blue_box_count = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_interfaces::action::Conveyor_Goal msg_;
};

class Init_Conveyor_Goal_red_box_count
{
public:
  Init_Conveyor_Goal_red_box_count()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Conveyor_Goal_blue_box_count red_box_count(::moveit_interfaces::action::Conveyor_Goal::_red_box_count_type arg)
  {
    msg_.red_box_count = std::move(arg);
    return Init_Conveyor_Goal_blue_box_count(msg_);
  }

private:
  ::moveit_interfaces::action::Conveyor_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_interfaces::action::Conveyor_Goal>()
{
  return moveit_interfaces::action::builder::Init_Conveyor_Goal_red_box_count();
}

}  // namespace moveit_interfaces


namespace moveit_interfaces
{

namespace action
{

namespace builder
{

class Init_Conveyor_Result_message
{
public:
  explicit Init_Conveyor_Result_message(::moveit_interfaces::action::Conveyor_Result & msg)
  : msg_(msg)
  {}
  ::moveit_interfaces::action::Conveyor_Result message(::moveit_interfaces::action::Conveyor_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_interfaces::action::Conveyor_Result msg_;
};

class Init_Conveyor_Result_success
{
public:
  Init_Conveyor_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Conveyor_Result_message success(::moveit_interfaces::action::Conveyor_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Conveyor_Result_message(msg_);
  }

private:
  ::moveit_interfaces::action::Conveyor_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_interfaces::action::Conveyor_Result>()
{
  return moveit_interfaces::action::builder::Init_Conveyor_Result_success();
}

}  // namespace moveit_interfaces


namespace moveit_interfaces
{

namespace action
{

namespace builder
{

class Init_Conveyor_Feedback_blue_boxes_moved
{
public:
  explicit Init_Conveyor_Feedback_blue_boxes_moved(::moveit_interfaces::action::Conveyor_Feedback & msg)
  : msg_(msg)
  {}
  ::moveit_interfaces::action::Conveyor_Feedback blue_boxes_moved(::moveit_interfaces::action::Conveyor_Feedback::_blue_boxes_moved_type arg)
  {
    msg_.blue_boxes_moved = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_interfaces::action::Conveyor_Feedback msg_;
};

class Init_Conveyor_Feedback_red_boxes_moved
{
public:
  Init_Conveyor_Feedback_red_boxes_moved()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Conveyor_Feedback_blue_boxes_moved red_boxes_moved(::moveit_interfaces::action::Conveyor_Feedback::_red_boxes_moved_type arg)
  {
    msg_.red_boxes_moved = std::move(arg);
    return Init_Conveyor_Feedback_blue_boxes_moved(msg_);
  }

private:
  ::moveit_interfaces::action::Conveyor_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_interfaces::action::Conveyor_Feedback>()
{
  return moveit_interfaces::action::builder::Init_Conveyor_Feedback_red_boxes_moved();
}

}  // namespace moveit_interfaces


namespace moveit_interfaces
{

namespace action
{

namespace builder
{

class Init_Conveyor_SendGoal_Request_goal
{
public:
  explicit Init_Conveyor_SendGoal_Request_goal(::moveit_interfaces::action::Conveyor_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::moveit_interfaces::action::Conveyor_SendGoal_Request goal(::moveit_interfaces::action::Conveyor_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_interfaces::action::Conveyor_SendGoal_Request msg_;
};

class Init_Conveyor_SendGoal_Request_goal_id
{
public:
  Init_Conveyor_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Conveyor_SendGoal_Request_goal goal_id(::moveit_interfaces::action::Conveyor_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Conveyor_SendGoal_Request_goal(msg_);
  }

private:
  ::moveit_interfaces::action::Conveyor_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_interfaces::action::Conveyor_SendGoal_Request>()
{
  return moveit_interfaces::action::builder::Init_Conveyor_SendGoal_Request_goal_id();
}

}  // namespace moveit_interfaces


namespace moveit_interfaces
{

namespace action
{

namespace builder
{

class Init_Conveyor_SendGoal_Response_stamp
{
public:
  explicit Init_Conveyor_SendGoal_Response_stamp(::moveit_interfaces::action::Conveyor_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::moveit_interfaces::action::Conveyor_SendGoal_Response stamp(::moveit_interfaces::action::Conveyor_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_interfaces::action::Conveyor_SendGoal_Response msg_;
};

class Init_Conveyor_SendGoal_Response_accepted
{
public:
  Init_Conveyor_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Conveyor_SendGoal_Response_stamp accepted(::moveit_interfaces::action::Conveyor_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Conveyor_SendGoal_Response_stamp(msg_);
  }

private:
  ::moveit_interfaces::action::Conveyor_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_interfaces::action::Conveyor_SendGoal_Response>()
{
  return moveit_interfaces::action::builder::Init_Conveyor_SendGoal_Response_accepted();
}

}  // namespace moveit_interfaces


namespace moveit_interfaces
{

namespace action
{

namespace builder
{

class Init_Conveyor_GetResult_Request_goal_id
{
public:
  Init_Conveyor_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::moveit_interfaces::action::Conveyor_GetResult_Request goal_id(::moveit_interfaces::action::Conveyor_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_interfaces::action::Conveyor_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_interfaces::action::Conveyor_GetResult_Request>()
{
  return moveit_interfaces::action::builder::Init_Conveyor_GetResult_Request_goal_id();
}

}  // namespace moveit_interfaces


namespace moveit_interfaces
{

namespace action
{

namespace builder
{

class Init_Conveyor_GetResult_Response_result
{
public:
  explicit Init_Conveyor_GetResult_Response_result(::moveit_interfaces::action::Conveyor_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::moveit_interfaces::action::Conveyor_GetResult_Response result(::moveit_interfaces::action::Conveyor_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_interfaces::action::Conveyor_GetResult_Response msg_;
};

class Init_Conveyor_GetResult_Response_status
{
public:
  Init_Conveyor_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Conveyor_GetResult_Response_result status(::moveit_interfaces::action::Conveyor_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Conveyor_GetResult_Response_result(msg_);
  }

private:
  ::moveit_interfaces::action::Conveyor_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_interfaces::action::Conveyor_GetResult_Response>()
{
  return moveit_interfaces::action::builder::Init_Conveyor_GetResult_Response_status();
}

}  // namespace moveit_interfaces


namespace moveit_interfaces
{

namespace action
{

namespace builder
{

class Init_Conveyor_FeedbackMessage_feedback
{
public:
  explicit Init_Conveyor_FeedbackMessage_feedback(::moveit_interfaces::action::Conveyor_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::moveit_interfaces::action::Conveyor_FeedbackMessage feedback(::moveit_interfaces::action::Conveyor_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::moveit_interfaces::action::Conveyor_FeedbackMessage msg_;
};

class Init_Conveyor_FeedbackMessage_goal_id
{
public:
  Init_Conveyor_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Conveyor_FeedbackMessage_feedback goal_id(::moveit_interfaces::action::Conveyor_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Conveyor_FeedbackMessage_feedback(msg_);
  }

private:
  ::moveit_interfaces::action::Conveyor_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::moveit_interfaces::action::Conveyor_FeedbackMessage>()
{
  return moveit_interfaces::action::builder::Init_Conveyor_FeedbackMessage_goal_id();
}

}  // namespace moveit_interfaces

#endif  // MOVEIT_INTERFACES__ACTION__DETAIL__CONVEYOR__BUILDER_HPP_
