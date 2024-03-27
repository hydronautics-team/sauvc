// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from stingray_core_interfaces:srv/SetDevice.idl
// generated code does not contain a copyright notice

#include "stingray_core_interfaces/srv/detail/set_device__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_stingray_core_interfaces
const rosidl_type_hash_t *
stingray_core_interfaces__srv__SetDevice__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc1, 0xbb, 0x51, 0x4e, 0x0c, 0x9a, 0x26, 0x83,
      0x7c, 0x09, 0xb1, 0x9e, 0xcb, 0x4f, 0x03, 0x95,
      0x7c, 0x6a, 0xa1, 0x60, 0x98, 0x92, 0xc5, 0xc7,
      0xc4, 0x68, 0x0e, 0x62, 0x17, 0xff, 0xc2, 0xf5,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_stingray_core_interfaces
const rosidl_type_hash_t *
stingray_core_interfaces__srv__SetDevice_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x98, 0xd0, 0x5b, 0xc8, 0x7b, 0xc9, 0xdd, 0x9f,
      0x1d, 0x6d, 0x3d, 0x55, 0xda, 0xe3, 0x49, 0xea,
      0x55, 0x02, 0xf1, 0x75, 0x10, 0x80, 0x39, 0x5d,
      0xc9, 0xd3, 0xa3, 0xc6, 0x75, 0x78, 0xd2, 0xdc,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_stingray_core_interfaces
const rosidl_type_hash_t *
stingray_core_interfaces__srv__SetDevice_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x1f, 0xf9, 0xb1, 0xb2, 0x5b, 0x48, 0x00, 0xd7,
      0x71, 0xaa, 0x5e, 0x77, 0xae, 0x0c, 0x84, 0x6d,
      0xc1, 0x0f, 0xb1, 0x69, 0xd4, 0xb0, 0x60, 0xed,
      0xfc, 0x27, 0xd0, 0x48, 0x25, 0x3b, 0xf5, 0x81,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_stingray_core_interfaces
const rosidl_type_hash_t *
stingray_core_interfaces__srv__SetDevice_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9c, 0x3d, 0xc8, 0xd3, 0x56, 0x66, 0xff, 0xdd,
      0xb7, 0x79, 0x04, 0x6c, 0x07, 0xb7, 0x24, 0xca,
      0x1f, 0x17, 0x30, 0xd0, 0x3f, 0xc2, 0x22, 0xcf,
      0x34, 0x51, 0x24, 0x49, 0xf2, 0x61, 0xd0, 0x05,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char stingray_core_interfaces__srv__SetDevice__TYPE_NAME[] = "stingray_core_interfaces/srv/SetDevice";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char stingray_core_interfaces__srv__SetDevice_Event__TYPE_NAME[] = "stingray_core_interfaces/srv/SetDevice_Event";
static char stingray_core_interfaces__srv__SetDevice_Request__TYPE_NAME[] = "stingray_core_interfaces/srv/SetDevice_Request";
static char stingray_core_interfaces__srv__SetDevice_Response__TYPE_NAME[] = "stingray_core_interfaces/srv/SetDevice_Response";

