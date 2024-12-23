// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:action/Conveyor.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__ACTION__DETAIL__CONVEYOR__BUILDER_HPP_
#define INTERFACES__ACTION__DETAIL__CONVEYOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/action/detail/conveyor__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Conveyor_Goal_purple_box_count
{
public:
  explicit Init_Conveyor_Goal_purple_box_count(::interfaces::action::Conveyor_Goal & msg)
  : msg_(msg)
  {}
  ::interfaces::action::Conveyor_Goal purple_box_count(::interfaces::action::Conveyor_Goal::_purple_box_count_type arg)
  {
    msg_.purple_box_count = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Conveyor_Goal msg_;
};

class Init_Conveyor_Goal_blue_box_count
{
public:
  explicit Init_Conveyor_Goal_blue_box_count(::interfaces::action::Conveyor_Goal & msg)
  : msg_(msg)
  {}
  Init_Conveyor_Goal_purple_box_count blue_box_count(::interfaces::action::Conveyor_Goal::_blue_box_count_type arg)
  {
    msg_.blue_box_count = std::move(arg);
    return Init_Conveyor_Goal_purple_box_count(msg_);
  }

private:
  ::interfaces::action::Conveyor_Goal msg_;
};

class Init_Conveyor_Goal_red_box_count
{
public:
  Init_Conveyor_Goal_red_box_count()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Conveyor_Goal_blue_box_count red_box_count(::interfaces::action::Conveyor_Goal::_red_box_count_type arg)
  {
    msg_.red_box_count = std::move(arg);
    return Init_Conveyor_Goal_blue_box_count(msg_);
  }

private:
  ::interfaces::action::Conveyor_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Conveyor_Goal>()
{
  return interfaces::action::builder::Init_Conveyor_Goal_red_box_count();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Conveyor_Result_message
{
public:
  explicit Init_Conveyor_Result_message(::interfaces::action::Conveyor_Result & msg)
  : msg_(msg)
  {}
  ::interfaces::action::Conveyor_Result message(::interfaces::action::Conveyor_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Conveyor_Result msg_;
};

class Init_Conveyor_Result_success
{
public:
  Init_Conveyor_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Conveyor_Result_message success(::interfaces::action::Conveyor_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Conveyor_Result_message(msg_);
  }

private:
  ::interfaces::action::Conveyor_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Conveyor_Result>()
{
  return interfaces::action::builder::Init_Conveyor_Result_success();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Conveyor_Feedback_purple_box_moved
{
public:
  explicit Init_Conveyor_Feedback_purple_box_moved(::interfaces::action::Conveyor_Feedback & msg)
  : msg_(msg)
  {}
  ::interfaces::action::Conveyor_Feedback purple_box_moved(::interfaces::action::Conveyor_Feedback::_purple_box_moved_type arg)
  {
    msg_.purple_box_moved = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Conveyor_Feedback msg_;
};

class Init_Conveyor_Feedback_blue_boxes_moved
{
public:
  explicit Init_Conveyor_Feedback_blue_boxes_moved(::interfaces::action::Conveyor_Feedback & msg)
  : msg_(msg)
  {}
  Init_Conveyor_Feedback_purple_box_moved blue_boxes_moved(::interfaces::action::Conveyor_Feedback::_blue_boxes_moved_type arg)
  {
    msg_.blue_boxes_moved = std::move(arg);
    return Init_Conveyor_Feedback_purple_box_moved(msg_);
  }

private:
  ::interfaces::action::Conveyor_Feedback msg_;
};

class Init_Conveyor_Feedback_red_boxes_moved
{
public:
  Init_Conveyor_Feedback_red_boxes_moved()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Conveyor_Feedback_blue_boxes_moved red_boxes_moved(::interfaces::action::Conveyor_Feedback::_red_boxes_moved_type arg)
  {
    msg_.red_boxes_moved = std::move(arg);
    return Init_Conveyor_Feedback_blue_boxes_moved(msg_);
  }

private:
  ::interfaces::action::Conveyor_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Conveyor_Feedback>()
{
  return interfaces::action::builder::Init_Conveyor_Feedback_red_boxes_moved();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Conveyor_SendGoal_Request_goal
{
public:
  explicit Init_Conveyor_SendGoal_Request_goal(::interfaces::action::Conveyor_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::interfaces::action::Conveyor_SendGoal_Request goal(::interfaces::action::Conveyor_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Conveyor_SendGoal_Request msg_;
};

class Init_Conveyor_SendGoal_Request_goal_id
{
public:
  Init_Conveyor_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Conveyor_SendGoal_Request_goal goal_id(::interfaces::action::Conveyor_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Conveyor_SendGoal_Request_goal(msg_);
  }

private:
  ::interfaces::action::Conveyor_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Conveyor_SendGoal_Request>()
{
  return interfaces::action::builder::Init_Conveyor_SendGoal_Request_goal_id();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Conveyor_SendGoal_Response_stamp
{
public:
  explicit Init_Conveyor_SendGoal_Response_stamp(::interfaces::action::Conveyor_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::interfaces::action::Conveyor_SendGoal_Response stamp(::interfaces::action::Conveyor_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Conveyor_SendGoal_Response msg_;
};

class Init_Conveyor_SendGoal_Response_accepted
{
public:
  Init_Conveyor_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Conveyor_SendGoal_Response_stamp accepted(::interfaces::action::Conveyor_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Conveyor_SendGoal_Response_stamp(msg_);
  }

private:
  ::interfaces::action::Conveyor_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Conveyor_SendGoal_Response>()
{
  return interfaces::action::builder::Init_Conveyor_SendGoal_Response_accepted();
}

}  // namespace interfaces


namespace interfaces
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
  ::interfaces::action::Conveyor_GetResult_Request goal_id(::interfaces::action::Conveyor_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Conveyor_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Conveyor_GetResult_Request>()
{
  return interfaces::action::builder::Init_Conveyor_GetResult_Request_goal_id();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Conveyor_GetResult_Response_result
{
public:
  explicit Init_Conveyor_GetResult_Response_result(::interfaces::action::Conveyor_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::interfaces::action::Conveyor_GetResult_Response result(::interfaces::action::Conveyor_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Conveyor_GetResult_Response msg_;
};

class Init_Conveyor_GetResult_Response_status
{
public:
  Init_Conveyor_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Conveyor_GetResult_Response_result status(::interfaces::action::Conveyor_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Conveyor_GetResult_Response_result(msg_);
  }

private:
  ::interfaces::action::Conveyor_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Conveyor_GetResult_Response>()
{
  return interfaces::action::builder::Init_Conveyor_GetResult_Response_status();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Conveyor_FeedbackMessage_feedback
{
public:
  explicit Init_Conveyor_FeedbackMessage_feedback(::interfaces::action::Conveyor_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::interfaces::action::Conveyor_FeedbackMessage feedback(::interfaces::action::Conveyor_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Conveyor_FeedbackMessage msg_;
};

class Init_Conveyor_FeedbackMessage_goal_id
{
public:
  Init_Conveyor_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Conveyor_FeedbackMessage_feedback goal_id(::interfaces::action::Conveyor_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Conveyor_FeedbackMessage_feedback(msg_);
  }

private:
  ::interfaces::action::Conveyor_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Conveyor_FeedbackMessage>()
{
  return interfaces::action::builder::Init_Conveyor_FeedbackMessage_goal_id();
}

}  // namespace interfaces

#endif  // INTERFACES__ACTION__DETAIL__CONVEYOR__BUILDER_HPP_
