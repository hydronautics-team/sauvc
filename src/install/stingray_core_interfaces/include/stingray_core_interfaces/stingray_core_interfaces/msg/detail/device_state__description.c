// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from stingray_core_interfaces:msg/DeviceState.idl
// generated code does not contain a copyright notice

#include "stingray_core_interfaces/msg/detail/device_state__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_stingray_core_interfaces
const rosidl_type_hash_t *
stingray_core_interfaces__msg__DeviceState__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe6, 0x24, 0x22, 0x08, 0xb4, 0x5b, 0x68, 0xbe,
      0x9d, 0x9b, 0xb1, 0x9e, 0x49, 0x13, 0xdf, 0xde,
      0x54, 0x2e, 0x3c, 0xb7, 0x1f, 0xd8, 0xcb, 0x29,
      0x63, 0xb5, 0xd8, 0xd6, 0x5d, 0x6e, 0xd4, 0xb6,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char stingray_core_interfaces__msg__DeviceState__TYPE_NAME[] = "stingray_core_interfaces/msg/DeviceState";

// Define type names, field names, and default values
static char stingray_core_interfaces__msg__DeviceState__FIELD_NAME__device[] = "device";
static char stingray_core_interfaces__msg__DeviceState__FIELD_NAME__value[] = "value";

static rosidl_runtime_c__type_description__Field stingray_core_interfaces__msg__DeviceState__FIELDS[] = {
  {
    {stingray_core_interfaces__msg__DeviceState__FIELD_NAME__device, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__msg__DeviceState__FIELD_NAME__value, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
stingray_core_interfaces__msg__DeviceState__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {stingray_core_interfaces__msg__DeviceState__TYPE_NAME, 40, 40},
      {stingray_core_interfaces__msg__DeviceState__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint8 device\n"
  "int32 value";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
stingray_core_interfaces__msg__DeviceState__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {stingray_core_interfaces__msg__DeviceState__TYPE_NAME, 40, 40},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 24, 24},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
stingray_core_interfaces__msg__DeviceState__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *stingray_core_interfaces__msg__DeviceState__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
