// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from grasp_kitchen_interfaces:srv/SetIO.idl
// generated code does not contain a copyright notice
#include "grasp_kitchen_interfaces/srv/detail/set_io__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `io_name`
#include "rosidl_runtime_c/string_functions.h"

bool
grasp_kitchen_interfaces__srv__SetIO_Request__init(grasp_kitchen_interfaces__srv__SetIO_Request * msg)
{
  if (!msg) {
    return false;
  }
  // io_name
  if (!rosidl_runtime_c__String__init(&msg->io_name)) {
    grasp_kitchen_interfaces__srv__SetIO_Request__fini(msg);
    return false;
  }
  // state
  return true;
}

void
grasp_kitchen_interfaces__srv__SetIO_Request__fini(grasp_kitchen_interfaces__srv__SetIO_Request * msg)
{
  if (!msg) {
    return;
  }
  // io_name
  rosidl_runtime_c__String__fini(&msg->io_name);
  // state
}

bool
grasp_kitchen_interfaces__srv__SetIO_Request__are_equal(const grasp_kitchen_interfaces__srv__SetIO_Request * lhs, const grasp_kitchen_interfaces__srv__SetIO_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // io_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->io_name), &(rhs->io_name)))
  {
    return false;
  }
  // state
  if (lhs->state != rhs->state) {
    return false;
  }
  return true;
}

bool
grasp_kitchen_interfaces__srv__SetIO_Request__copy(
  const grasp_kitchen_interfaces__srv__SetIO_Request * input,
  grasp_kitchen_interfaces__srv__SetIO_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // io_name
  if (!rosidl_runtime_c__String__copy(
      &(input->io_name), &(output->io_name)))
  {
    return false;
  }
  // state
  output->state = input->state;
  return true;
}

