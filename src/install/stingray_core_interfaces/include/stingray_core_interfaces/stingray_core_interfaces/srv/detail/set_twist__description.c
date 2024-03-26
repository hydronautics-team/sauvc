// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from stingray_core_interfaces:srv/SetTwist.idl
// generated code does not contain a copyright notice

#include "stingray_core_interfaces/srv/detail/set_twist__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_stingray_core_interfaces
const rosidl_type_hash_t *
stingray_core_interfaces__srv__SetTwist__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd8, 0xfb, 0x04, 0x11, 0xa8, 0xaa, 0xac, 0x4d,
      0xaf, 0x57, 0x9f, 0xae, 0x5c, 0x78, 0x34, 0xae,
      0xc9, 0x5f, 0x44, 0xdd, 0xeb, 0xb8, 0xf3, 0xde,
      0x7a, 0x79, 0x93, 0xbe, 0x19, 0xd7, 0x3c, 0xff,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_stingray_core_interfaces
const rosidl_type_hash_t *
stingray_core_interfaces__srv__SetTwist_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x8e, 0x70, 0x78, 0x47, 0xef, 0xf5, 0xc6, 0xdd,
      0xe1, 0xc7, 0xaa, 0x37, 0x5b, 0x7b, 0xa3, 0x36,
      0x37, 0xa2, 0x9e, 0x22, 0x94, 0x30, 0x38, 0x94,
      0x56, 0x56, 0x65, 0xb2, 0xce, 0xc6, 0x22, 0x44,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_stingray_core_interfaces
const rosidl_type_hash_t *
stingray_core_interfaces__srv__SetTwist_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x90, 0xf1, 0x9f, 0x40, 0x97, 0xfe, 0x57, 0xe1,
      0xf0, 0x1b, 0x6f, 0x91, 0xd2, 0x43, 0xde, 0x6f,
      0x42, 0x10, 0xfd, 0xa3, 0xae, 0xa3, 0x52, 0x64,
      0x39, 0x2e, 0x32, 0xb8, 0x20, 0x1b, 0x6a, 0x90,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_stingray_core_interfaces
const rosidl_type_hash_t *
stingray_core_interfaces__srv__SetTwist_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa4, 0xc2, 0xe7, 0xaf, 0x20, 0x87, 0xe4, 0x11,
      0xa4, 0xb2, 0xfd, 0x53, 0x5c, 0xb2, 0xe6, 0x1e,
      0xa1, 0x1e, 0xd0, 0x8e, 0x3f, 0x06, 0x0d, 0x47,
      0x66, 0xc2, 0x90, 0x6e, 0x5a, 0x43, 0xb7, 0x35,
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

static char stingray_core_interfaces__srv__SetTwist__TYPE_NAME[] = "stingray_core_interfaces/srv/SetTwist";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char stingray_core_interfaces__srv__SetTwist_Event__TYPE_NAME[] = "stingray_core_interfaces/srv/SetTwist_Event";
static char stingray_core_interfaces__srv__SetTwist_Request__TYPE_NAME[] = "stingray_core_interfaces/srv/SetTwist_Request";
static char stingray_core_interfaces__srv__SetTwist_Response__TYPE_NAME[] = "stingray_core_interfaces/srv/SetTwist_Response";

