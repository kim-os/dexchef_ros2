// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from grasp_kitchen_interfaces:msg/ScenePerception.idl
// generated code does not contain a copyright notice
#include "grasp_kitchen_interfaces/msg/detail/scene_perception__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `objects`
#include "grasp_kitchen_interfaces/msg/detail/object_detection__functions.h"
// Member `scene_id`
#include "rosidl_runtime_c/string_functions.h"

bool
grasp_kitchen_interfaces__msg__ScenePerception__init(grasp_kitchen_interfaces__msg__ScenePerception * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    grasp_kitchen_interfaces__msg__ScenePerception__fini(msg);
    return false;
  }
  // objects
  if (!grasp_kitchen_interfaces__msg__ObjectDetection__Sequence__init(&msg->objects, 0)) {
    grasp_kitchen_interfaces__msg__ScenePerception__fini(msg);
    return false;
  }
  // scene_valid
  // scene_id
  if (!rosidl_runtime_c__String__init(&msg->scene_id)) {
    grasp_kitchen_interfaces__msg__ScenePerception__fini(msg);
    return false;
  }
  return true;
}

void
grasp_kitchen_interfaces__msg__ScenePerception__fini(grasp_kitchen_interfaces__msg__ScenePerception * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // objects
  grasp_kitchen_interfaces__msg__ObjectDetection__Sequence__fini(&msg->objects);
  // scene_valid
  // scene_id
  rosidl_runtime_c__String__fini(&msg->scene_id);
}

bool
grasp_kitchen_interfaces__msg__ScenePerception__are_equal(const grasp_kitchen_interfaces__msg__ScenePerception * lhs, const grasp_kitchen_interfaces__msg__ScenePerception * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // objects
  if (!grasp_kitchen_interfaces__msg__ObjectDetection__Sequence__are_equal(
      &(lhs->objects), &(rhs->objects)))
  {
    return false;
  }
  // scene_valid
  if (lhs->scene_valid != rhs->scene_valid) {
    return false;
  }
  // scene_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->scene_id), &(rhs->scene_id)))
  {
    return false;
  }
  return true;
}

bool
grasp_kitchen_interfaces__msg__ScenePerception__copy(
  const grasp_kitchen_interfaces__msg__ScenePerception * input,
  grasp_kitchen_interfaces__msg__ScenePerception * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // objects
  if (!grasp_kitchen_interfaces__msg__ObjectDetection__Sequence__copy(
      &(input->objects), &(output->objects)))
  {
    return false;
  }
  // scene_valid
  output->scene_valid = input->scene_valid;
  // scene_id
  if (!rosidl_runtime_c__String__copy(
      &(input->scene_id), &(output->scene_id)))
  {
    return false;
  }
  return true;
}

grasp_kitchen_interfaces__msg__ScenePerception *
grasp_kitchen_interfaces__msg__ScenePerception__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  grasp_kitchen_interfaces__msg__ScenePerception * msg = (grasp_kitchen_interfaces__msg__ScenePerception *)allocator.allocate(sizeof(grasp_kitchen_interfaces__msg__ScenePerception), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(grasp_kitchen_interfaces__msg__ScenePerception));
  bool success = grasp_kitchen_interfaces__msg__ScenePerception__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
grasp_kitchen_interfaces__msg__ScenePerception__destroy(grasp_kitchen_interfaces__msg__ScenePerception * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    grasp_kitchen_interfaces__msg__ScenePerception__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
grasp_kitchen_interfaces__msg__ScenePerception__Sequence__init(grasp_kitchen_interfaces__msg__ScenePerception__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  grasp_kitchen_interfaces__msg__ScenePerception * data = NULL;

  if (size) {
    data = (grasp_kitchen_interfaces__msg__ScenePerception *)allocator.zero_allocate(size, sizeof(grasp_kitchen_interfaces__msg__ScenePerception), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = grasp_kitchen_interfaces__msg__ScenePerception__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        grasp_kitchen_interfaces__msg__ScenePerception__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
grasp_kitchen_interfaces__msg__ScenePerception__Sequence__fini(grasp_kitchen_interfaces__msg__ScenePerception__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      grasp_kitchen_interfaces__msg__ScenePerception__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

grasp_kitchen_interfaces__msg__ScenePerception__Sequence *
grasp_kitchen_interfaces__msg__ScenePerception__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  grasp_kitchen_interfaces__msg__ScenePerception__Sequence * array = (grasp_kitchen_interfaces__msg__ScenePerception__Sequence *)allocator.allocate(sizeof(grasp_kitchen_interfaces__msg__ScenePerception__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = grasp_kitchen_interfaces__msg__ScenePerception__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
grasp_kitchen_interfaces__msg__ScenePerception__Sequence__destroy(grasp_kitchen_interfaces__msg__ScenePerception__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    grasp_kitchen_interfaces__msg__ScenePerception__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
grasp_kitchen_interfaces__msg__ScenePerception__Sequence__are_equal(const grasp_kitchen_interfaces__msg__ScenePerception__Sequence * lhs, const grasp_kitchen_interfaces__msg__ScenePerception__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!grasp_kitchen_interfaces__msg__ScenePerception__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
grasp_kitchen_interfaces__msg__ScenePerception__Sequence__copy(
  const grasp_kitchen_interfaces__msg__ScenePerception__Sequence * input,
  grasp_kitchen_interfaces__msg__ScenePerception__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(grasp_kitchen_interfaces__msg__ScenePerception);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    grasp_kitchen_interfaces__msg__ScenePerception * data =
      (grasp_kitchen_interfaces__msg__ScenePerception *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!grasp_kitchen_interfaces__msg__ScenePerception__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          grasp_kitchen_interfaces__msg__ScenePerception__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!grasp_kitchen_interfaces__msg__ScenePerception__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
