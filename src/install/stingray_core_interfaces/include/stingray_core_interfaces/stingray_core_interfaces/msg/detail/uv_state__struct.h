// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from stingray_core_interfaces:msg/UVState.idl
// generated code does not contain a copyright notice

#ifndef STINGRAY_CORE_INTERFACES__MSG__DETAIL__UV_STATE__STRUCT_H_
#define STINGRAY_CORE_INTERFACES__MSG__DETAIL__UV_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/UVState in the package stingray_core_interfaces.
typedef struct stingray_core_interfaces__msg__UVState
{
  float roll;
  float pitch;
  float yaw;
  float roll_speed;
  float pitch_speed;
  float yaw_speed;
  float depth;
  bool depth_stabilization;
  bool roll_stabilization;
  bool pitch_stabilization;
  bool yaw_stabilization;
} stingray_core_interfaces__msg__UVState;

// Struct for a sequence of stingray_core_interfaces__msg__UVState.
typedef struct stingray_core_interfaces__msg__UVState__Sequence
{
  stingray_core_interfaces__msg__UVState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} stingray_core_interfaces__msg__UVState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // STINGRAY_CORE_INTERFACES__MSG__DETAIL__UV_STATE__STRUCT_H_
