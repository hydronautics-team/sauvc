// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from stingray_core_interfaces:msg/DeviceState.idl
// generated code does not contain a copyright notice

#ifndef STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE__STRUCT_H_
#define STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/DeviceState in the package stingray_core_interfaces.
typedef struct stingray_core_interfaces__msg__DeviceState
{
  uint8_t device;
  int32_t value;
} stingray_core_interfaces__msg__DeviceState;

// Struct for a sequence of stingray_core_interfaces__msg__DeviceState.
typedef struct stingray_core_interfaces__msg__DeviceState__Sequence
{
  stingray_core_interfaces__msg__DeviceState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} stingray_core_interfaces__msg__DeviceState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE__STRUCT_H_
