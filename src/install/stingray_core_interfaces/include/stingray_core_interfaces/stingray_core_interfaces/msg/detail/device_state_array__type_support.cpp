// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from stingray_core_interfaces:msg/DeviceStateArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "stingray_core_interfaces/msg/detail/device_state_array__functions.h"
#include "stingray_core_interfaces/msg/detail/device_state_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace stingray_core_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void DeviceStateArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) stingray_core_interfaces::msg::DeviceStateArray(_init);
}

void DeviceStateArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<stingray_core_interfaces::msg::DeviceStateArray *>(message_memory);
  typed_message->~DeviceStateArray();
}

size_t size_function__DeviceStateArray__states(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<stingray_core_interfaces::msg::DeviceState> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DeviceStateArray__states(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<stingray_core_interfaces::msg::DeviceState> *>(untyped_member);
  return &member[index];
}

void * get_function__DeviceStateArray__states(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<stingray_core_interfaces::msg::DeviceState> *>(untyped_member);
  return &member[index];
}

void fetch_function__DeviceStateArray__states(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const stingray_core_interfaces::msg::DeviceState *>(
    get_const_function__DeviceStateArray__states(untyped_member, index));
  auto & value = *reinterpret_cast<stingray_core_interfaces::msg::DeviceState *>(untyped_value);
  value = item;
}

void assign_function__DeviceStateArray__states(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<stingray_core_interfaces::msg::DeviceState *>(
    get_function__DeviceStateArray__states(untyped_member, index));
  const auto & value = *reinterpret_cast<const stingray_core_interfaces::msg::DeviceState *>(untyped_value);
  item = value;
}

void resize_function__DeviceStateArray__states(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<stingray_core_interfaces::msg::DeviceState> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DeviceStateArray_message_member_array[1] = {
  {
    "states",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<stingray_core_interfaces::msg::DeviceState>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stingray_core_interfaces::msg::DeviceStateArray, states),  // bytes offset in struct
    nullptr,  // default value
    size_function__DeviceStateArray__states,  // size() function pointer
    get_const_function__DeviceStateArray__states,  // get_const(index) function pointer
    get_function__DeviceStateArray__states,  // get(index) function pointer
    fetch_function__DeviceStateArray__states,  // fetch(index, &value) function pointer
    assign_function__DeviceStateArray__states,  // assign(index, value) function pointer
    resize_function__DeviceStateArray__states  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DeviceStateArray_message_members = {
  "stingray_core_interfaces::msg",  // message namespace
  "DeviceStateArray",  // message name
  1,  // number of fields
  sizeof(stingray_core_interfaces::msg::DeviceStateArray),
  DeviceStateArray_message_member_array,  // message members
  DeviceStateArray_init_function,  // function to initialize message memory (memory has to be allocated)
  DeviceStateArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DeviceStateArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DeviceStateArray_message_members,
  get_message_typesupport_handle_function,
  &stingray_core_interfaces__msg__DeviceStateArray__get_type_hash,
  &stingray_core_interfaces__msg__DeviceStateArray__get_type_description,
  &stingray_core_interfaces__msg__DeviceStateArray__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace stingray_core_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<stingray_core_interfaces::msg::DeviceStateArray>()
{
  return &::stingray_core_interfaces::msg::rosidl_typesupport_introspection_cpp::DeviceStateArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, stingray_core_interfaces, msg, DeviceStateArray)() {
  return &::stingray_core_interfaces::msg::rosidl_typesupport_introspection_cpp::DeviceStateArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
