#include <assert.h>

/*
 * Return 1 when x can be represented as an n-bit, 2'S-COMPLEMENT!
 * number; 0 otherwise 
 * Assume 1 <= n <= w
*/
int fits_bits(int x, int n) {
  /* 
   * in other words, can we erase (w - k) bits from the left,
   * so the 2's complement value of x won't change
  */
  unsigned w = sizeof(int) * 8;
  unsigned k = w - n;
  return x == ((x << k) >> k);
}

int main() {
  assert(fits_bits(8, 1) == 0);
  assert(fits_bits(8, 2) == 0);
  assert(fits_bits(8, 3) == 0);
  assert(fits_bits(8, 4) == 0);
  assert(fits_bits(8, 5) == 1);
  assert(fits_bits(0, 1) == 1);

  assert(!fits_bits(0xFF, 8));
  assert(!fits_bits(~0xFF, 8));

  assert(fits_bits(0b0010, 3));
  assert(!fits_bits(0b1010, 3));
  assert(!fits_bits(0b0110, 3));

  assert(fits_bits(~0b11, 3));
  assert(!fits_bits(~0b01000011, 3));
  assert(!fits_bits(~0b111, 3));
}