grasp_kitchen_interfaces__srv__SetIO_Request *
grasp_kitchen_interfaces__srv__SetIO_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  grasp_kitchen_interfaces__srv__SetIO_Request * msg = (grasp_kitchen_interfaces__srv__SetIO_Request *)allocator.allocate(sizeof(grasp_kitchen_interfaces__srv__SetIO_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(grasp_kitchen_interfaces__srv__SetIO_Request));
  bool success = grasp_kitchen_interfaces__srv__SetIO_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
grasp_kitchen_interfaces__srv__SetIO_Request__destroy(grasp_kitchen_interfaces__srv__SetIO_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    grasp_kitchen_interfaces__srv__SetIO_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
grasp_kitchen_interfaces__srv__SetIO_Request__Sequence__init(grasp_kitchen_interfaces__srv__SetIO_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  grasp_kitchen_interfaces__srv__SetIO_Request * data = NULL;

  if (size) {
    data = (grasp_kitchen_interfaces__srv__SetIO_Request *)allocator.zero_allocate(size, sizeof(grasp_kitchen_interfaces__srv__SetIO_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = grasp_kitchen_interfaces__srv__SetIO_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        grasp_kitchen_interfaces__srv__SetIO_Request__fini(&data[i - 1]);
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
grasp_kitchen_interfaces__srv__SetIO_Request__Sequence__fini(grasp_kitchen_interfaces__srv__SetIO_Request__Sequence * array)
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
      grasp_kitchen_interfaces__srv__SetIO_Request__fini(&array->data[i]);
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

grasp_kitchen_interfaces__srv__SetIO_Request__Sequence *
grasp_kitchen_interfaces__srv__SetIO_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  grasp_kitchen_interfaces__srv__SetIO_Request__Sequence * array = (grasp_kitchen_interfaces__srv__SetIO_Request__Sequence *)allocator.allocate(sizeof(grasp_kitchen_interfaces__srv__SetIO_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = grasp_kitchen_interfaces__srv__SetIO_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
grasp_kitchen_interfaces__srv__SetIO_Request__Sequence__destroy(grasp_kitchen_interfaces__srv__SetIO_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    grasp_kitchen_interfaces__srv__SetIO_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
grasp_kitchen_interfaces__srv__SetIO_Request__Sequence__are_equal(const grasp_kitchen_interfaces__srv__SetIO_Request__Sequence * lhs, const grasp_kitchen_interfaces__srv__SetIO_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!grasp_kitchen_interfaces__srv__SetIO_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
grasp_kitchen_interfaces__srv__SetIO_Request__Sequence__copy(
  const grasp_kitchen_interfaces__srv__SetIO_Request__Sequence * input,
  grasp_kitchen_interfaces__srv__SetIO_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(grasp_kitchen_interfaces__srv__SetIO_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    grasp_kitchen_interfaces__srv__SetIO_Request * data =
      (grasp_kitchen_interfaces__srv__SetIO_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!grasp_kitchen_interfaces__srv__SetIO_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          grasp_kitchen_interfaces__srv__SetIO_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!grasp_kitchen_interfaces__srv__SetIO_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
grasp_kitchen_interfaces__srv__SetIO_Response__init(grasp_kitchen_interfaces__srv__SetIO_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    grasp_kitchen_interfaces__srv__SetIO_Response__fini(msg);
    return false;
  }
  return true;
}

void
grasp_kitchen_interfaces__srv__SetIO_Response__fini(grasp_kitchen_interfaces__srv__SetIO_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
grasp_kitchen_interfaces__srv__SetIO_Response__are_equal(const grasp_kitchen_interfaces__srv__SetIO_Response * lhs, const grasp_kitchen_interfaces__srv__SetIO_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
grasp_kitchen_interfaces__srv__SetIO_Response__copy(
  const grasp_kitchen_interfaces__srv__SetIO_Response * input,
  grasp_kitchen_interfaces__srv__SetIO_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

grasp_kitchen_interfaces__srv__SetIO_Response *
grasp_kitchen_interfaces__srv__SetIO_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  grasp_kitchen_interfaces__srv__SetIO_Response * msg = (grasp_kitchen_interfaces__srv__SetIO_Response *)allocator.allocate(sizeof(grasp_kitchen_interfaces__srv__SetIO_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(grasp_kitchen_interfaces__srv__SetIO_Response));
  bool success = grasp_kitchen_interfaces__srv__SetIO_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
grasp_kitchen_interfaces__srv__SetIO_Response__destroy(grasp_kitchen_interfaces__srv__SetIO_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    grasp_kitchen_interfaces__srv__SetIO_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
grasp_kitchen_interfaces__srv__SetIO_Response__Sequence__init(grasp_kitchen_interfaces__srv__SetIO_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  grasp_kitchen_interfaces__srv__SetIO_Response * data = NULL;

  if (size) {
    data = (grasp_kitchen_interfaces__srv__SetIO_Response *)allocator.zero_allocate(size, sizeof(grasp_kitchen_interfaces__srv__SetIO_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = grasp_kitchen_interfaces__srv__SetIO_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        grasp_kitchen_interfaces__srv__SetIO_Response__fini(&data[i - 1]);
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
grasp_kitchen_interfaces__srv__SetIO_Response__Sequence__fini(grasp_kitchen_interfaces__srv__SetIO_Response__Sequence * array)
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
      grasp_kitchen_interfaces__srv__SetIO_Response__fini(&array->data[i]);
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

grasp_kitchen_interfaces__srv__SetIO_Response__Sequence *
grasp_kitchen_interfaces__srv__SetIO_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  grasp_kitchen_interfaces__srv__SetIO_Response__Sequence * array = (grasp_kitchen_interfaces__srv__SetIO_Response__Sequence *)allocator.allocate(sizeof(grasp_kitchen_interfaces__srv__SetIO_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = grasp_kitchen_interfaces__srv__SetIO_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
grasp_kitchen_interfaces__srv__SetIO_Response__Sequence__destroy(grasp_kitchen_interfaces__srv__SetIO_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    grasp_kitchen_interfaces__srv__SetIO_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
grasp_kitchen_interfaces__srv__SetIO_Response__Sequence__are_equal(const grasp_kitchen_interfaces__srv__SetIO_Response__Sequence * lhs, const grasp_kitchen_interfaces__srv__SetIO_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!grasp_kitchen_interfaces__srv__SetIO_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
grasp_kitchen_interfaces__srv__SetIO_Response__Sequence__copy(
  const grasp_kitchen_interfaces__srv__SetIO_Response__Sequence * input,
  grasp_kitchen_interfaces__srv__SetIO_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(grasp_kitchen_interfaces__srv__SetIO_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    grasp_kitchen_interfaces__srv__SetIO_Response * data =
      (grasp_kitchen_interfaces__srv__SetIO_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!grasp_kitchen_interfaces__srv__SetIO_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          grasp_kitchen_interfaces__srv__SetIO_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!grasp_kitchen_interfaces__srv__SetIO_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
