// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from stingray_core_interfaces:msg/DeviceState.idl
// generated code does not contain a copyright notice

#ifndef STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE__BUILDER_HPP_
#define STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "stingray_core_interfaces/msg/detail/device_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace stingray_core_interfaces
{

namespace msg
{

namespace builder
{

class Init_DeviceState_value
{
public:
  explicit Init_DeviceState_value(::stingray_core_interfaces::msg::DeviceState & msg)
  : msg_(msg)
  {}
  ::stingray_core_interfaces::msg::DeviceState value(::stingray_core_interfaces::msg::DeviceState::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::stingray_core_interfaces::msg::DeviceState msg_;
};

class Init_DeviceState_device
{
public:
  Init_DeviceState_device()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DeviceState_value device(::stingray_core_interfaces::msg::DeviceState::_device_type arg)
  {
    msg_.device = std::move(arg);
    return Init_DeviceState_value(msg_);
  }

private:
  ::stingray_core_interfaces::msg::DeviceState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::stingray_core_interfaces::msg::DeviceState>()
{
  return stingray_core_interfaces::msg::builder::Init_DeviceState_device();
}

}  // namespace stingray_core_interfaces

#endif  // STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE__BUILDER_HPP_
