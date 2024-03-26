// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from stingray_core_interfaces:msg/UVState.idl
// generated code does not contain a copyright notice
#include "stingray_core_interfaces/msg/detail/uv_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
stingray_core_interfaces__msg__UVState__init(stingray_core_interfaces__msg__UVState * msg)
{
  if (!msg) {
    return false;
  }
  // roll
  // pitch
  // yaw
  // roll_speed
  // pitch_speed
  // yaw_speed
  // depth
  // depth_stabilization
  // roll_stabilization
  // pitch_stabilization
  // yaw_stabilization
  return true;
}

void
stingray_core_interfaces__msg__UVState__fini(stingray_core_interfaces__msg__UVState * msg)
{
  if (!msg) {
    return;
  }
  // roll
  // pitch
  // yaw
  // roll_speed
  // pitch_speed
  // yaw_speed
  // depth
  // depth_stabilization
  // roll_stabilization
  // pitch_stabilization
  // yaw_stabilization
}

bool
stingray_core_interfaces__msg__UVState__are_equal(const stingray_core_interfaces__msg__UVState * lhs, const stingray_core_interfaces__msg__UVState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // roll
  if (lhs->roll != rhs->roll) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  // roll_speed
  if (lhs->roll_speed != rhs->roll_speed) {
    return false;
  }
  // pitch_speed
  if (lhs->pitch_speed != rhs->pitch_speed) {
    return false;
  }
  // yaw_speed
  if (lhs->yaw_speed != rhs->yaw_speed) {
    return false;
  }
  // depth
  if (lhs->depth != rhs->depth) {
    return false;
  }
  // depth_stabilization
  if (lhs->depth_stabilization != rhs->depth_stabilization) {
    return false;
  }
  // roll_stabilization
  if (lhs->roll_stabilization != rhs->roll_stabilization) {
    return false;
  }
  // pitch_stabilization
  if (lhs->pitch_stabilization != rhs->pitch_stabilization) {
    return false;
  }
  // yaw_stabilization
  if (lhs->yaw_stabilization != rhs->yaw_stabilization) {
    return false;
  }
  return true;
}

bool
stingray_core_interfaces__msg__UVState__copy(
  const stingray_core_interfaces__msg__UVState * input,
  stingray_core_interfaces__msg__UVState * output)
{
  if (!input || !output) {
    return false;
  }
  // roll
  output->roll = input->roll;
  // pitch
  output->pitch = input->pitch;
  // yaw
  output->yaw = input->yaw;
  // roll_speed
  output->roll_speed = input->roll_speed;
  // pitch_speed
  output->pitch_speed = input->pitch_speed;
  // yaw_speed
  output->yaw_speed = input->yaw_speed;
  // depth
  output->depth = input->depth;
  // depth_stabilization
  output->depth_stabilization = input->depth_stabilization;
  // roll_stabilization
  output->roll_stabilization = input->roll_stabilization;
  // pitch_stabilization
  output->pitch_stabilization = input->pitch_stabilization;
  // yaw_stabilization
  output->yaw_stabilization = input->yaw_stabilization;
  return true;
}

stingray_core_interfaces__msg__UVState *
stingray_core_interfaces__msg__UVState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stingray_core_interfaces__msg__UVState * msg = (stingray_core_interfaces__msg__UVState *)allocator.allocate(sizeof(stingray_core_interfaces__msg__UVState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(stingray_core_interfaces__msg__UVState));
  bool success = stingray_core_interfaces__msg__UVState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
stingray_core_interfaces__msg__UVState__destroy(stingray_core_interfaces__msg__UVState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    stingray_core_interfaces__msg__UVState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
stingray_core_interfaces__msg__UVState__Sequence__init(stingray_core_interfaces__msg__UVState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stingray_core_interfaces__msg__UVState * data = NULL;

  if (size) {
    data = (stingray_core_interfaces__msg__UVState *)allocator.zero_allocate(size, sizeof(stingray_core_interfaces__msg__UVState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = stingray_core_interfaces__msg__UVState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        stingray_core_interfaces__msg__UVState__fini(&data[i - 1]);
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
stingray_core_interfaces__msg__UVState__Sequence__fini(stingray_core_interfaces__msg__UVState__Sequence * array)
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
      stingray_core_interfaces__msg__UVState__fini(&array->data[i]);
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

stingray_core_interfaces__msg__UVState__Sequence *
stingray_core_interfaces__msg__UVState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stingray_core_interfaces__msg__UVState__Sequence * array = (stingray_core_interfaces__msg__UVState__Sequence *)allocator.allocate(sizeof(stingray_core_interfaces__msg__UVState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = stingray_core_interfaces__msg__UVState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
stingray_core_interfaces__msg__UVState__Sequence__destroy(stingray_core_interfaces__msg__UVState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    stingray_core_interfaces__msg__UVState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
stingray_core_interfaces__msg__UVState__Sequence__are_equal(const stingray_core_interfaces__msg__UVState__Sequence * lhs, const stingray_core_interfaces__msg__UVState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!stingray_core_interfaces__msg__UVState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
stingray_core_interfaces__msg__UVState__Sequence__copy(
  const stingray_core_interfaces__msg__UVState__Sequence * input,
  stingray_core_interfaces__msg__UVState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(stingray_core_interfaces__msg__UVState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    stingray_core_interfaces__msg__UVState * data =
      (stingray_core_interfaces__msg__UVState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!stingray_core_interfaces__msg__UVState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          stingray_core_interfaces__msg__UVState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!stingray_core_interfaces__msg__UVState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