// Define type names, field names, and default values
static char stingray_core_interfaces__srv__SetDevice__FIELD_NAME__request_message[] = "request_message";
static char stingray_core_interfaces__srv__SetDevice__FIELD_NAME__response_message[] = "response_message";
static char stingray_core_interfaces__srv__SetDevice__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field stingray_core_interfaces__srv__SetDevice__FIELDS[] = {
  {
    {stingray_core_interfaces__srv__SetDevice__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {stingray_core_interfaces__srv__SetDevice_Request__TYPE_NAME, 46, 46},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetDevice__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {stingray_core_interfaces__srv__SetDevice_Response__TYPE_NAME, 47, 47},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetDevice__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {stingray_core_interfaces__srv__SetDevice_Event__TYPE_NAME, 44, 44},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription stingray_core_interfaces__srv__SetDevice__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetDevice_Event__TYPE_NAME, 44, 44},
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetDevice_Request__TYPE_NAME, 46, 46},
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetDevice_Response__TYPE_NAME, 47, 47},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
stingray_core_interfaces__srv__SetDevice__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {stingray_core_interfaces__srv__SetDevice__TYPE_NAME, 38, 38},
      {stingray_core_interfaces__srv__SetDevice__FIELDS, 3, 3},
    },
    {stingray_core_interfaces__srv__SetDevice__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = stingray_core_interfaces__srv__SetDevice_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = stingray_core_interfaces__srv__SetDevice_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = stingray_core_interfaces__srv__SetDevice_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char stingray_core_interfaces__srv__SetDevice_Request__FIELD_NAME__device[] = "device";
static char stingray_core_interfaces__srv__SetDevice_Request__FIELD_NAME__value[] = "value";

static rosidl_runtime_c__type_description__Field stingray_core_interfaces__srv__SetDevice_Request__FIELDS[] = {
  {
    {stingray_core_interfaces__srv__SetDevice_Request__FIELD_NAME__device, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetDevice_Request__FIELD_NAME__value, 5, 5},
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
stingray_core_interfaces__srv__SetDevice_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {stingray_core_interfaces__srv__SetDevice_Request__TYPE_NAME, 46, 46},
      {stingray_core_interfaces__srv__SetDevice_Request__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char stingray_core_interfaces__srv__SetDevice_Response__FIELD_NAME__success[] = "success";
static char stingray_core_interfaces__srv__SetDevice_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field stingray_core_interfaces__srv__SetDevice_Response__FIELDS[] = {
  {
    {stingray_core_interfaces__srv__SetDevice_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetDevice_Response__FIELD_NAME__message, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
stingray_core_interfaces__srv__SetDevice_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {stingray_core_interfaces__srv__SetDevice_Response__TYPE_NAME, 47, 47},
      {stingray_core_interfaces__srv__SetDevice_Response__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char stingray_core_interfaces__srv__SetDevice_Event__FIELD_NAME__info[] = "info";
static char stingray_core_interfaces__srv__SetDevice_Event__FIELD_NAME__request[] = "request";
static char stingray_core_interfaces__srv__SetDevice_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field stingray_core_interfaces__srv__SetDevice_Event__FIELDS[] = {
  {
    {stingray_core_interfaces__srv__SetDevice_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetDevice_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {stingray_core_interfaces__srv__SetDevice_Request__TYPE_NAME, 46, 46},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetDevice_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {stingray_core_interfaces__srv__SetDevice_Response__TYPE_NAME, 47, 47},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription stingray_core_interfaces__srv__SetDevice_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetDevice_Request__TYPE_NAME, 46, 46},
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetDevice_Response__TYPE_NAME, 47, 47},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
stingray_core_interfaces__srv__SetDevice_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {stingray_core_interfaces__srv__SetDevice_Event__TYPE_NAME, 44, 44},
      {stingray_core_interfaces__srv__SetDevice_Event__FIELDS, 3, 3},
    },
    {stingray_core_interfaces__srv__SetDevice_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = stingray_core_interfaces__srv__SetDevice_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = stingray_core_interfaces__srv__SetDevice_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Request\n"
  "uint8 device\n"
  "int32 value\n"
  "---\n"
  "# Response\n"
  "bool success\n"
  "string message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
stingray_core_interfaces__srv__SetDevice__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {stingray_core_interfaces__srv__SetDevice__TYPE_NAME, 38, 38},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 77, 77},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
stingray_core_interfaces__srv__SetDevice_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {stingray_core_interfaces__srv__SetDevice_Request__TYPE_NAME, 46, 46},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
stingray_core_interfaces__srv__SetDevice_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {stingray_core_interfaces__srv__SetDevice_Response__TYPE_NAME, 47, 47},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
stingray_core_interfaces__srv__SetDevice_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {stingray_core_interfaces__srv__SetDevice_Event__TYPE_NAME, 44, 44},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
stingray_core_interfaces__srv__SetDevice__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *stingray_core_interfaces__srv__SetDevice__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *stingray_core_interfaces__srv__SetDevice_Event__get_individual_type_description_source(NULL);
    sources[4] = *stingray_core_interfaces__srv__SetDevice_Request__get_individual_type_description_source(NULL);
    sources[5] = *stingray_core_interfaces__srv__SetDevice_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
stingray_core_interfaces__srv__SetDevice_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *stingray_core_interfaces__srv__SetDevice_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
stingray_core_interfaces__srv__SetDevice_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *stingray_core_interfaces__srv__SetDevice_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
stingray_core_interfaces__srv__SetDevice_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *stingray_core_interfaces__srv__SetDevice_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *stingray_core_interfaces__srv__SetDevice_Request__get_individual_type_description_source(NULL);
    sources[4] = *stingray_core_interfaces__srv__SetDevice_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
