// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from stingray_core_interfaces:msg/DeviceStateArray.idl
// generated code does not contain a copyright notice

#include "stingray_core_interfaces/msg/detail/device_state_array__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_stingray_core_interfaces
const rosidl_type_hash_t *
stingray_core_interfaces__msg__DeviceStateArray__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x34, 0xd9, 0x98, 0xf4, 0xc5, 0x95, 0x84, 0xbb,
      0xf3, 0xba, 0x6b, 0x75, 0x04, 0x6a, 0x23, 0xa3,
      0x03, 0xc2, 0x02, 0xb6, 0x72, 0xa8, 0xdc, 0x95,
      0x7a, 0xb1, 0x79, 0xfe, 0x6e, 0x91, 0x1b, 0x26,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "stingray_core_interfaces/msg/detail/device_state__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t stingray_core_interfaces__msg__DeviceState__EXPECTED_HASH = {1, {
    0xe6, 0x24, 0x22, 0x08, 0xb4, 0x5b, 0x68, 0xbe,
    0x9d, 0x9b, 0xb1, 0x9e, 0x49, 0x13, 0xdf, 0xde,
    0x54, 0x2e, 0x3c, 0xb7, 0x1f, 0xd8, 0xcb, 0x29,
    0x63, 0xb5, 0xd8, 0xd6, 0x5d, 0x6e, 0xd4, 0xb6,
  }};
#endif

static char stingray_core_interfaces__msg__DeviceStateArray__TYPE_NAME[] = "stingray_core_interfaces/msg/DeviceStateArray";
static char stingray_core_interfaces__msg__DeviceState__TYPE_NAME[] = "stingray_core_interfaces/msg/DeviceState";

// Define type names, field names, and default values
static char stingray_core_interfaces__msg__DeviceStateArray__FIELD_NAME__states[] = "states";

static rosidl_runtime_c__type_description__Field stingray_core_interfaces__msg__DeviceStateArray__FIELDS[] = {
  {
    {stingray_core_interfaces__msg__DeviceStateArray__FIELD_NAME__states, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {stingray_core_interfaces__msg__DeviceState__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription stingray_core_interfaces__msg__DeviceStateArray__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {stingray_core_interfaces__msg__DeviceState__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
stingray_core_interfaces__msg__DeviceStateArray__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {stingray_core_interfaces__msg__DeviceStateArray__TYPE_NAME, 45, 45},
      {stingray_core_interfaces__msg__DeviceStateArray__FIELDS, 1, 1},
    },
    {stingray_core_interfaces__msg__DeviceStateArray__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&stingray_core_interfaces__msg__DeviceState__EXPECTED_HASH, stingray_core_interfaces__msg__DeviceState__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = stingray_core_interfaces__msg__DeviceState__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "stingray_core_interfaces/DeviceState[] states";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
stingray_core_interfaces__msg__DeviceStateArray__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {stingray_core_interfaces__msg__DeviceStateArray__TYPE_NAME, 45, 45},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 45, 45},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
stingray_core_interfaces__msg__DeviceStateArray__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *stingray_core_interfaces__msg__DeviceStateArray__get_individual_type_description_source(NULL),
    sources[1] = *stingray_core_interfaces__msg__DeviceState__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
