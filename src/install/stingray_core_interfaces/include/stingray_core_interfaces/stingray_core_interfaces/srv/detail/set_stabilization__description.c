// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from stingray_core_interfaces:srv/SetStabilization.idl
// generated code does not contain a copyright notice

#include "stingray_core_interfaces/srv/detail/set_stabilization__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_stingray_core_interfaces
const rosidl_type_hash_t *
stingray_core_interfaces__srv__SetStabilization__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x3a, 0x6a, 0xca, 0x7c, 0xfc, 0xef, 0x17, 0x4b,
      0x96, 0x76, 0x51, 0xc1, 0xbe, 0x11, 0xe8, 0xd7,
      0x73, 0xcc, 0x4f, 0x48, 0x68, 0x56, 0x81, 0xeb,
      0x94, 0xa8, 0xdc, 0x01, 0x4c, 0xeb, 0xe2, 0x29,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_stingray_core_interfaces
const rosidl_type_hash_t *
stingray_core_interfaces__srv__SetStabilization_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x11, 0xff, 0x0f, 0x88, 0xa5, 0x89, 0x8a, 0x95,
      0x7c, 0xf5, 0x55, 0x12, 0x09, 0xa1, 0xdb, 0xf1,
      0x26, 0xf2, 0x4e, 0xeb, 0x14, 0xa9, 0xd2, 0x74,
      0xf7, 0x36, 0x2c, 0xac, 0x53, 0x92, 0x9a, 0xee,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_stingray_core_interfaces
const rosidl_type_hash_t *
stingray_core_interfaces__srv__SetStabilization_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xaa, 0x6d, 0x8d, 0xe9, 0x46, 0xaf, 0x62, 0xe6,
      0x27, 0x25, 0xc4, 0xac, 0xe4, 0xc5, 0x3d, 0x84,
      0x5f, 0xc5, 0xb7, 0x38, 0x5a, 0x8c, 0xc1, 0x7f,
      0x2a, 0x17, 0x8b, 0xe8, 0xb7, 0x2b, 0x53, 0xe8,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_stingray_core_interfaces
const rosidl_type_hash_t *
stingray_core_interfaces__srv__SetStabilization_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x8a, 0x0a, 0xdd, 0x80, 0x8f, 0x75, 0xa7, 0x4a,
      0xa0, 0x1e, 0x77, 0x5f, 0x5e, 0x09, 0x53, 0xd9,
      0x1b, 0xf5, 0x15, 0xe2, 0xa1, 0x6b, 0x0c, 0xeb,
      0xad, 0x04, 0x04, 0xb9, 0xeb, 0x2e, 0xec, 0x16,
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

static char stingray_core_interfaces__srv__SetStabilization__TYPE_NAME[] = "stingray_core_interfaces/srv/SetStabilization";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char stingray_core_interfaces__srv__SetStabilization_Event__TYPE_NAME[] = "stingray_core_interfaces/srv/SetStabilization_Event";
static char stingray_core_interfaces__srv__SetStabilization_Request__TYPE_NAME[] = "stingray_core_interfaces/srv/SetStabilization_Request";
static char stingray_core_interfaces__srv__SetStabilization_Response__TYPE_NAME[] = "stingray_core_interfaces/srv/SetStabilization_Response";

