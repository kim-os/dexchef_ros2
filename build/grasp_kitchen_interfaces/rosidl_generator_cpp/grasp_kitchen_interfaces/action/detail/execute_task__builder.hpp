// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from grasp_kitchen_interfaces:action/ExecuteTask.idl
// generated code does not contain a copyright notice

#ifndef GRASP_KITCHEN_INTERFACES__ACTION__DETAIL__EXECUTE_TASK__BUILDER_HPP_
#define GRASP_KITCHEN_INTERFACES__ACTION__DETAIL__EXECUTE_TASK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "grasp_kitchen_interfaces/action/detail/execute_task__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace grasp_kitchen_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteTask_Goal_target
{
public:
  explicit Init_ExecuteTask_Goal_target(::grasp_kitchen_interfaces::action::ExecuteTask_Goal & msg)
  : msg_(msg)
  {}
  ::grasp_kitchen_interfaces::action::ExecuteTask_Goal target(::grasp_kitchen_interfaces::action::ExecuteTask_Goal::_target_type arg)
  {
    msg_.target = std::move(arg);
    return std::move(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::ExecuteTask_Goal msg_;
};

class Init_ExecuteTask_Goal_task_type
{
public:
  explicit Init_ExecuteTask_Goal_task_type(::grasp_kitchen_interfaces::action::ExecuteTask_Goal & msg)
  : msg_(msg)
  {}
  Init_ExecuteTask_Goal_target task_type(::grasp_kitchen_interfaces::action::ExecuteTask_Goal::_task_type_type arg)
  {
    msg_.task_type = std::move(arg);
    return Init_ExecuteTask_Goal_target(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::ExecuteTask_Goal msg_;
};

class Init_ExecuteTask_Goal_task_id
{
public:
  Init_ExecuteTask_Goal_task_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteTask_Goal_task_type task_id(::grasp_kitchen_interfaces::action::ExecuteTask_Goal::_task_id_type arg)
  {
    msg_.task_id = std::move(arg);
    return Init_ExecuteTask_Goal_task_type(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::ExecuteTask_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::grasp_kitchen_interfaces::action::ExecuteTask_Goal>()
{
  return grasp_kitchen_interfaces::action::builder::Init_ExecuteTask_Goal_task_id();
}

}  // namespace grasp_kitchen_interfaces


namespace grasp_kitchen_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteTask_Result_error_msg
{
public:
  explicit Init_ExecuteTask_Result_error_msg(::grasp_kitchen_interfaces::action::ExecuteTask_Result & msg)
  : msg_(msg)
  {}
  ::grasp_kitchen_interfaces::action::ExecuteTask_Result error_msg(::grasp_kitchen_interfaces::action::ExecuteTask_Result::_error_msg_type arg)
  {
    msg_.error_msg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::ExecuteTask_Result msg_;
};

class Init_ExecuteTask_Result_success
{
public:
  Init_ExecuteTask_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteTask_Result_error_msg success(::grasp_kitchen_interfaces::action::ExecuteTask_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ExecuteTask_Result_error_msg(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::ExecuteTask_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::grasp_kitchen_interfaces::action::ExecuteTask_Result>()
{
  return grasp_kitchen_interfaces::action::builder::Init_ExecuteTask_Result_success();
}

}  // namespace grasp_kitchen_interfaces


namespace grasp_kitchen_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteTask_Feedback_progress
{
public:
  explicit Init_ExecuteTask_Feedback_progress(::grasp_kitchen_interfaces::action::ExecuteTask_Feedback & msg)
  : msg_(msg)
  {}
  ::grasp_kitchen_interfaces::action::ExecuteTask_Feedback progress(::grasp_kitchen_interfaces::action::ExecuteTask_Feedback::_progress_type arg)
  {
    msg_.progress = std::move(arg);
    return std::move(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::ExecuteTask_Feedback msg_;
};

class Init_ExecuteTask_Feedback_phase
{
public:
  Init_ExecuteTask_Feedback_phase()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteTask_Feedback_progress phase(::grasp_kitchen_interfaces::action::ExecuteTask_Feedback::_phase_type arg)
  {
    msg_.phase = std::move(arg);
    return Init_ExecuteTask_Feedback_progress(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::ExecuteTask_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::grasp_kitchen_interfaces::action::ExecuteTask_Feedback>()
{
  return grasp_kitchen_interfaces::action::builder::Init_ExecuteTask_Feedback_phase();
}

}  // namespace grasp_kitchen_interfaces


namespace grasp_kitchen_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteTask_SendGoal_Request_goal
{
public:
  explicit Init_ExecuteTask_SendGoal_Request_goal(::grasp_kitchen_interfaces::action::ExecuteTask_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::grasp_kitchen_interfaces::action::ExecuteTask_SendGoal_Request goal(::grasp_kitchen_interfaces::action::ExecuteTask_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::ExecuteTask_SendGoal_Request msg_;
};

class Init_ExecuteTask_SendGoal_Request_goal_id
{
public:
  Init_ExecuteTask_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteTask_SendGoal_Request_goal goal_id(::grasp_kitchen_interfaces::action::ExecuteTask_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ExecuteTask_SendGoal_Request_goal(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::ExecuteTask_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::grasp_kitchen_interfaces::action::ExecuteTask_SendGoal_Request>()
{
  return grasp_kitchen_interfaces::action::builder::Init_ExecuteTask_SendGoal_Request_goal_id();
}

}  // namespace grasp_kitchen_interfaces


namespace grasp_kitchen_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteTask_SendGoal_Response_stamp
{
public:
  explicit Init_ExecuteTask_SendGoal_Response_stamp(::grasp_kitchen_interfaces::action::ExecuteTask_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::grasp_kitchen_interfaces::action::ExecuteTask_SendGoal_Response stamp(::grasp_kitchen_interfaces::action::ExecuteTask_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::ExecuteTask_SendGoal_Response msg_;
};

class Init_ExecuteTask_SendGoal_Response_accepted
{
public:
  Init_ExecuteTask_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteTask_SendGoal_Response_stamp accepted(::grasp_kitchen_interfaces::action::ExecuteTask_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_ExecuteTask_SendGoal_Response_stamp(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::ExecuteTask_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::grasp_kitchen_interfaces::action::ExecuteTask_SendGoal_Response>()
{
  return grasp_kitchen_interfaces::action::builder::Init_ExecuteTask_SendGoal_Response_accepted();
}

}  // namespace grasp_kitchen_interfaces


namespace grasp_kitchen_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteTask_GetResult_Request_goal_id
{
public:
  Init_ExecuteTask_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::grasp_kitchen_interfaces::action::ExecuteTask_GetResult_Request goal_id(::grasp_kitchen_interfaces::action::ExecuteTask_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::ExecuteTask_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::grasp_kitchen_interfaces::action::ExecuteTask_GetResult_Request>()
{
  return grasp_kitchen_interfaces::action::builder::Init_ExecuteTask_GetResult_Request_goal_id();
}

}  // namespace grasp_kitchen_interfaces


namespace grasp_kitchen_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteTask_GetResult_Response_result
{
public:
  explicit Init_ExecuteTask_GetResult_Response_result(::grasp_kitchen_interfaces::action::ExecuteTask_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::grasp_kitchen_interfaces::action::ExecuteTask_GetResult_Response result(::grasp_kitchen_interfaces::action::ExecuteTask_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::ExecuteTask_GetResult_Response msg_;
};

class Init_ExecuteTask_GetResult_Response_status
{
public:
  Init_ExecuteTask_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteTask_GetResult_Response_result status(::grasp_kitchen_interfaces::action::ExecuteTask_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ExecuteTask_GetResult_Response_result(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::ExecuteTask_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::grasp_kitchen_interfaces::action::ExecuteTask_GetResult_Response>()
{
  return grasp_kitchen_interfaces::action::builder::Init_ExecuteTask_GetResult_Response_status();
}

}  // namespace grasp_kitchen_interfaces


namespace grasp_kitchen_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteTask_FeedbackMessage_feedback
{
public:
  explicit Init_ExecuteTask_FeedbackMessage_feedback(::grasp_kitchen_interfaces::action::ExecuteTask_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::grasp_kitchen_interfaces::action::ExecuteTask_FeedbackMessage feedback(::grasp_kitchen_interfaces::action::ExecuteTask_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::ExecuteTask_FeedbackMessage msg_;
};

class Init_ExecuteTask_FeedbackMessage_goal_id
{
public:
  Init_ExecuteTask_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteTask_FeedbackMessage_feedback goal_id(::grasp_kitchen_interfaces::action::ExecuteTask_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ExecuteTask_FeedbackMessage_feedback(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::ExecuteTask_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::grasp_kitchen_interfaces::action::ExecuteTask_FeedbackMessage>()
{
  return grasp_kitchen_interfaces::action::builder::Init_ExecuteTask_FeedbackMessage_goal_id();
}

}  // namespace grasp_kitchen_interfaces

#endif  // GRASP_KITCHEN_INTERFACES__ACTION__DETAIL__EXECUTE_TASK__BUILDER_HPP_
