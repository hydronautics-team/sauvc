// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from stingray_core_interfaces:msg/DeviceState.idl
// generated code does not contain a copyright notice

#ifndef STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE__STRUCT_HPP_
#define STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__stingray_core_interfaces__msg__DeviceState __attribute__((deprecated))
#else
# define DEPRECATED__stingray_core_interfaces__msg__DeviceState __declspec(deprecated)
#endif

namespace stingray_core_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DeviceState_
{
  using Type = DeviceState_<ContainerAllocator>;

  explicit DeviceState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->device = 0;
      this->value = 0l;
    }
  }

  explicit DeviceState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->device = 0;
      this->value = 0l;
    }
  }

  // field types and members
  using _device_type =
    uint8_t;
  _device_type device;
  using _value_type =
    int32_t;
  _value_type value;

  // setters for named parameter idiom
  Type & set__device(
    const uint8_t & _arg)
  {
    this->device = _arg;
    return *this;
  }
  Type & set__value(
    const int32_t & _arg)
  {
    this->value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    stingray_core_interfaces::msg::DeviceState_<ContainerAllocator> *;
  using ConstRawPtr =
    const stingray_core_interfaces::msg::DeviceState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<stingray_core_interfaces::msg::DeviceState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<stingray_core_interfaces::msg::DeviceState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      stingray_core_interfaces::msg::DeviceState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<stingray_core_interfaces::msg::DeviceState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      stingray_core_interfaces::msg::DeviceState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<stingray_core_interfaces::msg::DeviceState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<stingray_core_interfaces::msg::DeviceState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<stingray_core_interfaces::msg::DeviceState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__stingray_core_interfaces__msg__DeviceState
    std::shared_ptr<stingray_core_interfaces::msg::DeviceState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__stingray_core_interfaces__msg__DeviceState
    std::shared_ptr<stingray_core_interfaces::msg::DeviceState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DeviceState_ & other) const
  {
    if (this->device != other.device) {
      return false;
    }
    if (this->value != other.value) {
      return false;
    }
    return true;
  }
  bool operator!=(const DeviceState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DeviceState_

// alias to use template instance with default allocator
using DeviceState =
  stingray_core_interfaces::msg::DeviceState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace stingray_core_interfaces

#endif  // STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE__STRUCT_HPP_
