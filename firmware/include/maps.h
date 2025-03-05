#include <stdint.h>

uint8_t find_mapping(char const* input);
uint8_t find_dpad(char const* input);
uint8_t find_dpad_dir(uint8_t* dpad);

typedef struct {
    const char* key;
    int8_t value;
} Mapping;

static const Mapping main_mappings[] = {
    {"a", 0}, {"b", 1}, {"x", 3}, {"y", 4},
    {"l1", 6}, {"r1", 7}, {"l2", 8}, {"r2", 9},
    {"select", 10}, {"start", 11}, {"home", 12},
    {"l3", 13}, {"r3", 14}
};

static const size_t main_mappings_size = sizeof(main_mappings) / sizeof(main_mappings[0]);

static const Mapping dpad_mappings[] = {
    {"dpad_u", 0}, {"dpad_r", 1}, {"dpad_d", 2}, {"dpad_l", 3}
};

static const size_t dpad_mappings_size = sizeof(dpad_mappings) / sizeof(dpad_mappings[0]);
