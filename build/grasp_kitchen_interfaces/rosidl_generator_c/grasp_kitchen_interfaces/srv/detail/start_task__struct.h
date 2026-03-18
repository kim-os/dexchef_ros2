// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from grasp_kitchen_interfaces:srv/StartTask.idl
// generated code does not contain a copyright notice

#ifndef GRASP_KITCHEN_INTERFACES__SRV__DETAIL__START_TASK__STRUCT_H_
#define GRASP_KITCHEN_INTERFACES__SRV__DETAIL__START_TASK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'task_type'
// Member 'target_class'
// Member 'scene_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/StartTask in the package grasp_kitchen_interfaces.
typedef struct grasp_kitchen_interfaces__srv__StartTask_Request
{
  /// e.g. "pick_and_place_pattern"
  rosidl_runtime_c__String task_type;
  /// e.g. "orange_heart"
  rosidl_runtime_c__String target_class;
  /// optional: tie to perception scene
  rosidl_runtime_c__String scene_id;
} grasp_kitchen_interfaces__srv__StartTask_Request;

// Struct for a sequence of grasp_kitchen_interfaces__srv__StartTask_Request.
typedef struct grasp_kitchen_interfaces__srv__StartTask_Request__Sequence
{
  grasp_kitchen_interfaces__srv__StartTask_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grasp_kitchen_interfaces__srv__StartTask_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/StartTask in the package grasp_kitchen_interfaces.
typedef struct grasp_kitchen_interfaces__srv__StartTask_Response
{
  bool accepted;
  rosidl_runtime_c__String message;
} grasp_kitchen_interfaces__srv__StartTask_Response;

// Struct for a sequence of grasp_kitchen_interfaces__srv__StartTask_Response.
typedef struct grasp_kitchen_interfaces__srv__StartTask_Response__Sequence
{
  grasp_kitchen_interfaces__srv__StartTask_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grasp_kitchen_interfaces__srv__StartTask_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GRASP_KITCHEN_INTERFACES__SRV__DETAIL__START_TASK__STRUCT_H_
