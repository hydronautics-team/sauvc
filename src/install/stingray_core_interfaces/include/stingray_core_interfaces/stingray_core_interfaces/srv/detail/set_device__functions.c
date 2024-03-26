// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from stingray_core_interfaces:srv/SetDevice.idl
// generated code does not contain a copyright notice
#include "stingray_core_interfaces/srv/detail/set_device__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
stingray_core_interfaces__srv__SetDevice_Request__init(stingray_core_interfaces__srv__SetDevice_Request * msg)
{
  if (!msg) {
    return false;
  }
  // device
  // value
  return true;
}

void
stingray_core_interfaces__srv__SetDevice_Request__fini(stingray_core_interfaces__srv__SetDevice_Request * msg)
{
  if (!msg) {
    return;
  }
  // device
  // value
}

bool
stingray_core_interfaces__srv__SetDevice_Request__are_equal(const stingray_core_interfaces__srv__SetDevice_Request * lhs, const stingray_core_interfaces__srv__SetDevice_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // device
  if (lhs->device != rhs->device) {
    return false;
  }
  // value
  if (lhs->value != rhs->value) {
    return false;
  }
  return true;
}

bool
stingray_core_interfaces__srv__SetDevice_Request__copy(
  const stingray_core_interfaces__srv__SetDevice_Request * input,
  stingray_core_interfaces__srv__SetDevice_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // device
  output->device = input->device;
  // value
  output->value = input->value;
  return true;
}

