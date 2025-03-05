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

uint8_t find_dpad_dir(uint8_t* dpad){
  // Diagonal directions
  if (dpad[0] && dpad[1]) return 2; // Up-Right
  if (dpad[2] && dpad[1]) return 4; // Down-Right
  if (dpad[2] && dpad[3]) return 6; // Down-Left
  if (dpad[0] && dpad[3]) return 8; // Up-Left

  // Straight directions
  if (dpad[0]) return 1; // Up
  if (dpad[1]) return 3; // Right
  if (dpad[2]) return 5; // Down
  if (dpad[3]) return 7; // Left

  return 0; // No direction pressed
}