// Define type names, field names, and default values
static char stingray_core_interfaces__srv__SetTwist__FIELD_NAME__request_message[] = "request_message";
static char stingray_core_interfaces__srv__SetTwist__FIELD_NAME__response_message[] = "response_message";
static char stingray_core_interfaces__srv__SetTwist__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field stingray_core_interfaces__srv__SetTwist__FIELDS[] = {
  {
    {stingray_core_interfaces__srv__SetTwist__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {stingray_core_interfaces__srv__SetTwist_Request__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetTwist__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {stingray_core_interfaces__srv__SetTwist_Response__TYPE_NAME, 46, 46},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetTwist__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {stingray_core_interfaces__srv__SetTwist_Event__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription stingray_core_interfaces__srv__SetTwist__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetTwist_Event__TYPE_NAME, 43, 43},
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetTwist_Request__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetTwist_Response__TYPE_NAME, 46, 46},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
stingray_core_interfaces__srv__SetTwist__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {stingray_core_interfaces__srv__SetTwist__TYPE_NAME, 37, 37},
      {stingray_core_interfaces__srv__SetTwist__FIELDS, 3, 3},
    },
    {stingray_core_interfaces__srv__SetTwist__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = stingray_core_interfaces__srv__SetTwist_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = stingray_core_interfaces__srv__SetTwist_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = stingray_core_interfaces__srv__SetTwist_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char stingray_core_interfaces__srv__SetTwist_Request__FIELD_NAME__surge[] = "surge";
static char stingray_core_interfaces__srv__SetTwist_Request__FIELD_NAME__sway[] = "sway";
static char stingray_core_interfaces__srv__SetTwist_Request__FIELD_NAME__depth[] = "depth";
static char stingray_core_interfaces__srv__SetTwist_Request__FIELD_NAME__roll[] = "roll";
static char stingray_core_interfaces__srv__SetTwist_Request__FIELD_NAME__pitch[] = "pitch";
static char stingray_core_interfaces__srv__SetTwist_Request__FIELD_NAME__yaw[] = "yaw";

static rosidl_runtime_c__type_description__Field stingray_core_interfaces__srv__SetTwist_Request__FIELDS[] = {
  {
    {stingray_core_interfaces__srv__SetTwist_Request__FIELD_NAME__surge, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetTwist_Request__FIELD_NAME__sway, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetTwist_Request__FIELD_NAME__depth, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetTwist_Request__FIELD_NAME__roll, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetTwist_Request__FIELD_NAME__pitch, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetTwist_Request__FIELD_NAME__yaw, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
stingray_core_interfaces__srv__SetTwist_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {stingray_core_interfaces__srv__SetTwist_Request__TYPE_NAME, 45, 45},
      {stingray_core_interfaces__srv__SetTwist_Request__FIELDS, 6, 6},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char stingray_core_interfaces__srv__SetTwist_Response__FIELD_NAME__success[] = "success";
static char stingray_core_interfaces__srv__SetTwist_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field stingray_core_interfaces__srv__SetTwist_Response__FIELDS[] = {
  {
    {stingray_core_interfaces__srv__SetTwist_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetTwist_Response__FIELD_NAME__message, 7, 7},
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
stingray_core_interfaces__srv__SetTwist_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {stingray_core_interfaces__srv__SetTwist_Response__TYPE_NAME, 46, 46},
      {stingray_core_interfaces__srv__SetTwist_Response__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char stingray_core_interfaces__srv__SetTwist_Event__FIELD_NAME__info[] = "info";
static char stingray_core_interfaces__srv__SetTwist_Event__FIELD_NAME__request[] = "request";
static char stingray_core_interfaces__srv__SetTwist_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field stingray_core_interfaces__srv__SetTwist_Event__FIELDS[] = {
  {
    {stingray_core_interfaces__srv__SetTwist_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetTwist_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {stingray_core_interfaces__srv__SetTwist_Request__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetTwist_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {stingray_core_interfaces__srv__SetTwist_Response__TYPE_NAME, 46, 46},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription stingray_core_interfaces__srv__SetTwist_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetTwist_Request__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetTwist_Response__TYPE_NAME, 46, 46},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
stingray_core_interfaces__srv__SetTwist_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {stingray_core_interfaces__srv__SetTwist_Event__TYPE_NAME, 43, 43},
      {stingray_core_interfaces__srv__SetTwist_Event__FIELDS, 3, 3},
    },
    {stingray_core_interfaces__srv__SetTwist_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = stingray_core_interfaces__srv__SetTwist_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = stingray_core_interfaces__srv__SetTwist_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Request\n"
  "float32 surge \n"
  "float32 sway\n"
  "float32 depth\n"
  "float32 roll\n"
  "float32 pitch\n"
  "float32 yaw\n"
  "---\n"
  "# Response\n"
  "bool success\n"
  "string message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
stingray_core_interfaces__srv__SetTwist__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {stingray_core_interfaces__srv__SetTwist__TYPE_NAME, 37, 37},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 133, 133},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
stingray_core_interfaces__srv__SetTwist_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {stingray_core_interfaces__srv__SetTwist_Request__TYPE_NAME, 45, 45},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
stingray_core_interfaces__srv__SetTwist_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {stingray_core_interfaces__srv__SetTwist_Response__TYPE_NAME, 46, 46},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
stingray_core_interfaces__srv__SetTwist_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {stingray_core_interfaces__srv__SetTwist_Event__TYPE_NAME, 43, 43},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
stingray_core_interfaces__srv__SetTwist__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *stingray_core_interfaces__srv__SetTwist__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *stingray_core_interfaces__srv__SetTwist_Event__get_individual_type_description_source(NULL);
    sources[4] = *stingray_core_interfaces__srv__SetTwist_Request__get_individual_type_description_source(NULL);
    sources[5] = *stingray_core_interfaces__srv__SetTwist_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
stingray_core_interfaces__srv__SetTwist_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *stingray_core_interfaces__srv__SetTwist_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
stingray_core_interfaces__srv__SetTwist_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *stingray_core_interfaces__srv__SetTwist_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
stingray_core_interfaces__srv__SetTwist_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *stingray_core_interfaces__srv__SetTwist_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *stingray_core_interfaces__srv__SetTwist_Request__get_individual_type_description_source(NULL);
    sources[4] = *stingray_core_interfaces__srv__SetTwist_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
