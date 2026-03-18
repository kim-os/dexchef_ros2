// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from grasp_kitchen_interfaces:action/FollowCartesianTrajectory.idl
// generated code does not contain a copyright notice

#ifndef GRASP_KITCHEN_INTERFACES__ACTION__DETAIL__FOLLOW_CARTESIAN_TRAJECTORY__STRUCT_H_
#define GRASP_KITCHEN_INTERFACES__ACTION__DETAIL__FOLLOW_CARTESIAN_TRAJECTORY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'waypoints'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in action/FollowCartesianTrajectory in the package grasp_kitchen_interfaces.
typedef struct grasp_kitchen_interfaces__action__FollowCartesianTrajectory_Goal
{
  geometry_msgs__msg__Pose__Sequence waypoints;
  float max_velocity;
  float max_acceleration;
} grasp_kitchen_interfaces__action__FollowCartesianTrajectory_Goal;

// Struct for a sequence of grasp_kitchen_interfaces__action__FollowCartesianTrajectory_Goal.
typedef struct grasp_kitchen_interfaces__action__FollowCartesianTrajectory_Goal__Sequence
{
  grasp_kitchen_interfaces__action__FollowCartesianTrajectory_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grasp_kitchen_interfaces__action__FollowCartesianTrajectory_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'error_msg'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/FollowCartesianTrajectory in the package grasp_kitchen_interfaces.
typedef struct grasp_kitchen_interfaces__action__FollowCartesianTrajectory_Result
{
  bool success;
  rosidl_runtime_c__String error_msg;
} grasp_kitchen_interfaces__action__FollowCartesianTrajectory_Result;

// Struct for a sequence of grasp_kitchen_interfaces__action__FollowCartesianTrajectory_Result.
typedef struct grasp_kitchen_interfaces__action__FollowCartesianTrajectory_Result__Sequence
{
  grasp_kitchen_interfaces__action__FollowCartesianTrajectory_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grasp_kitchen_interfaces__action__FollowCartesianTrajectory_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'current_pose'
// already included above
// #include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in action/FollowCartesianTrajectory in the package grasp_kitchen_interfaces.
typedef struct grasp_kitchen_interfaces__action__FollowCartesianTrajectory_Feedback
{
  uint32_t current_index;
  geometry_msgs__msg__Pose current_pose;
} grasp_kitchen_interfaces__action__FollowCartesianTrajectory_Feedback;

// Struct for a sequence of grasp_kitchen_interfaces__action__FollowCartesianTrajectory_Feedback.
typedef struct grasp_kitchen_interfaces__action__FollowCartesianTrajectory_Feedback__Sequence
{
  grasp_kitchen_interfaces__action__FollowCartesianTrajectory_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grasp_kitchen_interfaces__action__FollowCartesianTrajectory_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "grasp_kitchen_interfaces/action/detail/follow_cartesian_trajectory__struct.h"

/// Struct defined in action/FollowCartesianTrajectory in the package grasp_kitchen_interfaces.
typedef struct grasp_kitchen_interfaces__action__FollowCartesianTrajectory_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  grasp_kitchen_interfaces__action__FollowCartesianTrajectory_Goal goal;
} grasp_kitchen_interfaces__action__FollowCartesianTrajectory_SendGoal_Request;

// Struct for a sequence of grasp_kitchen_interfaces__action__FollowCartesianTrajectory_SendGoal_Request.
typedef struct grasp_kitchen_interfaces__action__FollowCartesianTrajectory_SendGoal_Request__Sequence
{
  grasp_kitchen_interfaces__action__FollowCartesianTrajectory_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grasp_kitchen_interfaces__action__FollowCartesianTrajectory_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/FollowCartesianTrajectory in the package grasp_kitchen_interfaces.
typedef struct grasp_kitchen_interfaces__action__FollowCartesianTrajectory_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} grasp_kitchen_interfaces__action__FollowCartesianTrajectory_SendGoal_Response;

// Struct for a sequence of grasp_kitchen_interfaces__action__FollowCartesianTrajectory_SendGoal_Response.
typedef struct grasp_kitchen_interfaces__action__FollowCartesianTrajectory_SendGoal_Response__Sequence
{
  grasp_kitchen_interfaces__action__FollowCartesianTrajectory_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grasp_kitchen_interfaces__action__FollowCartesianTrajectory_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/FollowCartesianTrajectory in the package grasp_kitchen_interfaces.
typedef struct grasp_kitchen_interfaces__action__FollowCartesianTrajectory_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} grasp_kitchen_interfaces__action__FollowCartesianTrajectory_GetResult_Request;

// Struct for a sequence of grasp_kitchen_interfaces__action__FollowCartesianTrajectory_GetResult_Request.
typedef struct grasp_kitchen_interfaces__action__FollowCartesianTrajectory_GetResult_Request__Sequence
{
  grasp_kitchen_interfaces__action__FollowCartesianTrajectory_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grasp_kitchen_interfaces__action__FollowCartesianTrajectory_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "grasp_kitchen_interfaces/action/detail/follow_cartesian_trajectory__struct.h"

/// Struct defined in action/FollowCartesianTrajectory in the package grasp_kitchen_interfaces.
typedef struct grasp_kitchen_interfaces__action__FollowCartesianTrajectory_GetResult_Response
{
  int8_t status;
  grasp_kitchen_interfaces__action__FollowCartesianTrajectory_Result result;
} grasp_kitchen_interfaces__action__FollowCartesianTrajectory_GetResult_Response;

// Struct for a sequence of grasp_kitchen_interfaces__action__FollowCartesianTrajectory_GetResult_Response.
typedef struct grasp_kitchen_interfaces__action__FollowCartesianTrajectory_GetResult_Response__Sequence
{
  grasp_kitchen_interfaces__action__FollowCartesianTrajectory_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grasp_kitchen_interfaces__action__FollowCartesianTrajectory_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "grasp_kitchen_interfaces/action/detail/follow_cartesian_trajectory__struct.h"

/// Struct defined in action/FollowCartesianTrajectory in the package grasp_kitchen_interfaces.
typedef struct grasp_kitchen_interfaces__action__FollowCartesianTrajectory_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  grasp_kitchen_interfaces__action__FollowCartesianTrajectory_Feedback feedback;
} grasp_kitchen_interfaces__action__FollowCartesianTrajectory_FeedbackMessage;

// Struct for a sequence of grasp_kitchen_interfaces__action__FollowCartesianTrajectory_FeedbackMessage.
typedef struct grasp_kitchen_interfaces__action__FollowCartesianTrajectory_FeedbackMessage__Sequence
{
  grasp_kitchen_interfaces__action__FollowCartesianTrajectory_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grasp_kitchen_interfaces__action__FollowCartesianTrajectory_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GRASP_KITCHEN_INTERFACES__ACTION__DETAIL__FOLLOW_CARTESIAN_TRAJECTORY__STRUCT_H_
