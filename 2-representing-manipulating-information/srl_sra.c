#include <assert.h>
#include <stdio.h>

unsigned srl(unsigned x, int k) {
  unsigned xsra = (int)x >> k;

  unsigned w = sizeof(int) * 8; 
  unsigned t = w - k; // w = k + t

  unsigned mask = (~0) << (t - 1); // 1..10..0 : k + t;
  mask <<= 1; // have to avoid case when k = 0

  return xsra & (~mask);
}

int test_srl() {
  unsigned x = 0xA3F90231;
  for (int k = 0; k < sizeof(int) * 8; ++k) {
    if (srl(x, k) != (x >> k)) {
      printf("srl fail at x=%x k=%x\n", x, k);
      return 0;
    }
  }

  return 1;
}

int sra(int x, int k) {
  int xsrl = (unsigned)x >> k;

  int w = sizeof(int) * 8;

  // x < 0   -> mxb = 10..0
  // x >= 0  -> msb = 00..0
  int msb = (1 << (w - 1)) & x; 

  // 10..0  -> 1 
  // 00..0  -> 0 
  msb = !!msb;

  // 1 -> 1..1
  // 0 -> 0..0
  msb = ~(msb - 1);
  // all of this lead to:
  // x < 0   -> mxb = 11..1
  // x >= 0  -> msb = 00..0

  unsigned t = w - k; // w = k + t
  unsigned mask = (~0) << (t - 1); // 1..10..0 : k + t;
  mask <<= 1; // have to avoid case when k = 0
  
  return xsrl | (mask & msb);
}

int test_sra() {
  signed x = 0xA3F90231;
  for (int k = 0; k < sizeof(int) * 8; ++k) {
    if (sra(x, k) != (x >> k)) {
      printf("sra fail at x=%x k=%x\n", x, k);
      return 0;
    }
  }
  signed x_ = 0xFFF90231;
  for (int k = 0; k < sizeof(int) * 8; ++k) {
    if (sra(x_, k) != (x_ >> k)) {
      printf("sra fail at x=%x k=%x\n", x_, k);
      return 0;
    }
  }

  return 1;
}

int main() {
  if (test_srl()) {
    puts("srl work fine");
  } else {
    puts("srl error");
  }

  if (test_sra()) {
    puts("sra work fine");
  } else {
    puts("sra error");
  }
}
