// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from stingray_core_interfaces:srv/SetStabilization.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "stingray_core_interfaces/srv/detail/set_stabilization__rosidl_typesupport_introspection_c.h"
#include "stingray_core_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "stingray_core_interfaces/srv/detail/set_stabilization__functions.h"
#include "stingray_core_interfaces/srv/detail/set_stabilization__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void stingray_core_interfaces__srv__SetStabilization_Request__rosidl_typesupport_introspection_c__SetStabilization_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  stingray_core_interfaces__srv__SetStabilization_Request__init(message_memory);
}

void stingray_core_interfaces__srv__SetStabilization_Request__rosidl_typesupport_introspection_c__SetStabilization_Request_fini_function(void * message_memory)
{
  stingray_core_interfaces__srv__SetStabilization_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember stingray_core_interfaces__srv__SetStabilization_Request__rosidl_typesupport_introspection_c__SetStabilization_Request_message_member_array[4] = {
  {
    "depth_stabilization",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stingray_core_interfaces__srv__SetStabilization_Request, depth_stabilization),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "roll_stabilization",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stingray_core_interfaces__srv__SetStabilization_Request, roll_stabilization),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pitch_stabilization",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stingray_core_interfaces__srv__SetStabilization_Request, pitch_stabilization),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "yaw_stabilization",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stingray_core_interfaces__srv__SetStabilization_Request, yaw_stabilization),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers stingray_core_interfaces__srv__SetStabilization_Request__rosidl_typesupport_introspection_c__SetStabilization_Request_message_members = {
  "stingray_core_interfaces__srv",  // message namespace
  "SetStabilization_Request",  // message name
  4,  // number of fields
  sizeof(stingray_core_interfaces__srv__SetStabilization_Request),
  stingray_core_interfaces__srv__SetStabilization_Request__rosidl_typesupport_introspection_c__SetStabilization_Request_message_member_array,  // message members
  stingray_core_interfaces__srv__SetStabilization_Request__rosidl_typesupport_introspection_c__SetStabilization_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  stingray_core_interfaces__srv__SetStabilization_Request__rosidl_typesupport_introspection_c__SetStabilization_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t stingray_core_interfaces__srv__SetStabilization_Request__rosidl_typesupport_introspection_c__SetStabilization_Request_message_type_support_handle = {
  0,
  &stingray_core_interfaces__srv__SetStabilization_Request__rosidl_typesupport_introspection_c__SetStabilization_Request_message_members,
  get_message_typesupport_handle_function,
  &stingray_core_interfaces__srv__SetStabilization_Request__get_type_hash,
  &stingray_core_interfaces__srv__SetStabilization_Request__get_type_description,
  &stingray_core_interfaces__srv__SetStabilization_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_stingray_core_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, stingray_core_interfaces, srv, SetStabilization_Request)() {
  if (!stingray_core_interfaces__srv__SetStabilization_Request__rosidl_typesupport_introspection_c__SetStabilization_Request_message_type_support_handle.typesupport_identifier) {
    stingray_core_interfaces__srv__SetStabilization_Request__rosidl_typesupport_introspection_c__SetStabilization_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &stingray_core_interfaces__srv__SetStabilization_Request__rosidl_typesupport_introspection_c__SetStabilization_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "stingray_core_interfaces/srv/detail/set_stabilization__rosidl_typesupport_introspection_c.h"
// already included above
// #include "stingray_core_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "stingray_core_interfaces/srv/detail/set_stabilization__functions.h"
// already included above
// #include "stingray_core_interfaces/srv/detail/set_stabilization__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void stingray_core_interfaces__srv__SetStabilization_Response__rosidl_typesupport_introspection_c__SetStabilization_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  stingray_core_interfaces__srv__SetStabilization_Response__init(message_memory);
}

void stingray_core_interfaces__srv__SetStabilization_Response__rosidl_typesupport_introspection_c__SetStabilization_Response_fini_function(void * message_memory)
{
  stingray_core_interfaces__srv__SetStabilization_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember stingray_core_interfaces__srv__SetStabilization_Response__rosidl_typesupport_introspection_c__SetStabilization_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stingray_core_interfaces__srv__SetStabilization_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stingray_core_interfaces__srv__SetStabilization_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers stingray_core_interfaces__srv__SetStabilization_Response__rosidl_typesupport_introspection_c__SetStabilization_Response_message_members = {
  "stingray_core_interfaces__srv",  // message namespace
  "SetStabilization_Response",  // message name
  2,  // number of fields
  sizeof(stingray_core_interfaces__srv__SetStabilization_Response),
  stingray_core_interfaces__srv__SetStabilization_Response__rosidl_typesupport_introspection_c__SetStabilization_Response_message_member_array,  // message members
  stingray_core_interfaces__srv__SetStabilization_Response__rosidl_typesupport_introspection_c__SetStabilization_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  stingray_core_interfaces__srv__SetStabilization_Response__rosidl_typesupport_introspection_c__SetStabilization_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t stingray_core_interfaces__srv__SetStabilization_Response__rosidl_typesupport_introspection_c__SetStabilization_Response_message_type_support_handle = {
  0,
  &stingray_core_interfaces__srv__SetStabilization_Response__rosidl_typesupport_introspection_c__SetStabilization_Response_message_members,
  get_message_typesupport_handle_function,
  &stingray_core_interfaces__srv__SetStabilization_Response__get_type_hash,
  &stingray_core_interfaces__srv__SetStabilization_Response__get_type_description,
  &stingray_core_interfaces__srv__SetStabilization_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_stingray_core_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, stingray_core_interfaces, srv, SetStabilization_Response)() {
  if (!stingray_core_interfaces__srv__SetStabilization_Response__rosidl_typesupport_introspection_c__SetStabilization_Response_message_type_support_handle.typesupport_identifier) {
    stingray_core_interfaces__srv__SetStabilization_Response__rosidl_typesupport_introspection_c__SetStabilization_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &stingray_core_interfaces__srv__SetStabilization_Response__rosidl_typesupport_introspection_c__SetStabilization_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "stingray_core_interfaces/srv/detail/set_stabilization__rosidl_typesupport_introspection_c.h"
// already included above
// #include "stingray_core_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "stingray_core_interfaces/srv/detail/set_stabilization__functions.h"
// already included above
// #include "stingray_core_interfaces/srv/detail/set_stabilization__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "stingray_core_interfaces/srv/set_stabilization.h"
// Member `request`
// Member `response`
// already included above
// #include "stingray_core_interfaces/srv/detail/set_stabilization__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__SetStabilization_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  stingray_core_interfaces__srv__SetStabilization_Event__init(message_memory);
}

void stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__SetStabilization_Event_fini_function(void * message_memory)
{
  stingray_core_interfaces__srv__SetStabilization_Event__fini(message_memory);
}

size_t stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__size_function__SetStabilization_Event__request(
  const void * untyped_member)
{
  const stingray_core_interfaces__srv__SetStabilization_Request__Sequence * member =
    (const stingray_core_interfaces__srv__SetStabilization_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__get_const_function__SetStabilization_Event__request(
  const void * untyped_member, size_t index)
{
  const stingray_core_interfaces__srv__SetStabilization_Request__Sequence * member =
    (const stingray_core_interfaces__srv__SetStabilization_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__get_function__SetStabilization_Event__request(
  void * untyped_member, size_t index)
{
  stingray_core_interfaces__srv__SetStabilization_Request__Sequence * member =
    (stingray_core_interfaces__srv__SetStabilization_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__fetch_function__SetStabilization_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const stingray_core_interfaces__srv__SetStabilization_Request * item =
    ((const stingray_core_interfaces__srv__SetStabilization_Request *)
    stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__get_const_function__SetStabilization_Event__request(untyped_member, index));
  stingray_core_interfaces__srv__SetStabilization_Request * value =
    (stingray_core_interfaces__srv__SetStabilization_Request *)(untyped_value);
  *value = *item;
}

void stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__assign_function__SetStabilization_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  stingray_core_interfaces__srv__SetStabilization_Request * item =
    ((stingray_core_interfaces__srv__SetStabilization_Request *)
    stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__get_function__SetStabilization_Event__request(untyped_member, index));
  const stingray_core_interfaces__srv__SetStabilization_Request * value =
    (const stingray_core_interfaces__srv__SetStabilization_Request *)(untyped_value);
  *item = *value;
}

bool stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__resize_function__SetStabilization_Event__request(
  void * untyped_member, size_t size)
{
  stingray_core_interfaces__srv__SetStabilization_Request__Sequence * member =
    (stingray_core_interfaces__srv__SetStabilization_Request__Sequence *)(untyped_member);
  stingray_core_interfaces__srv__SetStabilization_Request__Sequence__fini(member);
  return stingray_core_interfaces__srv__SetStabilization_Request__Sequence__init(member, size);
}

size_t stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__size_function__SetStabilization_Event__response(
  const void * untyped_member)
{
  const stingray_core_interfaces__srv__SetStabilization_Response__Sequence * member =
    (const stingray_core_interfaces__srv__SetStabilization_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__get_const_function__SetStabilization_Event__response(
  const void * untyped_member, size_t index)
{
  const stingray_core_interfaces__srv__SetStabilization_Response__Sequence * member =
    (const stingray_core_interfaces__srv__SetStabilization_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__get_function__SetStabilization_Event__response(
  void * untyped_member, size_t index)
{
  stingray_core_interfaces__srv__SetStabilization_Response__Sequence * member =
    (stingray_core_interfaces__srv__SetStabilization_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__fetch_function__SetStabilization_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const stingray_core_interfaces__srv__SetStabilization_Response * item =
    ((const stingray_core_interfaces__srv__SetStabilization_Response *)
    stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__get_const_function__SetStabilization_Event__response(untyped_member, index));
  stingray_core_interfaces__srv__SetStabilization_Response * value =
    (stingray_core_interfaces__srv__SetStabilization_Response *)(untyped_value);
  *value = *item;
}

void stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__assign_function__SetStabilization_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  stingray_core_interfaces__srv__SetStabilization_Response * item =
    ((stingray_core_interfaces__srv__SetStabilization_Response *)
    stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__get_function__SetStabilization_Event__response(untyped_member, index));
  const stingray_core_interfaces__srv__SetStabilization_Response * value =
    (const stingray_core_interfaces__srv__SetStabilization_Response *)(untyped_value);
  *item = *value;
}

bool stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__resize_function__SetStabilization_Event__response(
  void * untyped_member, size_t size)
{
  stingray_core_interfaces__srv__SetStabilization_Response__Sequence * member =
    (stingray_core_interfaces__srv__SetStabilization_Response__Sequence *)(untyped_member);
  stingray_core_interfaces__srv__SetStabilization_Response__Sequence__fini(member);
  return stingray_core_interfaces__srv__SetStabilization_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__SetStabilization_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stingray_core_interfaces__srv__SetStabilization_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(stingray_core_interfaces__srv__SetStabilization_Event, request),  // bytes offset in struct
    NULL,  // default value
    stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__size_function__SetStabilization_Event__request,  // size() function pointer
    stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__get_const_function__SetStabilization_Event__request,  // get_const(index) function pointer
    stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__get_function__SetStabilization_Event__request,  // get(index) function pointer
    stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__fetch_function__SetStabilization_Event__request,  // fetch(index, &value) function pointer
    stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__assign_function__SetStabilization_Event__request,  // assign(index, value) function pointer
    stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__resize_function__SetStabilization_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(stingray_core_interfaces__srv__SetStabilization_Event, response),  // bytes offset in struct
    NULL,  // default value
    stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__size_function__SetStabilization_Event__response,  // size() function pointer
    stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__get_const_function__SetStabilization_Event__response,  // get_const(index) function pointer
    stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__get_function__SetStabilization_Event__response,  // get(index) function pointer
    stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__fetch_function__SetStabilization_Event__response,  // fetch(index, &value) function pointer
    stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__assign_function__SetStabilization_Event__response,  // assign(index, value) function pointer
    stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__resize_function__SetStabilization_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__SetStabilization_Event_message_members = {
  "stingray_core_interfaces__srv",  // message namespace
  "SetStabilization_Event",  // message name
  3,  // number of fields
  sizeof(stingray_core_interfaces__srv__SetStabilization_Event),
  stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__SetStabilization_Event_message_member_array,  // message members
  stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__SetStabilization_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__SetStabilization_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__SetStabilization_Event_message_type_support_handle = {
  0,
  &stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__SetStabilization_Event_message_members,
  get_message_typesupport_handle_function,
  &stingray_core_interfaces__srv__SetStabilization_Event__get_type_hash,
  &stingray_core_interfaces__srv__SetStabilization_Event__get_type_description,
  &stingray_core_interfaces__srv__SetStabilization_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_stingray_core_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, stingray_core_interfaces, srv, SetStabilization_Event)() {
  stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__SetStabilization_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__SetStabilization_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, stingray_core_interfaces, srv, SetStabilization_Request)();
  stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__SetStabilization_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, stingray_core_interfaces, srv, SetStabilization_Response)();
  if (!stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__SetStabilization_Event_message_type_support_handle.typesupport_identifier) {
    stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__SetStabilization_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__SetStabilization_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "stingray_core_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "stingray_core_interfaces/srv/detail/set_stabilization__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers stingray_core_interfaces__srv__detail__set_stabilization__rosidl_typesupport_introspection_c__SetStabilization_service_members = {
  "stingray_core_interfaces__srv",  // service namespace
  "SetStabilization",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // stingray_core_interfaces__srv__detail__set_stabilization__rosidl_typesupport_introspection_c__SetStabilization_Request_message_type_support_handle,
  NULL,  // response message
  // stingray_core_interfaces__srv__detail__set_stabilization__rosidl_typesupport_introspection_c__SetStabilization_Response_message_type_support_handle
  NULL  // event_message
  // stingray_core_interfaces__srv__detail__set_stabilization__rosidl_typesupport_introspection_c__SetStabilization_Response_message_type_support_handle
};


static rosidl_service_type_support_t stingray_core_interfaces__srv__detail__set_stabilization__rosidl_typesupport_introspection_c__SetStabilization_service_type_support_handle = {
  0,
  &stingray_core_interfaces__srv__detail__set_stabilization__rosidl_typesupport_introspection_c__SetStabilization_service_members,
  get_service_typesupport_handle_function,
  &stingray_core_interfaces__srv__SetStabilization_Request__rosidl_typesupport_introspection_c__SetStabilization_Request_message_type_support_handle,
  &stingray_core_interfaces__srv__SetStabilization_Response__rosidl_typesupport_introspection_c__SetStabilization_Response_message_type_support_handle,
  &stingray_core_interfaces__srv__SetStabilization_Event__rosidl_typesupport_introspection_c__SetStabilization_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    stingray_core_interfaces,
    srv,
    SetStabilization
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    stingray_core_interfaces,
    srv,
    SetStabilization
  ),
  &stingray_core_interfaces__srv__SetStabilization__get_type_hash,
  &stingray_core_interfaces__srv__SetStabilization__get_type_description,
  &stingray_core_interfaces__srv__SetStabilization__get_type_description_sources,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, stingray_core_interfaces, srv, SetStabilization_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, stingray_core_interfaces, srv, SetStabilization_Response)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, stingray_core_interfaces, srv, SetStabilization_Event)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_stingray_core_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, stingray_core_interfaces, srv, SetStabilization)() {
  if (!stingray_core_interfaces__srv__detail__set_stabilization__rosidl_typesupport_introspection_c__SetStabilization_service_type_support_handle.typesupport_identifier) {
    stingray_core_interfaces__srv__detail__set_stabilization__rosidl_typesupport_introspection_c__SetStabilization_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)stingray_core_interfaces__srv__detail__set_stabilization__rosidl_typesupport_introspection_c__SetStabilization_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, stingray_core_interfaces, srv, SetStabilization_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, stingray_core_interfaces, srv, SetStabilization_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, stingray_core_interfaces, srv, SetStabilization_Event)()->data;
  }

  return &stingray_core_interfaces__srv__detail__set_stabilization__rosidl_typesupport_introspection_c__SetStabilization_service_type_support_handle;
}
