// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from stingray_core_interfaces:msg/DeviceState.idl
// generated code does not contain a copyright notice

#ifndef STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "stingray_core_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "stingray_core_interfaces/msg/detail/device_state__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace stingray_core_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_stingray_core_interfaces
cdr_serialize(
  const stingray_core_interfaces::msg::DeviceState & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_stingray_core_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  stingray_core_interfaces::msg::DeviceState & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_stingray_core_interfaces
get_serialized_size(
  const stingray_core_interfaces::msg::DeviceState & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_stingray_core_interfaces
max_serialized_size_DeviceState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace stingray_core_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_stingray_core_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, stingray_core_interfaces, msg, DeviceState)();

#ifdef __cplusplus
}
#endif

#endif  // STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
