// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from stingray_core_interfaces:msg/DeviceStateArray.idl
// generated code does not contain a copyright notice

#ifndef STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE_ARRAY__TRAITS_HPP_
#define STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "stingray_core_interfaces/msg/detail/device_state_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'states'
#include "stingray_core_interfaces/msg/detail/device_state__traits.hpp"

namespace stingray_core_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const DeviceStateArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: states
  {
    if (msg.states.size() == 0) {
      out << "states: []";
    } else {
      out << "states: [";
      size_t pending_items = msg.states.size();
      for (auto item : msg.states) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DeviceStateArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: states
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.states.size() == 0) {
      out << "states: []\n";
    } else {
      out << "states:\n";
      for (auto item : msg.states) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DeviceStateArray & msg, bool use_flow_style = false)
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
  const stingray_core_interfaces::msg::DeviceStateArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  stingray_core_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use stingray_core_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const stingray_core_interfaces::msg::DeviceStateArray & msg)
{
  return stingray_core_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<stingray_core_interfaces::msg::DeviceStateArray>()
{
  return "stingray_core_interfaces::msg::DeviceStateArray";
}

template<>
inline const char * name<stingray_core_interfaces::msg::DeviceStateArray>()
{
  return "stingray_core_interfaces/msg/DeviceStateArray";
}

template<>
struct has_fixed_size<stingray_core_interfaces::msg::DeviceStateArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<stingray_core_interfaces::msg::DeviceStateArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<stingray_core_interfaces::msg::DeviceStateArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE_ARRAY__TRAITS_HPP_
