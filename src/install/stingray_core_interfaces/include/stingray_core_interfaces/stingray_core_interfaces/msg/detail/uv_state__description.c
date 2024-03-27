// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from stingray_core_interfaces:msg/UVState.idl
// generated code does not contain a copyright notice

#include "stingray_core_interfaces/msg/detail/uv_state__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_stingray_core_interfaces
const rosidl_type_hash_t *
stingray_core_interfaces__msg__UVState__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xdf, 0xa3, 0xc9, 0xad, 0x8c, 0xd1, 0xce, 0x1d,
      0xb2, 0xd1, 0xfc, 0xfe, 0xb9, 0x72, 0xc7, 0xfe,
      0x4a, 0x0b, 0x70, 0x88, 0x75, 0x29, 0x06, 0xa7,
      0xc5, 0x5d, 0x3a, 0x62, 0x35, 0x1b, 0x32, 0xdd,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char stingray_core_interfaces__msg__UVState__TYPE_NAME[] = "stingray_core_interfaces/msg/UVState";

// Define type names, field names, and default values
static char stingray_core_interfaces__msg__UVState__FIELD_NAME__roll[] = "roll";
static char stingray_core_interfaces__msg__UVState__FIELD_NAME__pitch[] = "pitch";
static char stingray_core_interfaces__msg__UVState__FIELD_NAME__yaw[] = "yaw";
static char stingray_core_interfaces__msg__UVState__FIELD_NAME__roll_speed[] = "roll_speed";
static char stingray_core_interfaces__msg__UVState__FIELD_NAME__pitch_speed[] = "pitch_speed";
static char stingray_core_interfaces__msg__UVState__FIELD_NAME__yaw_speed[] = "yaw_speed";
static char stingray_core_interfaces__msg__UVState__FIELD_NAME__depth[] = "depth";
static char stingray_core_interfaces__msg__UVState__FIELD_NAME__depth_stabilization[] = "depth_stabilization";
static char stingray_core_interfaces__msg__UVState__FIELD_NAME__roll_stabilization[] = "roll_stabilization";
static char stingray_core_interfaces__msg__UVState__FIELD_NAME__pitch_stabilization[] = "pitch_stabilization";
static char stingray_core_interfaces__msg__UVState__FIELD_NAME__yaw_stabilization[] = "yaw_stabilization";

static rosidl_runtime_c__type_description__Field stingray_core_interfaces__msg__UVState__FIELDS[] = {
  {
    {stingray_core_interfaces__msg__UVState__FIELD_NAME__roll, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__msg__UVState__FIELD_NAME__pitch, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__msg__UVState__FIELD_NAME__yaw, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__msg__UVState__FIELD_NAME__roll_speed, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__msg__UVState__FIELD_NAME__pitch_speed, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__msg__UVState__FIELD_NAME__yaw_speed, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__msg__UVState__FIELD_NAME__depth, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__msg__UVState__FIELD_NAME__depth_stabilization, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__msg__UVState__FIELD_NAME__roll_stabilization, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__msg__UVState__FIELD_NAME__pitch_stabilization, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__msg__UVState__FIELD_NAME__yaw_stabilization, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
stingray_core_interfaces__msg__UVState__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {stingray_core_interfaces__msg__UVState__TYPE_NAME, 36, 36},
      {stingray_core_interfaces__msg__UVState__FIELDS, 11, 11},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 roll\n"
  "float32 pitch\n"
  "float32 yaw\n"
  "float32 roll_speed\n"
  "float32 pitch_speed\n"
  "float32 yaw_speed\n"
  "float32 depth\n"
  "bool depth_stabilization\n"
  "bool roll_stabilization\n"
  "bool pitch_stabilization\n"
  "bool yaw_stabilization";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
stingray_core_interfaces__msg__UVState__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {stingray_core_interfaces__msg__UVState__TYPE_NAME, 36, 36},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 206, 206},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
stingray_core_interfaces__msg__UVState__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *stingray_core_interfaces__msg__UVState__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
