#include <assert.h>

unsigned lowx_elsey(unsigned x, unsigned y) {
  unsigned xmask = 0xFF;
  unsigned ymask = ~(0xFF);

  x = x & xmask;
  y = y & ymask;

  return x | y;
}

int main() {
  assert(lowx_elsey(0x89ABCDEF, 0x76543210) == 0x765432EF);
}
