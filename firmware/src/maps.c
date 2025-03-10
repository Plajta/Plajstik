#include <string.h>
#include <stdint.h>
#include "maps.h"

uint8_t find_mapping(char const* input) {
    for (int i = 0; i < main_mappings_size; ++i) {
        if (strcmp(input, main_mappings[i].key) == 0) {
            return main_mappings[i].value;
        }
    }
    return -1;
};

uint8_t find_dpad(char const* input) {
    for (int i = 0; i < dpad_mappings_size; ++i) {
        if (strcmp(input, dpad_mappings[i].key) == 0) {
            return dpad_mappings[i].value;
        }
    }
    return -1;
};
