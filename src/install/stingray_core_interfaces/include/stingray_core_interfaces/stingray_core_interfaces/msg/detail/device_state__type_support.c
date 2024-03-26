// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from stingray_core_interfaces:msg/DeviceState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "stingray_core_interfaces/msg/detail/device_state__rosidl_typesupport_introspection_c.h"
#include "stingray_core_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "stingray_core_interfaces/msg/detail/device_state__functions.h"
#include "stingray_core_interfaces/msg/detail/device_state__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void stingray_core_interfaces__msg__DeviceState__rosidl_typesupport_introspection_c__DeviceState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  stingray_core_interfaces__msg__DeviceState__init(message_memory);
}

void stingray_core_interfaces__msg__DeviceState__rosidl_typesupport_introspection_c__DeviceState_fini_function(void * message_memory)
{
  stingray_core_interfaces__msg__DeviceState__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember stingray_core_interfaces__msg__DeviceState__rosidl_typesupport_introspection_c__DeviceState_message_member_array[2] = {
  {
    "device",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stingray_core_interfaces__msg__DeviceState, device),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "value",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stingray_core_interfaces__msg__DeviceState, value),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers stingray_core_interfaces__msg__DeviceState__rosidl_typesupport_introspection_c__DeviceState_message_members = {
  "stingray_core_interfaces__msg",  // message namespace
  "DeviceState",  // message name
  2,  // number of fields
  sizeof(stingray_core_interfaces__msg__DeviceState),
  stingray_core_interfaces__msg__DeviceState__rosidl_typesupport_introspection_c__DeviceState_message_member_array,  // message members
  stingray_core_interfaces__msg__DeviceState__rosidl_typesupport_introspection_c__DeviceState_init_function,  // function to initialize message memory (memory has to be allocated)
  stingray_core_interfaces__msg__DeviceState__rosidl_typesupport_introspection_c__DeviceState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t stingray_core_interfaces__msg__DeviceState__rosidl_typesupport_introspection_c__DeviceState_message_type_support_handle = {
  0,
  &stingray_core_interfaces__msg__DeviceState__rosidl_typesupport_introspection_c__DeviceState_message_members,
  get_message_typesupport_handle_function,
  &stingray_core_interfaces__msg__DeviceState__get_type_hash,
  &stingray_core_interfaces__msg__DeviceState__get_type_description,
  &stingray_core_interfaces__msg__DeviceState__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_stingray_core_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, stingray_core_interfaces, msg, DeviceState)() {
  if (!stingray_core_interfaces__msg__DeviceState__rosidl_typesupport_introspection_c__DeviceState_message_type_support_handle.typesupport_identifier) {
    stingray_core_interfaces__msg__DeviceState__rosidl_typesupport_introspection_c__DeviceState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &stingray_core_interfaces__msg__DeviceState__rosidl_typesupport_introspection_c__DeviceState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
