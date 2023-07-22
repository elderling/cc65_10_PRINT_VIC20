#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <peekpoke.h>

# define VID_RAM_LAYOUT_REG 0x9005

uint8_t slant1[] = { 'M', 0 };
uint8_t slant2[] = { 'N', 0 };

uint8_t main(void) {

  // Switch to capitals + graphics character set
  POKE(VID_RAM_LAYOUT_REG, 0xf0);

  while (1) {
    (rand() % 2) ? printf("%s", &slant1) : printf("%s", &slant2);
  }

  return 0;
}

