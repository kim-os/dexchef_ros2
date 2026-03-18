// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from grasp_kitchen_interfaces:srv/StartTask.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "grasp_kitchen_interfaces/srv/detail/start_task__rosidl_typesupport_introspection_c.h"
#include "grasp_kitchen_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "grasp_kitchen_interfaces/srv/detail/start_task__functions.h"
#include "grasp_kitchen_interfaces/srv/detail/start_task__struct.h"


// Include directives for member types
// Member `task_type`
// Member `target_class`
// Member `scene_id`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void grasp_kitchen_interfaces__srv__StartTask_Request__rosidl_typesupport_introspection_c__StartTask_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  grasp_kitchen_interfaces__srv__StartTask_Request__init(message_memory);
}

void grasp_kitchen_interfaces__srv__StartTask_Request__rosidl_typesupport_introspection_c__StartTask_Request_fini_function(void * message_memory)
{
  grasp_kitchen_interfaces__srv__StartTask_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember grasp_kitchen_interfaces__srv__StartTask_Request__rosidl_typesupport_introspection_c__StartTask_Request_message_member_array[3] = {
  {
    "task_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grasp_kitchen_interfaces__srv__StartTask_Request, task_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target_class",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grasp_kitchen_interfaces__srv__StartTask_Request, target_class),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "scene_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grasp_kitchen_interfaces__srv__StartTask_Request, scene_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers grasp_kitchen_interfaces__srv__StartTask_Request__rosidl_typesupport_introspection_c__StartTask_Request_message_members = {
  "grasp_kitchen_interfaces__srv",  // message namespace
  "StartTask_Request",  // message name
  3,  // number of fields
  sizeof(grasp_kitchen_interfaces__srv__StartTask_Request),
  grasp_kitchen_interfaces__srv__StartTask_Request__rosidl_typesupport_introspection_c__StartTask_Request_message_member_array,  // message members
  grasp_kitchen_interfaces__srv__StartTask_Request__rosidl_typesupport_introspection_c__StartTask_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  grasp_kitchen_interfaces__srv__StartTask_Request__rosidl_typesupport_introspection_c__StartTask_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t grasp_kitchen_interfaces__srv__StartTask_Request__rosidl_typesupport_introspection_c__StartTask_Request_message_type_support_handle = {
  0,
  &grasp_kitchen_interfaces__srv__StartTask_Request__rosidl_typesupport_introspection_c__StartTask_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_grasp_kitchen_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, grasp_kitchen_interfaces, srv, StartTask_Request)() {
  if (!grasp_kitchen_interfaces__srv__StartTask_Request__rosidl_typesupport_introspection_c__StartTask_Request_message_type_support_handle.typesupport_identifier) {
    grasp_kitchen_interfaces__srv__StartTask_Request__rosidl_typesupport_introspection_c__StartTask_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &grasp_kitchen_interfaces__srv__StartTask_Request__rosidl_typesupport_introspection_c__StartTask_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "grasp_kitchen_interfaces/srv/detail/start_task__rosidl_typesupport_introspection_c.h"
// already included above
// #include "grasp_kitchen_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "grasp_kitchen_interfaces/srv/detail/start_task__functions.h"
// already included above
// #include "grasp_kitchen_interfaces/srv/detail/start_task__struct.h"


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void grasp_kitchen_interfaces__srv__StartTask_Response__rosidl_typesupport_introspection_c__StartTask_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  grasp_kitchen_interfaces__srv__StartTask_Response__init(message_memory);
}

void grasp_kitchen_interfaces__srv__StartTask_Response__rosidl_typesupport_introspection_c__StartTask_Response_fini_function(void * message_memory)
{
  grasp_kitchen_interfaces__srv__StartTask_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember grasp_kitchen_interfaces__srv__StartTask_Response__rosidl_typesupport_introspection_c__StartTask_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grasp_kitchen_interfaces__srv__StartTask_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grasp_kitchen_interfaces__srv__StartTask_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers grasp_kitchen_interfaces__srv__StartTask_Response__rosidl_typesupport_introspection_c__StartTask_Response_message_members = {
  "grasp_kitchen_interfaces__srv",  // message namespace
  "StartTask_Response",  // message name
  2,  // number of fields
  sizeof(grasp_kitchen_interfaces__srv__StartTask_Response),
  grasp_kitchen_interfaces__srv__StartTask_Response__rosidl_typesupport_introspection_c__StartTask_Response_message_member_array,  // message members
  grasp_kitchen_interfaces__srv__StartTask_Response__rosidl_typesupport_introspection_c__StartTask_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  grasp_kitchen_interfaces__srv__StartTask_Response__rosidl_typesupport_introspection_c__StartTask_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t grasp_kitchen_interfaces__srv__StartTask_Response__rosidl_typesupport_introspection_c__StartTask_Response_message_type_support_handle = {
  0,
  &grasp_kitchen_interfaces__srv__StartTask_Response__rosidl_typesupport_introspection_c__StartTask_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_grasp_kitchen_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, grasp_kitchen_interfaces, srv, StartTask_Response)() {
  if (!grasp_kitchen_interfaces__srv__StartTask_Response__rosidl_typesupport_introspection_c__StartTask_Response_message_type_support_handle.typesupport_identifier) {
    grasp_kitchen_interfaces__srv__StartTask_Response__rosidl_typesupport_introspection_c__StartTask_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &grasp_kitchen_interfaces__srv__StartTask_Response__rosidl_typesupport_introspection_c__StartTask_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "grasp_kitchen_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "grasp_kitchen_interfaces/srv/detail/start_task__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers grasp_kitchen_interfaces__srv__detail__start_task__rosidl_typesupport_introspection_c__StartTask_service_members = {
  "grasp_kitchen_interfaces__srv",  // service namespace
  "StartTask",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // grasp_kitchen_interfaces__srv__detail__start_task__rosidl_typesupport_introspection_c__StartTask_Request_message_type_support_handle,
  NULL  // response message
  // grasp_kitchen_interfaces__srv__detail__start_task__rosidl_typesupport_introspection_c__StartTask_Response_message_type_support_handle
};

static rosidl_service_type_support_t grasp_kitchen_interfaces__srv__detail__start_task__rosidl_typesupport_introspection_c__StartTask_service_type_support_handle = {
  0,
  &grasp_kitchen_interfaces__srv__detail__start_task__rosidl_typesupport_introspection_c__StartTask_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, grasp_kitchen_interfaces, srv, StartTask_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, grasp_kitchen_interfaces, srv, StartTask_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_grasp_kitchen_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, grasp_kitchen_interfaces, srv, StartTask)() {
  if (!grasp_kitchen_interfaces__srv__detail__start_task__rosidl_typesupport_introspection_c__StartTask_service_type_support_handle.typesupport_identifier) {
    grasp_kitchen_interfaces__srv__detail__start_task__rosidl_typesupport_introspection_c__StartTask_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)grasp_kitchen_interfaces__srv__detail__start_task__rosidl_typesupport_introspection_c__StartTask_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, grasp_kitchen_interfaces, srv, StartTask_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, grasp_kitchen_interfaces, srv, StartTask_Response)()->data;
  }

  return &grasp_kitchen_interfaces__srv__detail__start_task__rosidl_typesupport_introspection_c__StartTask_service_type_support_handle;
}
