// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from stingray_core_interfaces:msg/UVState.idl
// generated code does not contain a copyright notice

#ifndef STINGRAY_CORE_INTERFACES__MSG__DETAIL__UV_STATE__TRAITS_HPP_
#define STINGRAY_CORE_INTERFACES__MSG__DETAIL__UV_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "stingray_core_interfaces/msg/detail/uv_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace stingray_core_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const UVState & msg,
  std::ostream & out)
{
  out << "{";
  // member: roll
  {
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << ", ";
  }

  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << ", ";
  }

  // member: roll_speed
  {
    out << "roll_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.roll_speed, out);
    out << ", ";
  }

  // member: pitch_speed
  {
    out << "pitch_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_speed, out);
    out << ", ";
  }

  // member: yaw_speed
  {
    out << "yaw_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_speed, out);
    out << ", ";
  }

  // member: depth
  {
    out << "depth: ";
    rosidl_generator_traits::value_to_yaml(msg.depth, out);
    out << ", ";
  }

  // member: depth_stabilization
  {
    out << "depth_stabilization: ";
    rosidl_generator_traits::value_to_yaml(msg.depth_stabilization, out);
    out << ", ";
  }

  // member: roll_stabilization
  {
    out << "roll_stabilization: ";
    rosidl_generator_traits::value_to_yaml(msg.roll_stabilization, out);
    out << ", ";
  }

  // member: pitch_stabilization
  {
    out << "pitch_stabilization: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_stabilization, out);
    out << ", ";
  }

  // member: yaw_stabilization
  {
    out << "yaw_stabilization: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_stabilization, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UVState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << "\n";
  }

  // member: pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << "\n";
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }

  // member: roll_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.roll_speed, out);
    out << "\n";
  }

  // member: pitch_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_speed, out);
    out << "\n";
  }

  // member: yaw_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_speed, out);
    out << "\n";
  }

  // member: depth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "depth: ";
    rosidl_generator_traits::value_to_yaml(msg.depth, out);
    out << "\n";
  }

  // member: depth_stabilization
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "depth_stabilization: ";
    rosidl_generator_traits::value_to_yaml(msg.depth_stabilization, out);
    out << "\n";
  }

  // member: roll_stabilization
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll_stabilization: ";
    rosidl_generator_traits::value_to_yaml(msg.roll_stabilization, out);
    out << "\n";
  }

  // member: pitch_stabilization
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch_stabilization: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_stabilization, out);
    out << "\n";
  }

  // member: yaw_stabilization
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_stabilization: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_stabilization, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UVState & msg, bool use_flow_style = false)
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
  const stingray_core_interfaces::msg::UVState & msg,
  std::ostream & out, size_t indentation = 0)
{
  stingray_core_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use stingray_core_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const stingray_core_interfaces::msg::UVState & msg)
{
  return stingray_core_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<stingray_core_interfaces::msg::UVState>()
{
  return "stingray_core_interfaces::msg::UVState";
}

template<>
inline const char * name<stingray_core_interfaces::msg::UVState>()
{
  return "stingray_core_interfaces/msg/UVState";
}

template<>
struct has_fixed_size<stingray_core_interfaces::msg::UVState>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<stingray_core_interfaces::msg::UVState>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<stingray_core_interfaces::msg::UVState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // STINGRAY_CORE_INTERFACES__MSG__DETAIL__UV_STATE__TRAITS_HPP_
