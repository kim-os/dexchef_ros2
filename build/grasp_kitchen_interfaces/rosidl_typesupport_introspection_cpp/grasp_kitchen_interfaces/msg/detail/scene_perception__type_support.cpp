// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from grasp_kitchen_interfaces:msg/ScenePerception.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "grasp_kitchen_interfaces/msg/detail/scene_perception__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace grasp_kitchen_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ScenePerception_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) grasp_kitchen_interfaces::msg::ScenePerception(_init);
}

void ScenePerception_fini_function(void * message_memory)
{
  auto typed_message = static_cast<grasp_kitchen_interfaces::msg::ScenePerception *>(message_memory);
  typed_message->~ScenePerception();
}

size_t size_function__ScenePerception__objects(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<grasp_kitchen_interfaces::msg::ObjectDetection> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ScenePerception__objects(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<grasp_kitchen_interfaces::msg::ObjectDetection> *>(untyped_member);
  return &member[index];
}

void * get_function__ScenePerception__objects(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<grasp_kitchen_interfaces::msg::ObjectDetection> *>(untyped_member);
  return &member[index];
}

void fetch_function__ScenePerception__objects(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const grasp_kitchen_interfaces::msg::ObjectDetection *>(
    get_const_function__ScenePerception__objects(untyped_member, index));
  auto & value = *reinterpret_cast<grasp_kitchen_interfaces::msg::ObjectDetection *>(untyped_value);
  value = item;
}

void assign_function__ScenePerception__objects(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<grasp_kitchen_interfaces::msg::ObjectDetection *>(
    get_function__ScenePerception__objects(untyped_member, index));
  const auto & value = *reinterpret_cast<const grasp_kitchen_interfaces::msg::ObjectDetection *>(untyped_value);
  item = value;
}

void resize_function__ScenePerception__objects(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<grasp_kitchen_interfaces::msg::ObjectDetection> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ScenePerception_message_member_array[4] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grasp_kitchen_interfaces::msg::ScenePerception, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "objects",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<grasp_kitchen_interfaces::msg::ObjectDetection>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grasp_kitchen_interfaces::msg::ScenePerception, objects),  // bytes offset in struct
    nullptr,  // default value
    size_function__ScenePerception__objects,  // size() function pointer
    get_const_function__ScenePerception__objects,  // get_const(index) function pointer
    get_function__ScenePerception__objects,  // get(index) function pointer
    fetch_function__ScenePerception__objects,  // fetch(index, &value) function pointer
    assign_function__ScenePerception__objects,  // assign(index, value) function pointer
    resize_function__ScenePerception__objects  // resize(index) function pointer
  },
  {
    "scene_valid",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grasp_kitchen_interfaces::msg::ScenePerception, scene_valid),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "scene_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grasp_kitchen_interfaces::msg::ScenePerception, scene_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ScenePerception_message_members = {
  "grasp_kitchen_interfaces::msg",  // message namespace
  "ScenePerception",  // message name
  4,  // number of fields
  sizeof(grasp_kitchen_interfaces::msg::ScenePerception),
  ScenePerception_message_member_array,  // message members
  ScenePerception_init_function,  // function to initialize message memory (memory has to be allocated)
  ScenePerception_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ScenePerception_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ScenePerception_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace grasp_kitchen_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<grasp_kitchen_interfaces::msg::ScenePerception>()
{
  return &::grasp_kitchen_interfaces::msg::rosidl_typesupport_introspection_cpp::ScenePerception_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, grasp_kitchen_interfaces, msg, ScenePerception)() {
  return &::grasp_kitchen_interfaces::msg::rosidl_typesupport_introspection_cpp::ScenePerception_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
