// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from stingray_core_interfaces:msg/DeviceStateArray.idl
// generated code does not contain a copyright notice
#include "stingray_core_interfaces/msg/detail/device_state_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `states`
#include "stingray_core_interfaces/msg/detail/device_state__functions.h"

bool
stingray_core_interfaces__msg__DeviceStateArray__init(stingray_core_interfaces__msg__DeviceStateArray * msg)
{
  if (!msg) {
    return false;
  }
  // states
  if (!stingray_core_interfaces__msg__DeviceState__Sequence__init(&msg->states, 0)) {
    stingray_core_interfaces__msg__DeviceStateArray__fini(msg);
    return false;
  }
  return true;
}

void
stingray_core_interfaces__msg__DeviceStateArray__fini(stingray_core_interfaces__msg__DeviceStateArray * msg)
{
  if (!msg) {
    return;
  }
  // states
  stingray_core_interfaces__msg__DeviceState__Sequence__fini(&msg->states);
}

bool
stingray_core_interfaces__msg__DeviceStateArray__are_equal(const stingray_core_interfaces__msg__DeviceStateArray * lhs, const stingray_core_interfaces__msg__DeviceStateArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // states
  if (!stingray_core_interfaces__msg__DeviceState__Sequence__are_equal(
      &(lhs->states), &(rhs->states)))
  {
    return false;
  }
  return true;
}

bool
stingray_core_interfaces__msg__DeviceStateArray__copy(
  const stingray_core_interfaces__msg__DeviceStateArray * input,
  stingray_core_interfaces__msg__DeviceStateArray * output)
{
  if (!input || !output) {
    return false;
  }
  // states
  if (!stingray_core_interfaces__msg__DeviceState__Sequence__copy(
      &(input->states), &(output->states)))
  {
    return false;
  }
  return true;
}

stingray_core_interfaces__msg__DeviceStateArray *
stingray_core_interfaces__msg__DeviceStateArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stingray_core_interfaces__msg__DeviceStateArray * msg = (stingray_core_interfaces__msg__DeviceStateArray *)allocator.allocate(sizeof(stingray_core_interfaces__msg__DeviceStateArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(stingray_core_interfaces__msg__DeviceStateArray));
  bool success = stingray_core_interfaces__msg__DeviceStateArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
stingray_core_interfaces__msg__DeviceStateArray__destroy(stingray_core_interfaces__msg__DeviceStateArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    stingray_core_interfaces__msg__DeviceStateArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
stingray_core_interfaces__msg__DeviceStateArray__Sequence__init(stingray_core_interfaces__msg__DeviceStateArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stingray_core_interfaces__msg__DeviceStateArray * data = NULL;

  if (size) {
    data = (stingray_core_interfaces__msg__DeviceStateArray *)allocator.zero_allocate(size, sizeof(stingray_core_interfaces__msg__DeviceStateArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = stingray_core_interfaces__msg__DeviceStateArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        stingray_core_interfaces__msg__DeviceStateArray__fini(&data[i - 1]);
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
stingray_core_interfaces__msg__DeviceStateArray__Sequence__fini(stingray_core_interfaces__msg__DeviceStateArray__Sequence * array)
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
      stingray_core_interfaces__msg__DeviceStateArray__fini(&array->data[i]);
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

stingray_core_interfaces__msg__DeviceStateArray__Sequence *
stingray_core_interfaces__msg__DeviceStateArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stingray_core_interfaces__msg__DeviceStateArray__Sequence * array = (stingray_core_interfaces__msg__DeviceStateArray__Sequence *)allocator.allocate(sizeof(stingray_core_interfaces__msg__DeviceStateArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = stingray_core_interfaces__msg__DeviceStateArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
stingray_core_interfaces__msg__DeviceStateArray__Sequence__destroy(stingray_core_interfaces__msg__DeviceStateArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    stingray_core_interfaces__msg__DeviceStateArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
stingray_core_interfaces__msg__DeviceStateArray__Sequence__are_equal(const stingray_core_interfaces__msg__DeviceStateArray__Sequence * lhs, const stingray_core_interfaces__msg__DeviceStateArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!stingray_core_interfaces__msg__DeviceStateArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
stingray_core_interfaces__msg__DeviceStateArray__Sequence__copy(
  const stingray_core_interfaces__msg__DeviceStateArray__Sequence * input,
  stingray_core_interfaces__msg__DeviceStateArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(stingray_core_interfaces__msg__DeviceStateArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    stingray_core_interfaces__msg__DeviceStateArray * data =
      (stingray_core_interfaces__msg__DeviceStateArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!stingray_core_interfaces__msg__DeviceStateArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          stingray_core_interfaces__msg__DeviceStateArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!stingray_core_interfaces__msg__DeviceStateArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
