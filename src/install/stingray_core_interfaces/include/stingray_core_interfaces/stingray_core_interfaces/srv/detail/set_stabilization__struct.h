// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from stingray_core_interfaces:srv/SetStabilization.idl
// generated code does not contain a copyright notice

#ifndef STINGRAY_CORE_INTERFACES__SRV__DETAIL__SET_STABILIZATION__STRUCT_H_
#define STINGRAY_CORE_INTERFACES__SRV__DETAIL__SET_STABILIZATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetStabilization in the package stingray_core_interfaces.
typedef struct stingray_core_interfaces__srv__SetStabilization_Request
{
  bool depth_stabilization;
  bool roll_stabilization;
  bool pitch_stabilization;
  bool yaw_stabilization;
} stingray_core_interfaces__srv__SetStabilization_Request;

// Struct for a sequence of stingray_core_interfaces__srv__SetStabilization_Request.
typedef struct stingray_core_interfaces__srv__SetStabilization_Request__Sequence
{
  stingray_core_interfaces__srv__SetStabilization_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} stingray_core_interfaces__srv__SetStabilization_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetStabilization in the package stingray_core_interfaces.
typedef struct stingray_core_interfaces__srv__SetStabilization_Response
{
  bool success;
  rosidl_runtime_c__String message;
} stingray_core_interfaces__srv__SetStabilization_Response;

// Struct for a sequence of stingray_core_interfaces__srv__SetStabilization_Response.
typedef struct stingray_core_interfaces__srv__SetStabilization_Response__Sequence
{
  stingray_core_interfaces__srv__SetStabilization_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} stingray_core_interfaces__srv__SetStabilization_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  stingray_core_interfaces__srv__SetStabilization_Event__request__MAX_SIZE = 1
};
// response
enum
{
  stingray_core_interfaces__srv__SetStabilization_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/SetStabilization in the package stingray_core_interfaces.
typedef struct stingray_core_interfaces__srv__SetStabilization_Event
{
  service_msgs__msg__ServiceEventInfo info;
  stingray_core_interfaces__srv__SetStabilization_Request__Sequence request;
  stingray_core_interfaces__srv__SetStabilization_Response__Sequence response;
} stingray_core_interfaces__srv__SetStabilization_Event;

// Struct for a sequence of stingray_core_interfaces__srv__SetStabilization_Event.
typedef struct stingray_core_interfaces__srv__SetStabilization_Event__Sequence
{
  stingray_core_interfaces__srv__SetStabilization_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} stingray_core_interfaces__srv__SetStabilization_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // STINGRAY_CORE_INTERFACES__SRV__DETAIL__SET_STABILIZATION__STRUCT_H_
