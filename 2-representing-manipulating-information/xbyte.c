#include <assert.h>

typedef unsigned packed_t; // assume int is 4 bytes

/* Extract byte from word and sign extend to 32-bit. Return as signed integer */
int xbyte(packed_t word, int bytenum) {
  unsigned shift = (3 - bytenum) * 8;
  int x = word; // to use arithmetic right shifts
  return (x << shift) >> (3 * 8);
} 

int main() {
  assert(xbyte(0xFFFFFFFF, 0) == 0xFFFFFFFF);
  assert(xbyte(0xFFFFFFFF, 1) == 0xFFFFFFFF);
  assert(xbyte(0xFFFFFFFF, 2) == 0xFFFFFFFF);
  assert(xbyte(0xFFFFFFFF, 3) == 0xFFFFFFFF);

  assert(xbyte(0xFFFFFF0F, 0) == 0x0F);

  assert(xbyte(0x00112233, 0) == 0x33);
  assert(xbyte(0x00112233, 1) == 0x22);
  assert(xbyte(0x00112233, 2) == 0x11);
  assert(xbyte(0x00112233, 3) == 0x00);

  assert(xbyte(0xAABBCCDD, 0) == 0xFFFFFFDD);
  assert(xbyte(0xAABBCCDD, 1) == 0xFFFFFFCC);
  assert(xbyte(0xAABBCCDD, 2) == 0xFFFFFFBB);
  assert(xbyte(0xAABBCCDD, 3) == 0xFFFFFFAA);
}