stingray_core_interfaces__srv__SetDevice_Request *
stingray_core_interfaces__srv__SetDevice_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stingray_core_interfaces__srv__SetDevice_Request * msg = (stingray_core_interfaces__srv__SetDevice_Request *)allocator.allocate(sizeof(stingray_core_interfaces__srv__SetDevice_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(stingray_core_interfaces__srv__SetDevice_Request));
  bool success = stingray_core_interfaces__srv__SetDevice_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
stingray_core_interfaces__srv__SetDevice_Request__destroy(stingray_core_interfaces__srv__SetDevice_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    stingray_core_interfaces__srv__SetDevice_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
stingray_core_interfaces__srv__SetDevice_Request__Sequence__init(stingray_core_interfaces__srv__SetDevice_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stingray_core_interfaces__srv__SetDevice_Request * data = NULL;

  if (size) {
    data = (stingray_core_interfaces__srv__SetDevice_Request *)allocator.zero_allocate(size, sizeof(stingray_core_interfaces__srv__SetDevice_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = stingray_core_interfaces__srv__SetDevice_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        stingray_core_interfaces__srv__SetDevice_Request__fini(&data[i - 1]);
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
stingray_core_interfaces__srv__SetDevice_Request__Sequence__fini(stingray_core_interfaces__srv__SetDevice_Request__Sequence * array)
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
      stingray_core_interfaces__srv__SetDevice_Request__fini(&array->data[i]);
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

stingray_core_interfaces__srv__SetDevice_Request__Sequence *
stingray_core_interfaces__srv__SetDevice_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stingray_core_interfaces__srv__SetDevice_Request__Sequence * array = (stingray_core_interfaces__srv__SetDevice_Request__Sequence *)allocator.allocate(sizeof(stingray_core_interfaces__srv__SetDevice_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = stingray_core_interfaces__srv__SetDevice_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
stingray_core_interfaces__srv__SetDevice_Request__Sequence__destroy(stingray_core_interfaces__srv__SetDevice_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    stingray_core_interfaces__srv__SetDevice_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
stingray_core_interfaces__srv__SetDevice_Request__Sequence__are_equal(const stingray_core_interfaces__srv__SetDevice_Request__Sequence * lhs, const stingray_core_interfaces__srv__SetDevice_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!stingray_core_interfaces__srv__SetDevice_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
stingray_core_interfaces__srv__SetDevice_Request__Sequence__copy(
  const stingray_core_interfaces__srv__SetDevice_Request__Sequence * input,
  stingray_core_interfaces__srv__SetDevice_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(stingray_core_interfaces__srv__SetDevice_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    stingray_core_interfaces__srv__SetDevice_Request * data =
      (stingray_core_interfaces__srv__SetDevice_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!stingray_core_interfaces__srv__SetDevice_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          stingray_core_interfaces__srv__SetDevice_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!stingray_core_interfaces__srv__SetDevice_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
stingray_core_interfaces__srv__SetDevice_Response__init(stingray_core_interfaces__srv__SetDevice_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    stingray_core_interfaces__srv__SetDevice_Response__fini(msg);
    return false;
  }
  return true;
}

void
stingray_core_interfaces__srv__SetDevice_Response__fini(stingray_core_interfaces__srv__SetDevice_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
stingray_core_interfaces__srv__SetDevice_Response__are_equal(const stingray_core_interfaces__srv__SetDevice_Response * lhs, const stingray_core_interfaces__srv__SetDevice_Response * rhs)
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
stingray_core_interfaces__srv__SetDevice_Response__copy(
  const stingray_core_interfaces__srv__SetDevice_Response * input,
  stingray_core_interfaces__srv__SetDevice_Response * output)
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

stingray_core_interfaces__srv__SetDevice_Response *
stingray_core_interfaces__srv__SetDevice_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stingray_core_interfaces__srv__SetDevice_Response * msg = (stingray_core_interfaces__srv__SetDevice_Response *)allocator.allocate(sizeof(stingray_core_interfaces__srv__SetDevice_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(stingray_core_interfaces__srv__SetDevice_Response));
  bool success = stingray_core_interfaces__srv__SetDevice_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
stingray_core_interfaces__srv__SetDevice_Response__destroy(stingray_core_interfaces__srv__SetDevice_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    stingray_core_interfaces__srv__SetDevice_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
stingray_core_interfaces__srv__SetDevice_Response__Sequence__init(stingray_core_interfaces__srv__SetDevice_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stingray_core_interfaces__srv__SetDevice_Response * data = NULL;

  if (size) {
    data = (stingray_core_interfaces__srv__SetDevice_Response *)allocator.zero_allocate(size, sizeof(stingray_core_interfaces__srv__SetDevice_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = stingray_core_interfaces__srv__SetDevice_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        stingray_core_interfaces__srv__SetDevice_Response__fini(&data[i - 1]);
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
stingray_core_interfaces__srv__SetDevice_Response__Sequence__fini(stingray_core_interfaces__srv__SetDevice_Response__Sequence * array)
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
      stingray_core_interfaces__srv__SetDevice_Response__fini(&array->data[i]);
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

stingray_core_interfaces__srv__SetDevice_Response__Sequence *
stingray_core_interfaces__srv__SetDevice_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stingray_core_interfaces__srv__SetDevice_Response__Sequence * array = (stingray_core_interfaces__srv__SetDevice_Response__Sequence *)allocator.allocate(sizeof(stingray_core_interfaces__srv__SetDevice_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = stingray_core_interfaces__srv__SetDevice_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
stingray_core_interfaces__srv__SetDevice_Response__Sequence__destroy(stingray_core_interfaces__srv__SetDevice_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    stingray_core_interfaces__srv__SetDevice_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
stingray_core_interfaces__srv__SetDevice_Response__Sequence__are_equal(const stingray_core_interfaces__srv__SetDevice_Response__Sequence * lhs, const stingray_core_interfaces__srv__SetDevice_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!stingray_core_interfaces__srv__SetDevice_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
stingray_core_interfaces__srv__SetDevice_Response__Sequence__copy(
  const stingray_core_interfaces__srv__SetDevice_Response__Sequence * input,
  stingray_core_interfaces__srv__SetDevice_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(stingray_core_interfaces__srv__SetDevice_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    stingray_core_interfaces__srv__SetDevice_Response * data =
      (stingray_core_interfaces__srv__SetDevice_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!stingray_core_interfaces__srv__SetDevice_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          stingray_core_interfaces__srv__SetDevice_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!stingray_core_interfaces__srv__SetDevice_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "stingray_core_interfaces/srv/detail/set_device__functions.h"

bool
stingray_core_interfaces__srv__SetDevice_Event__init(stingray_core_interfaces__srv__SetDevice_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    stingray_core_interfaces__srv__SetDevice_Event__fini(msg);
    return false;
  }
  // request
  if (!stingray_core_interfaces__srv__SetDevice_Request__Sequence__init(&msg->request, 0)) {
    stingray_core_interfaces__srv__SetDevice_Event__fini(msg);
    return false;
  }
  // response
  if (!stingray_core_interfaces__srv__SetDevice_Response__Sequence__init(&msg->response, 0)) {
    stingray_core_interfaces__srv__SetDevice_Event__fini(msg);
    return false;
  }
  return true;
}

void
stingray_core_interfaces__srv__SetDevice_Event__fini(stingray_core_interfaces__srv__SetDevice_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  stingray_core_interfaces__srv__SetDevice_Request__Sequence__fini(&msg->request);
  // response
  stingray_core_interfaces__srv__SetDevice_Response__Sequence__fini(&msg->response);
}

bool
stingray_core_interfaces__srv__SetDevice_Event__are_equal(const stingray_core_interfaces__srv__SetDevice_Event * lhs, const stingray_core_interfaces__srv__SetDevice_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!stingray_core_interfaces__srv__SetDevice_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!stingray_core_interfaces__srv__SetDevice_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
stingray_core_interfaces__srv__SetDevice_Event__copy(
  const stingray_core_interfaces__srv__SetDevice_Event * input,
  stingray_core_interfaces__srv__SetDevice_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!stingray_core_interfaces__srv__SetDevice_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!stingray_core_interfaces__srv__SetDevice_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

stingray_core_interfaces__srv__SetDevice_Event *
stingray_core_interfaces__srv__SetDevice_Event__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stingray_core_interfaces__srv__SetDevice_Event * msg = (stingray_core_interfaces__srv__SetDevice_Event *)allocator.allocate(sizeof(stingray_core_interfaces__srv__SetDevice_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(stingray_core_interfaces__srv__SetDevice_Event));
  bool success = stingray_core_interfaces__srv__SetDevice_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
stingray_core_interfaces__srv__SetDevice_Event__destroy(stingray_core_interfaces__srv__SetDevice_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    stingray_core_interfaces__srv__SetDevice_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
stingray_core_interfaces__srv__SetDevice_Event__Sequence__init(stingray_core_interfaces__srv__SetDevice_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stingray_core_interfaces__srv__SetDevice_Event * data = NULL;

  if (size) {
    data = (stingray_core_interfaces__srv__SetDevice_Event *)allocator.zero_allocate(size, sizeof(stingray_core_interfaces__srv__SetDevice_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = stingray_core_interfaces__srv__SetDevice_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        stingray_core_interfaces__srv__SetDevice_Event__fini(&data[i - 1]);
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
stingray_core_interfaces__srv__SetDevice_Event__Sequence__fini(stingray_core_interfaces__srv__SetDevice_Event__Sequence * array)
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
      stingray_core_interfaces__srv__SetDevice_Event__fini(&array->data[i]);
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

stingray_core_interfaces__srv__SetDevice_Event__Sequence *
stingray_core_interfaces__srv__SetDevice_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stingray_core_interfaces__srv__SetDevice_Event__Sequence * array = (stingray_core_interfaces__srv__SetDevice_Event__Sequence *)allocator.allocate(sizeof(stingray_core_interfaces__srv__SetDevice_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = stingray_core_interfaces__srv__SetDevice_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
stingray_core_interfaces__srv__SetDevice_Event__Sequence__destroy(stingray_core_interfaces__srv__SetDevice_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    stingray_core_interfaces__srv__SetDevice_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
stingray_core_interfaces__srv__SetDevice_Event__Sequence__are_equal(const stingray_core_interfaces__srv__SetDevice_Event__Sequence * lhs, const stingray_core_interfaces__srv__SetDevice_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!stingray_core_interfaces__srv__SetDevice_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
stingray_core_interfaces__srv__SetDevice_Event__Sequence__copy(
  const stingray_core_interfaces__srv__SetDevice_Event__Sequence * input,
  stingray_core_interfaces__srv__SetDevice_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(stingray_core_interfaces__srv__SetDevice_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    stingray_core_interfaces__srv__SetDevice_Event * data =
      (stingray_core_interfaces__srv__SetDevice_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!stingray_core_interfaces__srv__SetDevice_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          stingray_core_interfaces__srv__SetDevice_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!stingray_core_interfaces__srv__SetDevice_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
