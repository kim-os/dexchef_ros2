// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from grasp_kitchen_interfaces:srv/SetIO.idl
// generated code does not contain a copyright notice

#ifndef GRASP_KITCHEN_INTERFACES__SRV__DETAIL__SET_IO__STRUCT_H_
#define GRASP_KITCHEN_INTERFACES__SRV__DETAIL__SET_IO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'io_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetIO in the package grasp_kitchen_interfaces.
typedef struct grasp_kitchen_interfaces__srv__SetIO_Request
{
  rosidl_runtime_c__String io_name;
  bool state;
} grasp_kitchen_interfaces__srv__SetIO_Request;

// Struct for a sequence of grasp_kitchen_interfaces__srv__SetIO_Request.
typedef struct grasp_kitchen_interfaces__srv__SetIO_Request__Sequence
{
  grasp_kitchen_interfaces__srv__SetIO_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grasp_kitchen_interfaces__srv__SetIO_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetIO in the package grasp_kitchen_interfaces.
typedef struct grasp_kitchen_interfaces__srv__SetIO_Response
{
  bool success;
  rosidl_runtime_c__String message;
} grasp_kitchen_interfaces__srv__SetIO_Response;

// Struct for a sequence of grasp_kitchen_interfaces__srv__SetIO_Response.
typedef struct grasp_kitchen_interfaces__srv__SetIO_Response__Sequence
{
  grasp_kitchen_interfaces__srv__SetIO_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grasp_kitchen_interfaces__srv__SetIO_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GRASP_KITCHEN_INTERFACES__SRV__DETAIL__SET_IO__STRUCT_H_
