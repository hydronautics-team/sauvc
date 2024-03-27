// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from stingray_core_interfaces:msg/DeviceStateArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "stingray_core_interfaces/msg/detail/device_state_array__rosidl_typesupport_introspection_c.h"
#include "stingray_core_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "stingray_core_interfaces/msg/detail/device_state_array__functions.h"
#include "stingray_core_interfaces/msg/detail/device_state_array__struct.h"


// Include directives for member types
// Member `states`
#include "stingray_core_interfaces/msg/device_state.h"
// Member `states`
#include "stingray_core_interfaces/msg/detail/device_state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__DeviceStateArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  stingray_core_interfaces__msg__DeviceStateArray__init(message_memory);
}

void stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__DeviceStateArray_fini_function(void * message_memory)
{
  stingray_core_interfaces__msg__DeviceStateArray__fini(message_memory);
}

size_t stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__size_function__DeviceStateArray__states(
  const void * untyped_member)
{
  const stingray_core_interfaces__msg__DeviceState__Sequence * member =
    (const stingray_core_interfaces__msg__DeviceState__Sequence *)(untyped_member);
  return member->size;
}

const void * stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__get_const_function__DeviceStateArray__states(
  const void * untyped_member, size_t index)
{
  const stingray_core_interfaces__msg__DeviceState__Sequence * member =
    (const stingray_core_interfaces__msg__DeviceState__Sequence *)(untyped_member);
  return &member->data[index];
}

void * stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__get_function__DeviceStateArray__states(
  void * untyped_member, size_t index)
{
  stingray_core_interfaces__msg__DeviceState__Sequence * member =
    (stingray_core_interfaces__msg__DeviceState__Sequence *)(untyped_member);
  return &member->data[index];
}

void stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__fetch_function__DeviceStateArray__states(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const stingray_core_interfaces__msg__DeviceState * item =
    ((const stingray_core_interfaces__msg__DeviceState *)
    stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__get_const_function__DeviceStateArray__states(untyped_member, index));
  stingray_core_interfaces__msg__DeviceState * value =
    (stingray_core_interfaces__msg__DeviceState *)(untyped_value);
  *value = *item;
}

void stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__assign_function__DeviceStateArray__states(
  void * untyped_member, size_t index, const void * untyped_value)
{
  stingray_core_interfaces__msg__DeviceState * item =
    ((stingray_core_interfaces__msg__DeviceState *)
    stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__get_function__DeviceStateArray__states(untyped_member, index));
  const stingray_core_interfaces__msg__DeviceState * value =
    (const stingray_core_interfaces__msg__DeviceState *)(untyped_value);
  *item = *value;
}

bool stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__resize_function__DeviceStateArray__states(
  void * untyped_member, size_t size)
{
  stingray_core_interfaces__msg__DeviceState__Sequence * member =
    (stingray_core_interfaces__msg__DeviceState__Sequence *)(untyped_member);
  stingray_core_interfaces__msg__DeviceState__Sequence__fini(member);
  return stingray_core_interfaces__msg__DeviceState__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__DeviceStateArray_message_member_array[1] = {
  {
    "states",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stingray_core_interfaces__msg__DeviceStateArray, states),  // bytes offset in struct
    NULL,  // default value
    stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__size_function__DeviceStateArray__states,  // size() function pointer
    stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__get_const_function__DeviceStateArray__states,  // get_const(index) function pointer
    stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__get_function__DeviceStateArray__states,  // get(index) function pointer
    stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__fetch_function__DeviceStateArray__states,  // fetch(index, &value) function pointer
    stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__assign_function__DeviceStateArray__states,  // assign(index, value) function pointer
    stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__resize_function__DeviceStateArray__states  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__DeviceStateArray_message_members = {
  "stingray_core_interfaces__msg",  // message namespace
  "DeviceStateArray",  // message name
  1,  // number of fields
  sizeof(stingray_core_interfaces__msg__DeviceStateArray),
  stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__DeviceStateArray_message_member_array,  // message members
  stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__DeviceStateArray_init_function,  // function to initialize message memory (memory has to be allocated)
  stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__DeviceStateArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__DeviceStateArray_message_type_support_handle = {
  0,
  &stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__DeviceStateArray_message_members,
  get_message_typesupport_handle_function,
  &stingray_core_interfaces__msg__DeviceStateArray__get_type_hash,
  &stingray_core_interfaces__msg__DeviceStateArray__get_type_description,
  &stingray_core_interfaces__msg__DeviceStateArray__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_stingray_core_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, stingray_core_interfaces, msg, DeviceStateArray)() {
  stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__DeviceStateArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, stingray_core_interfaces, msg, DeviceState)();
  if (!stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__DeviceStateArray_message_type_support_handle.typesupport_identifier) {
    stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__DeviceStateArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &stingray_core_interfaces__msg__DeviceStateArray__rosidl_typesupport_introspection_c__DeviceStateArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
