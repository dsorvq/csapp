#include <assert.h>

unsigned replace_byte (unsigned x, int i, unsigned char b) {
  assert(0 <= i && i < sizeof(unsigned));

  unsigned bits_to_shift = i * 8;
  unsigned y = ((unsigned)b) << bits_to_shift;
  x &= ~(0xFF << bits_to_shift);
  return x | y;
}

int main() {
  assert(replace_byte(0x12345678, 2, 0xAB) == 0x12AB5678);
  assert(replace_byte(0x12345678, 0, 0xAB) == 0x123456AB);
}
