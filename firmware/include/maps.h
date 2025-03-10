#include <stdint.h>

#define DPAD_UP    0
#define DPAD_RIGHT 1
#define DPAD_DOWN  2
#define DPAD_LEFT  3

uint8_t find_mapping(char const* input);
uint8_t find_dpad(char const* input);

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

// Lookup table based on the ordering of conditions:
// Priority order (first matching):
// 1. Up+Right, 2. Down+Right, 3. Down+Left, 4. Up+Left,
// 5. Up, 6. Right, 7. Down, 8. Left, and 0 if none.
static const uint8_t dpad_lookup[16] = {
     0, // 0000: No direction pressed
     1, // 0001: Up only
     3, // 0010: Right only
     2, // 0011: Up+Right
     5, // 0100: Down only
     1, // 0101: Up+Down
     4, // 0110: Down+Right
     2, // 0111: Up+Right+Down
     7, // 1000: Left only
     8, // 1001: Up+Left
     3, // 1010: Right+Left
     2, // 1011: Up+Right+Left
     6, // 1100: Down+Left
     6, // 1101: Up+Down+Left
     4, // 1110: Down+Right+Left
     0  // 1111: All pressed
};
