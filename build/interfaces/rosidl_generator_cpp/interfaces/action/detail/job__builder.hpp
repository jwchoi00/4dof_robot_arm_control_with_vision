// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:action/Job.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__ACTION__DETAIL__JOB__BUILDER_HPP_
#define INTERFACES__ACTION__DETAIL__JOB__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/action/detail/job__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Job_Goal_goal
{
public:
  explicit Init_Job_Goal_goal(::interfaces::action::Job_Goal & msg)
  : msg_(msg)
  {}
  ::interfaces::action::Job_Goal goal(::interfaces::action::Job_Goal::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Job_Goal msg_;
};

class Init_Job_Goal_bluebox
{
public:
  explicit Init_Job_Goal_bluebox(::interfaces::action::Job_Goal & msg)
  : msg_(msg)
  {}
  Init_Job_Goal_goal bluebox(::interfaces::action::Job_Goal::_bluebox_type arg)
  {
    msg_.bluebox = std::move(arg);
    return Init_Job_Goal_goal(msg_);
  }

private:
  ::interfaces::action::Job_Goal msg_;
};

class Init_Job_Goal_redbox
{
public:
  Init_Job_Goal_redbox()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Job_Goal_bluebox redbox(::interfaces::action::Job_Goal::_redbox_type arg)
  {
    msg_.redbox = std::move(arg);
    return Init_Job_Goal_bluebox(msg_);
  }

private:
  ::interfaces::action::Job_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Job_Goal>()
{
  return interfaces::action::builder::Init_Job_Goal_redbox();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Job_Result_success
{
public:
  Init_Job_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::action::Job_Result success(::interfaces::action::Job_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Job_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Job_Result>()
{
  return interfaces::action::builder::Init_Job_Result_success();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Job_Feedback_feedback
{
public:
  Init_Job_Feedback_feedback()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::action::Job_Feedback feedback(::interfaces::action::Job_Feedback::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Job_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Job_Feedback>()
{
  return interfaces::action::builder::Init_Job_Feedback_feedback();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Job_SendGoal_Request_goal
{
public:
  explicit Init_Job_SendGoal_Request_goal(::interfaces::action::Job_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::interfaces::action::Job_SendGoal_Request goal(::interfaces::action::Job_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Job_SendGoal_Request msg_;
};

class Init_Job_SendGoal_Request_goal_id
{
public:
  Init_Job_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Job_SendGoal_Request_goal goal_id(::interfaces::action::Job_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Job_SendGoal_Request_goal(msg_);
  }

private:
  ::interfaces::action::Job_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Job_SendGoal_Request>()
{
  return interfaces::action::builder::Init_Job_SendGoal_Request_goal_id();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Job_SendGoal_Response_stamp
{
public:
  explicit Init_Job_SendGoal_Response_stamp(::interfaces::action::Job_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::interfaces::action::Job_SendGoal_Response stamp(::interfaces::action::Job_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Job_SendGoal_Response msg_;
};

class Init_Job_SendGoal_Response_accepted
{
public:
  Init_Job_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Job_SendGoal_Response_stamp accepted(::interfaces::action::Job_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Job_SendGoal_Response_stamp(msg_);
  }

private:
  ::interfaces::action::Job_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Job_SendGoal_Response>()
{
  return interfaces::action::builder::Init_Job_SendGoal_Response_accepted();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Job_GetResult_Request_goal_id
{
public:
  Init_Job_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::action::Job_GetResult_Request goal_id(::interfaces::action::Job_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Job_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Job_GetResult_Request>()
{
  return interfaces::action::builder::Init_Job_GetResult_Request_goal_id();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Job_GetResult_Response_result
{
public:
  explicit Init_Job_GetResult_Response_result(::interfaces::action::Job_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::interfaces::action::Job_GetResult_Response result(::interfaces::action::Job_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Job_GetResult_Response msg_;
};

class Init_Job_GetResult_Response_status
{
public:
  Init_Job_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Job_GetResult_Response_result status(::interfaces::action::Job_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Job_GetResult_Response_result(msg_);
  }

private:
  ::interfaces::action::Job_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Job_GetResult_Response>()
{
  return interfaces::action::builder::Init_Job_GetResult_Response_status();
}

}  // namespace interfaces


namespace interfaces
{

namespace action
{

namespace builder
{

class Init_Job_FeedbackMessage_feedback
{
public:
  explicit Init_Job_FeedbackMessage_feedback(::interfaces::action::Job_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::interfaces::action::Job_FeedbackMessage feedback(::interfaces::action::Job_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::action::Job_FeedbackMessage msg_;
};

class Init_Job_FeedbackMessage_goal_id
{
public:
  Init_Job_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Job_FeedbackMessage_feedback goal_id(::interfaces::action::Job_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Job_FeedbackMessage_feedback(msg_);
  }

private:
  ::interfaces::action::Job_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::action::Job_FeedbackMessage>()
{
  return interfaces::action::builder::Init_Job_FeedbackMessage_goal_id();
}

}  // namespace interfaces

#endif  // INTERFACES__ACTION__DETAIL__JOB__BUILDER_HPP_
