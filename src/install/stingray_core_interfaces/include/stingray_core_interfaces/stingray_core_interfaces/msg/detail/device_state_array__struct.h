// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from stingray_core_interfaces:msg/DeviceStateArray.idl
// generated code does not contain a copyright notice

#ifndef STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE_ARRAY__STRUCT_H_
#define STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'states'
#include "stingray_core_interfaces/msg/detail/device_state__struct.h"

/// Struct defined in msg/DeviceStateArray in the package stingray_core_interfaces.
typedef struct stingray_core_interfaces__msg__DeviceStateArray
{
  stingray_core_interfaces__msg__DeviceState__Sequence states;
} stingray_core_interfaces__msg__DeviceStateArray;

// Struct for a sequence of stingray_core_interfaces__msg__DeviceStateArray.
typedef struct stingray_core_interfaces__msg__DeviceStateArray__Sequence
{
  stingray_core_interfaces__msg__DeviceStateArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} stingray_core_interfaces__msg__DeviceStateArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE_ARRAY__STRUCT_H_
