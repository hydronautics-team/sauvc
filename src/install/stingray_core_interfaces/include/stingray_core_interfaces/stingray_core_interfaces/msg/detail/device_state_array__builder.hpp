// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from stingray_core_interfaces:msg/DeviceStateArray.idl
// generated code does not contain a copyright notice

#ifndef STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE_ARRAY__BUILDER_HPP_
#define STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "stingray_core_interfaces/msg/detail/device_state_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace stingray_core_interfaces
{

namespace msg
{

namespace builder
{

class Init_DeviceStateArray_states
{
public:
  Init_DeviceStateArray_states()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::stingray_core_interfaces::msg::DeviceStateArray states(::stingray_core_interfaces::msg::DeviceStateArray::_states_type arg)
  {
    msg_.states = std::move(arg);
    return std::move(msg_);
  }

private:
  ::stingray_core_interfaces::msg::DeviceStateArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::stingray_core_interfaces::msg::DeviceStateArray>()
{
  return stingray_core_interfaces::msg::builder::Init_DeviceStateArray_states();
}

}  // namespace stingray_core_interfaces

#endif  // STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE_ARRAY__BUILDER_HPP_
