// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from grasp_kitchen_interfaces:action/FollowCartesianTrajectory.idl
// generated code does not contain a copyright notice

#ifndef GRASP_KITCHEN_INTERFACES__ACTION__DETAIL__FOLLOW_CARTESIAN_TRAJECTORY__BUILDER_HPP_
#define GRASP_KITCHEN_INTERFACES__ACTION__DETAIL__FOLLOW_CARTESIAN_TRAJECTORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "grasp_kitchen_interfaces/action/detail/follow_cartesian_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace grasp_kitchen_interfaces
{

namespace action
{

namespace builder
{

class Init_FollowCartesianTrajectory_Goal_max_acceleration
{
public:
  explicit Init_FollowCartesianTrajectory_Goal_max_acceleration(::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Goal & msg)
  : msg_(msg)
  {}
  ::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Goal max_acceleration(::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Goal::_max_acceleration_type arg)
  {
    msg_.max_acceleration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Goal msg_;
};

class Init_FollowCartesianTrajectory_Goal_max_velocity
{
public:
  explicit Init_FollowCartesianTrajectory_Goal_max_velocity(::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Goal & msg)
  : msg_(msg)
  {}
  Init_FollowCartesianTrajectory_Goal_max_acceleration max_velocity(::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Goal::_max_velocity_type arg)
  {
    msg_.max_velocity = std::move(arg);
    return Init_FollowCartesianTrajectory_Goal_max_acceleration(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Goal msg_;
};

class Init_FollowCartesianTrajectory_Goal_waypoints
{
public:
  Init_FollowCartesianTrajectory_Goal_waypoints()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FollowCartesianTrajectory_Goal_max_velocity waypoints(::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Goal::_waypoints_type arg)
  {
    msg_.waypoints = std::move(arg);
    return Init_FollowCartesianTrajectory_Goal_max_velocity(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Goal>()
{
  return grasp_kitchen_interfaces::action::builder::Init_FollowCartesianTrajectory_Goal_waypoints();
}

}  // namespace grasp_kitchen_interfaces


namespace grasp_kitchen_interfaces
{

namespace action
{

namespace builder
{

class Init_FollowCartesianTrajectory_Result_error_msg
{
public:
  explicit Init_FollowCartesianTrajectory_Result_error_msg(::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Result & msg)
  : msg_(msg)
  {}
  ::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Result error_msg(::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Result::_error_msg_type arg)
  {
    msg_.error_msg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Result msg_;
};

class Init_FollowCartesianTrajectory_Result_success
{
public:
  Init_FollowCartesianTrajectory_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FollowCartesianTrajectory_Result_error_msg success(::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_FollowCartesianTrajectory_Result_error_msg(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Result>()
{
  return grasp_kitchen_interfaces::action::builder::Init_FollowCartesianTrajectory_Result_success();
}

}  // namespace grasp_kitchen_interfaces


namespace grasp_kitchen_interfaces
{

namespace action
{

namespace builder
{

class Init_FollowCartesianTrajectory_Feedback_current_pose
{
public:
  explicit Init_FollowCartesianTrajectory_Feedback_current_pose(::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Feedback & msg)
  : msg_(msg)
  {}
  ::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Feedback current_pose(::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Feedback::_current_pose_type arg)
  {
    msg_.current_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Feedback msg_;
};

class Init_FollowCartesianTrajectory_Feedback_current_index
{
public:
  Init_FollowCartesianTrajectory_Feedback_current_index()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FollowCartesianTrajectory_Feedback_current_pose current_index(::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Feedback::_current_index_type arg)
  {
    msg_.current_index = std::move(arg);
    return Init_FollowCartesianTrajectory_Feedback_current_pose(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Feedback>()
{
  return grasp_kitchen_interfaces::action::builder::Init_FollowCartesianTrajectory_Feedback_current_index();
}

}  // namespace grasp_kitchen_interfaces


namespace grasp_kitchen_interfaces
{

namespace action
{

namespace builder
{

class Init_FollowCartesianTrajectory_SendGoal_Request_goal
{
public:
  explicit Init_FollowCartesianTrajectory_SendGoal_Request_goal(::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Request goal(::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Request msg_;
};

class Init_FollowCartesianTrajectory_SendGoal_Request_goal_id
{
public:
  Init_FollowCartesianTrajectory_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FollowCartesianTrajectory_SendGoal_Request_goal goal_id(::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_FollowCartesianTrajectory_SendGoal_Request_goal(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Request>()
{
  return grasp_kitchen_interfaces::action::builder::Init_FollowCartesianTrajectory_SendGoal_Request_goal_id();
}

}  // namespace grasp_kitchen_interfaces


namespace grasp_kitchen_interfaces
{

namespace action
{

namespace builder
{

class Init_FollowCartesianTrajectory_SendGoal_Response_stamp
{
public:
  explicit Init_FollowCartesianTrajectory_SendGoal_Response_stamp(::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Response stamp(::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Response msg_;
};

class Init_FollowCartesianTrajectory_SendGoal_Response_accepted
{
public:
  Init_FollowCartesianTrajectory_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FollowCartesianTrajectory_SendGoal_Response_stamp accepted(::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_FollowCartesianTrajectory_SendGoal_Response_stamp(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Response>()
{
  return grasp_kitchen_interfaces::action::builder::Init_FollowCartesianTrajectory_SendGoal_Response_accepted();
}

}  // namespace grasp_kitchen_interfaces


namespace grasp_kitchen_interfaces
{

namespace action
{

namespace builder
{

class Init_FollowCartesianTrajectory_GetResult_Request_goal_id
{
public:
  Init_FollowCartesianTrajectory_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Request goal_id(::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Request>()
{
  return grasp_kitchen_interfaces::action::builder::Init_FollowCartesianTrajectory_GetResult_Request_goal_id();
}

}  // namespace grasp_kitchen_interfaces


namespace grasp_kitchen_interfaces
{

namespace action
{

namespace builder
{

class Init_FollowCartesianTrajectory_GetResult_Response_result
{
public:
  explicit Init_FollowCartesianTrajectory_GetResult_Response_result(::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Response result(::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Response msg_;
};

class Init_FollowCartesianTrajectory_GetResult_Response_status
{
public:
  Init_FollowCartesianTrajectory_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FollowCartesianTrajectory_GetResult_Response_result status(::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_FollowCartesianTrajectory_GetResult_Response_result(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Response>()
{
  return grasp_kitchen_interfaces::action::builder::Init_FollowCartesianTrajectory_GetResult_Response_status();
}

}  // namespace grasp_kitchen_interfaces


namespace grasp_kitchen_interfaces
{

namespace action
{

namespace builder
{

class Init_FollowCartesianTrajectory_FeedbackMessage_feedback
{
public:
  explicit Init_FollowCartesianTrajectory_FeedbackMessage_feedback(::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_FeedbackMessage feedback(::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_FeedbackMessage msg_;
};

class Init_FollowCartesianTrajectory_FeedbackMessage_goal_id
{
public:
  Init_FollowCartesianTrajectory_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FollowCartesianTrajectory_FeedbackMessage_feedback goal_id(::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_FollowCartesianTrajectory_FeedbackMessage_feedback(msg_);
  }

private:
  ::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::grasp_kitchen_interfaces::action::FollowCartesianTrajectory_FeedbackMessage>()
{
  return grasp_kitchen_interfaces::action::builder::Init_FollowCartesianTrajectory_FeedbackMessage_goal_id();
}

}  // namespace grasp_kitchen_interfaces

#endif  // GRASP_KITCHEN_INTERFACES__ACTION__DETAIL__FOLLOW_CARTESIAN_TRAJECTORY__BUILDER_HPP_
