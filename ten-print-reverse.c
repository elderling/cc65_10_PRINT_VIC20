#include <string.h>
#include <stdint.h>
#include <peekpoke.h>
#include <stdlib.h>

# define VID_RAM_LAYOUT_REG 0x9005
# define SCREEN 0x1e00      // unexpanded
# define COLOR_START 0x9600  // unexpanded
// # define COLOR_START 0x9400  // expanded
// # define SCREEN 0x1000      // expanded

# define SLANT1 0x4d
# define SLANT2 0x4e

void main(void) {

  uint8_t* screen; 
  uint8_t* color;
  int i;
  uint8_t j;

  // Switch to capitals + graphics character set (unexpanded)
  POKE(VID_RAM_LAYOUT_REG, 0xf0);

  screen = (uint8_t*) SCREEN;
  color = (uint8_t*) COLOR_START;

  for ( j = 0; j < 22; j++ ) {
      POKE(color + j, 6); // blue
  }

  while (1) {
    for (i = 22 * 22; i > -1; i = i - 22) {
      memcpy( screen + 22 + i, screen + i, 22 ); 
      memcpy( color + 22 + i, color + i, 22 );
    }

    for ( j = 0; j < 22; j++ ) {
      if ( rand() % 2 ) {
        POKE(screen + j, SLANT1);
      } else {
        POKE(screen + j, SLANT2);
      }
    }
  }
}
