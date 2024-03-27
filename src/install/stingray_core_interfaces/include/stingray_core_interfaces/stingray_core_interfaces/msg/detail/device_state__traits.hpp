// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from stingray_core_interfaces:msg/DeviceState.idl
// generated code does not contain a copyright notice

#ifndef STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE__TRAITS_HPP_
#define STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "stingray_core_interfaces/msg/detail/device_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace stingray_core_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const DeviceState & msg,
  std::ostream & out)
{
  out << "{";
  // member: device
  {
    out << "device: ";
    rosidl_generator_traits::value_to_yaml(msg.device, out);
    out << ", ";
  }

  // member: value
  {
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DeviceState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: device
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "device: ";
    rosidl_generator_traits::value_to_yaml(msg.device, out);
    out << "\n";
  }

  // member: value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DeviceState & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace stingray_core_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use stingray_core_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const stingray_core_interfaces::msg::DeviceState & msg,
  std::ostream & out, size_t indentation = 0)
{
  stingray_core_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use stingray_core_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const stingray_core_interfaces::msg::DeviceState & msg)
{
  return stingray_core_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<stingray_core_interfaces::msg::DeviceState>()
{
  return "stingray_core_interfaces::msg::DeviceState";
}

template<>
inline const char * name<stingray_core_interfaces::msg::DeviceState>()
{
  return "stingray_core_interfaces/msg/DeviceState";
}

template<>
struct has_fixed_size<stingray_core_interfaces::msg::DeviceState>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<stingray_core_interfaces::msg::DeviceState>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<stingray_core_interfaces::msg::DeviceState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE__TRAITS_HPP_
