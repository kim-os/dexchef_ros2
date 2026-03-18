// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from grasp_kitchen_interfaces:action/ExecuteTask.idl
// generated code does not contain a copyright notice

#ifndef GRASP_KITCHEN_INTERFACES__ACTION__DETAIL__EXECUTE_TASK__STRUCT_H_
#define GRASP_KITCHEN_INTERFACES__ACTION__DETAIL__EXECUTE_TASK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'task_id'
// Member 'task_type'
#include "rosidl_runtime_c/string.h"
// Member 'target'
#include "grasp_kitchen_interfaces/msg/detail/task_target__struct.h"

/// Struct defined in action/ExecuteTask in the package grasp_kitchen_interfaces.
typedef struct grasp_kitchen_interfaces__action__ExecuteTask_Goal
{
  rosidl_runtime_c__String task_id;
  rosidl_runtime_c__String task_type;
  grasp_kitchen_interfaces__msg__TaskTarget target;
} grasp_kitchen_interfaces__action__ExecuteTask_Goal;

// Struct for a sequence of grasp_kitchen_interfaces__action__ExecuteTask_Goal.
typedef struct grasp_kitchen_interfaces__action__ExecuteTask_Goal__Sequence
{
  grasp_kitchen_interfaces__action__ExecuteTask_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grasp_kitchen_interfaces__action__ExecuteTask_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'error_msg'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/ExecuteTask in the package grasp_kitchen_interfaces.
typedef struct grasp_kitchen_interfaces__action__ExecuteTask_Result
{
  bool success;
  rosidl_runtime_c__String error_msg;
} grasp_kitchen_interfaces__action__ExecuteTask_Result;

// Struct for a sequence of grasp_kitchen_interfaces__action__ExecuteTask_Result.
typedef struct grasp_kitchen_interfaces__action__ExecuteTask_Result__Sequence
{
  grasp_kitchen_interfaces__action__ExecuteTask_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grasp_kitchen_interfaces__action__ExecuteTask_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'phase'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/ExecuteTask in the package grasp_kitchen_interfaces.
typedef struct grasp_kitchen_interfaces__action__ExecuteTask_Feedback
{
  /// e.g. "planning", "moving_to_pregrasp", "grasping", "placing"
  rosidl_runtime_c__String phase;
  /// 0.0 - 1.0
  float progress;
} grasp_kitchen_interfaces__action__ExecuteTask_Feedback;

// Struct for a sequence of grasp_kitchen_interfaces__action__ExecuteTask_Feedback.
typedef struct grasp_kitchen_interfaces__action__ExecuteTask_Feedback__Sequence
{
  grasp_kitchen_interfaces__action__ExecuteTask_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grasp_kitchen_interfaces__action__ExecuteTask_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "grasp_kitchen_interfaces/action/detail/execute_task__struct.h"

/// Struct defined in action/ExecuteTask in the package grasp_kitchen_interfaces.
typedef struct grasp_kitchen_interfaces__action__ExecuteTask_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  grasp_kitchen_interfaces__action__ExecuteTask_Goal goal;
} grasp_kitchen_interfaces__action__ExecuteTask_SendGoal_Request;

// Struct for a sequence of grasp_kitchen_interfaces__action__ExecuteTask_SendGoal_Request.
typedef struct grasp_kitchen_interfaces__action__ExecuteTask_SendGoal_Request__Sequence
{
  grasp_kitchen_interfaces__action__ExecuteTask_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grasp_kitchen_interfaces__action__ExecuteTask_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/ExecuteTask in the package grasp_kitchen_interfaces.
typedef struct grasp_kitchen_interfaces__action__ExecuteTask_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} grasp_kitchen_interfaces__action__ExecuteTask_SendGoal_Response;

// Struct for a sequence of grasp_kitchen_interfaces__action__ExecuteTask_SendGoal_Response.
typedef struct grasp_kitchen_interfaces__action__ExecuteTask_SendGoal_Response__Sequence
{
  grasp_kitchen_interfaces__action__ExecuteTask_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grasp_kitchen_interfaces__action__ExecuteTask_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/ExecuteTask in the package grasp_kitchen_interfaces.
typedef struct grasp_kitchen_interfaces__action__ExecuteTask_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} grasp_kitchen_interfaces__action__ExecuteTask_GetResult_Request;

// Struct for a sequence of grasp_kitchen_interfaces__action__ExecuteTask_GetResult_Request.
typedef struct grasp_kitchen_interfaces__action__ExecuteTask_GetResult_Request__Sequence
{
  grasp_kitchen_interfaces__action__ExecuteTask_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grasp_kitchen_interfaces__action__ExecuteTask_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "grasp_kitchen_interfaces/action/detail/execute_task__struct.h"

/// Struct defined in action/ExecuteTask in the package grasp_kitchen_interfaces.
typedef struct grasp_kitchen_interfaces__action__ExecuteTask_GetResult_Response
{
  int8_t status;
  grasp_kitchen_interfaces__action__ExecuteTask_Result result;
} grasp_kitchen_interfaces__action__ExecuteTask_GetResult_Response;

// Struct for a sequence of grasp_kitchen_interfaces__action__ExecuteTask_GetResult_Response.
typedef struct grasp_kitchen_interfaces__action__ExecuteTask_GetResult_Response__Sequence
{
  grasp_kitchen_interfaces__action__ExecuteTask_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grasp_kitchen_interfaces__action__ExecuteTask_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "grasp_kitchen_interfaces/action/detail/execute_task__struct.h"

/// Struct defined in action/ExecuteTask in the package grasp_kitchen_interfaces.
typedef struct grasp_kitchen_interfaces__action__ExecuteTask_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  grasp_kitchen_interfaces__action__ExecuteTask_Feedback feedback;
} grasp_kitchen_interfaces__action__ExecuteTask_FeedbackMessage;

// Struct for a sequence of grasp_kitchen_interfaces__action__ExecuteTask_FeedbackMessage.
typedef struct grasp_kitchen_interfaces__action__ExecuteTask_FeedbackMessage__Sequence
{
  grasp_kitchen_interfaces__action__ExecuteTask_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grasp_kitchen_interfaces__action__ExecuteTask_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GRASP_KITCHEN_INTERFACES__ACTION__DETAIL__EXECUTE_TASK__STRUCT_H_
