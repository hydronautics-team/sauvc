// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from stingray_core_interfaces:msg/DeviceStateArray.idl
// generated code does not contain a copyright notice

#ifndef STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE_ARRAY__STRUCT_HPP_
#define STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'states'
#include "stingray_core_interfaces/msg/detail/device_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__stingray_core_interfaces__msg__DeviceStateArray __attribute__((deprecated))
#else
# define DEPRECATED__stingray_core_interfaces__msg__DeviceStateArray __declspec(deprecated)
#endif

namespace stingray_core_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DeviceStateArray_
{
  using Type = DeviceStateArray_<ContainerAllocator>;

  explicit DeviceStateArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit DeviceStateArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _states_type =
    std::vector<stingray_core_interfaces::msg::DeviceState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<stingray_core_interfaces::msg::DeviceState_<ContainerAllocator>>>;
  _states_type states;

  // setters for named parameter idiom
  Type & set__states(
    const std::vector<stingray_core_interfaces::msg::DeviceState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<stingray_core_interfaces::msg::DeviceState_<ContainerAllocator>>> & _arg)
  {
    this->states = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    stingray_core_interfaces::msg::DeviceStateArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const stingray_core_interfaces::msg::DeviceStateArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<stingray_core_interfaces::msg::DeviceStateArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<stingray_core_interfaces::msg::DeviceStateArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      stingray_core_interfaces::msg::DeviceStateArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<stingray_core_interfaces::msg::DeviceStateArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      stingray_core_interfaces::msg::DeviceStateArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<stingray_core_interfaces::msg::DeviceStateArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<stingray_core_interfaces::msg::DeviceStateArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<stingray_core_interfaces::msg::DeviceStateArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__stingray_core_interfaces__msg__DeviceStateArray
    std::shared_ptr<stingray_core_interfaces::msg::DeviceStateArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__stingray_core_interfaces__msg__DeviceStateArray
    std::shared_ptr<stingray_core_interfaces::msg::DeviceStateArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DeviceStateArray_ & other) const
  {
    if (this->states != other.states) {
      return false;
    }
    return true;
  }
  bool operator!=(const DeviceStateArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DeviceStateArray_

// alias to use template instance with default allocator
using DeviceStateArray =
  stingray_core_interfaces::msg::DeviceStateArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace stingray_core_interfaces

#endif  // STINGRAY_CORE_INTERFACES__MSG__DETAIL__DEVICE_STATE_ARRAY__STRUCT_HPP_