// Define type names, field names, and default values
static char stingray_core_interfaces__srv__SetStabilization__FIELD_NAME__request_message[] = "request_message";
static char stingray_core_interfaces__srv__SetStabilization__FIELD_NAME__response_message[] = "response_message";
static char stingray_core_interfaces__srv__SetStabilization__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field stingray_core_interfaces__srv__SetStabilization__FIELDS[] = {
  {
    {stingray_core_interfaces__srv__SetStabilization__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {stingray_core_interfaces__srv__SetStabilization_Request__TYPE_NAME, 53, 53},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetStabilization__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {stingray_core_interfaces__srv__SetStabilization_Response__TYPE_NAME, 54, 54},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetStabilization__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {stingray_core_interfaces__srv__SetStabilization_Event__TYPE_NAME, 51, 51},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription stingray_core_interfaces__srv__SetStabilization__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetStabilization_Event__TYPE_NAME, 51, 51},
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetStabilization_Request__TYPE_NAME, 53, 53},
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetStabilization_Response__TYPE_NAME, 54, 54},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
stingray_core_interfaces__srv__SetStabilization__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {stingray_core_interfaces__srv__SetStabilization__TYPE_NAME, 45, 45},
      {stingray_core_interfaces__srv__SetStabilization__FIELDS, 3, 3},
    },
    {stingray_core_interfaces__srv__SetStabilization__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = stingray_core_interfaces__srv__SetStabilization_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = stingray_core_interfaces__srv__SetStabilization_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = stingray_core_interfaces__srv__SetStabilization_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char stingray_core_interfaces__srv__SetStabilization_Request__FIELD_NAME__depth_stabilization[] = "depth_stabilization";
static char stingray_core_interfaces__srv__SetStabilization_Request__FIELD_NAME__roll_stabilization[] = "roll_stabilization";
static char stingray_core_interfaces__srv__SetStabilization_Request__FIELD_NAME__pitch_stabilization[] = "pitch_stabilization";
static char stingray_core_interfaces__srv__SetStabilization_Request__FIELD_NAME__yaw_stabilization[] = "yaw_stabilization";

static rosidl_runtime_c__type_description__Field stingray_core_interfaces__srv__SetStabilization_Request__FIELDS[] = {
  {
    {stingray_core_interfaces__srv__SetStabilization_Request__FIELD_NAME__depth_stabilization, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetStabilization_Request__FIELD_NAME__roll_stabilization, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetStabilization_Request__FIELD_NAME__pitch_stabilization, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetStabilization_Request__FIELD_NAME__yaw_stabilization, 17, 17},
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
stingray_core_interfaces__srv__SetStabilization_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {stingray_core_interfaces__srv__SetStabilization_Request__TYPE_NAME, 53, 53},
      {stingray_core_interfaces__srv__SetStabilization_Request__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char stingray_core_interfaces__srv__SetStabilization_Response__FIELD_NAME__success[] = "success";
static char stingray_core_interfaces__srv__SetStabilization_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field stingray_core_interfaces__srv__SetStabilization_Response__FIELDS[] = {
  {
    {stingray_core_interfaces__srv__SetStabilization_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetStabilization_Response__FIELD_NAME__message, 7, 7},
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
stingray_core_interfaces__srv__SetStabilization_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {stingray_core_interfaces__srv__SetStabilization_Response__TYPE_NAME, 54, 54},
      {stingray_core_interfaces__srv__SetStabilization_Response__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char stingray_core_interfaces__srv__SetStabilization_Event__FIELD_NAME__info[] = "info";
static char stingray_core_interfaces__srv__SetStabilization_Event__FIELD_NAME__request[] = "request";
static char stingray_core_interfaces__srv__SetStabilization_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field stingray_core_interfaces__srv__SetStabilization_Event__FIELDS[] = {
  {
    {stingray_core_interfaces__srv__SetStabilization_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetStabilization_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {stingray_core_interfaces__srv__SetStabilization_Request__TYPE_NAME, 53, 53},
    },
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetStabilization_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {stingray_core_interfaces__srv__SetStabilization_Response__TYPE_NAME, 54, 54},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription stingray_core_interfaces__srv__SetStabilization_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetStabilization_Request__TYPE_NAME, 53, 53},
    {NULL, 0, 0},
  },
  {
    {stingray_core_interfaces__srv__SetStabilization_Response__TYPE_NAME, 54, 54},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
stingray_core_interfaces__srv__SetStabilization_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {stingray_core_interfaces__srv__SetStabilization_Event__TYPE_NAME, 51, 51},
      {stingray_core_interfaces__srv__SetStabilization_Event__FIELDS, 3, 3},
    },
    {stingray_core_interfaces__srv__SetStabilization_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = stingray_core_interfaces__srv__SetStabilization_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = stingray_core_interfaces__srv__SetStabilization_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Request\n"
  "bool depth_stabilization\n"
  "bool roll_stabilization\n"
  "bool pitch_stabilization\n"
  "bool yaw_stabilization\n"
  "---\n"
  "# Response\n"
  "bool success\n"
  "string message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
stingray_core_interfaces__srv__SetStabilization__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {stingray_core_interfaces__srv__SetStabilization__TYPE_NAME, 45, 45},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 149, 149},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
stingray_core_interfaces__srv__SetStabilization_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {stingray_core_interfaces__srv__SetStabilization_Request__TYPE_NAME, 53, 53},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
stingray_core_interfaces__srv__SetStabilization_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {stingray_core_interfaces__srv__SetStabilization_Response__TYPE_NAME, 54, 54},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
stingray_core_interfaces__srv__SetStabilization_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {stingray_core_interfaces__srv__SetStabilization_Event__TYPE_NAME, 51, 51},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
stingray_core_interfaces__srv__SetStabilization__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *stingray_core_interfaces__srv__SetStabilization__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *stingray_core_interfaces__srv__SetStabilization_Event__get_individual_type_description_source(NULL);
    sources[4] = *stingray_core_interfaces__srv__SetStabilization_Request__get_individual_type_description_source(NULL);
    sources[5] = *stingray_core_interfaces__srv__SetStabilization_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
stingray_core_interfaces__srv__SetStabilization_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *stingray_core_interfaces__srv__SetStabilization_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
stingray_core_interfaces__srv__SetStabilization_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *stingray_core_interfaces__srv__SetStabilization_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
stingray_core_interfaces__srv__SetStabilization_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *stingray_core_interfaces__srv__SetStabilization_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *stingray_core_interfaces__srv__SetStabilization_Request__get_individual_type_description_source(NULL);
    sources[4] = *stingray_core_interfaces__srv__SetStabilization_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
