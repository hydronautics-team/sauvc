// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from stingray_core_interfaces:srv/SetTwist.idl
// generated code does not contain a copyright notice

#ifndef STINGRAY_CORE_INTERFACES__SRV__DETAIL__SET_TWIST__TRAITS_HPP_
#define STINGRAY_CORE_INTERFACES__SRV__DETAIL__SET_TWIST__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "stingray_core_interfaces/srv/detail/set_twist__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace stingray_core_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetTwist_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: surge
  {
    out << "surge: ";
    rosidl_generator_traits::value_to_yaml(msg.surge, out);
    out << ", ";
  }

  // member: sway
  {
    out << "sway: ";
    rosidl_generator_traits::value_to_yaml(msg.sway, out);
    out << ", ";
  }

  // member: depth
  {
    out << "depth: ";
    rosidl_generator_traits::value_to_yaml(msg.depth, out);
    out << ", ";
  }

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
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetTwist_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: surge
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "surge: ";
    rosidl_generator_traits::value_to_yaml(msg.surge, out);
    out << "\n";
  }

  // member: sway
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sway: ";
    rosidl_generator_traits::value_to_yaml(msg.sway, out);
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetTwist_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace stingray_core_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use stingray_core_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const stingray_core_interfaces::srv::SetTwist_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  stingray_core_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use stingray_core_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const stingray_core_interfaces::srv::SetTwist_Request & msg)
{
  return stingray_core_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<stingray_core_interfaces::srv::SetTwist_Request>()
{
  return "stingray_core_interfaces::srv::SetTwist_Request";
}

template<>
inline const char * name<stingray_core_interfaces::srv::SetTwist_Request>()
{
  return "stingray_core_interfaces/srv/SetTwist_Request";
}

template<>
struct has_fixed_size<stingray_core_interfaces::srv::SetTwist_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<stingray_core_interfaces::srv::SetTwist_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<stingray_core_interfaces::srv::SetTwist_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace stingray_core_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetTwist_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetTwist_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetTwist_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace stingray_core_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use stingray_core_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const stingray_core_interfaces::srv::SetTwist_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  stingray_core_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use stingray_core_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const stingray_core_interfaces::srv::SetTwist_Response & msg)
{
  return stingray_core_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<stingray_core_interfaces::srv::SetTwist_Response>()
{
  return "stingray_core_interfaces::srv::SetTwist_Response";
}

template<>
inline const char * name<stingray_core_interfaces::srv::SetTwist_Response>()
{
  return "stingray_core_interfaces/srv/SetTwist_Response";
}

template<>
struct has_fixed_size<stingray_core_interfaces::srv::SetTwist_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<stingray_core_interfaces::srv::SetTwist_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<stingray_core_interfaces::srv::SetTwist_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace stingray_core_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetTwist_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
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
  const SetTwist_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetTwist_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace stingray_core_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use stingray_core_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const stingray_core_interfaces::srv::SetTwist_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  stingray_core_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use stingray_core_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const stingray_core_interfaces::srv::SetTwist_Event & msg)
{
  return stingray_core_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<stingray_core_interfaces::srv::SetTwist_Event>()
{
  return "stingray_core_interfaces::srv::SetTwist_Event";
}

template<>
inline const char * name<stingray_core_interfaces::srv::SetTwist_Event>()
{
  return "stingray_core_interfaces/srv/SetTwist_Event";
}

template<>
struct has_fixed_size<stingray_core_interfaces::srv::SetTwist_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<stingray_core_interfaces::srv::SetTwist_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<stingray_core_interfaces::srv::SetTwist_Request>::value && has_bounded_size<stingray_core_interfaces::srv::SetTwist_Response>::value> {};

template<>
struct is_message<stingray_core_interfaces::srv::SetTwist_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<stingray_core_interfaces::srv::SetTwist>()
{
  return "stingray_core_interfaces::srv::SetTwist";
}

template<>
inline const char * name<stingray_core_interfaces::srv::SetTwist>()
{
  return "stingray_core_interfaces/srv/SetTwist";
}

template<>
struct has_fixed_size<stingray_core_interfaces::srv::SetTwist>
  : std::integral_constant<
    bool,
    has_fixed_size<stingray_core_interfaces::srv::SetTwist_Request>::value &&
    has_fixed_size<stingray_core_interfaces::srv::SetTwist_Response>::value
  >
{
};

template<>
struct has_bounded_size<stingray_core_interfaces::srv::SetTwist>
  : std::integral_constant<
    bool,
    has_bounded_size<stingray_core_interfaces::srv::SetTwist_Request>::value &&
    has_bounded_size<stingray_core_interfaces::srv::SetTwist_Response>::value
  >
{
};

template<>
struct is_service<stingray_core_interfaces::srv::SetTwist>
  : std::true_type
{
};

template<>
struct is_service_request<stingray_core_interfaces::srv::SetTwist_Request>
  : std::true_type
{
};

template<>
struct is_service_response<stingray_core_interfaces::srv::SetTwist_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // STINGRAY_CORE_INTERFACES__SRV__DETAIL__SET_TWIST__TRAITS_HPP_
