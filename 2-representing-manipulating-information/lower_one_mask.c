#include <stdio.h>

/*
 * generates mask with least signficant n bits set to 1
 * assumes 1 <= n <= w
*/
int lower_one_mask(int n) {
  int mask = 1 << (n - 1);
  mask |= mask >> 1;
  mask |= mask >> 2;
  mask |= mask >> 4;
  mask |= mask >> 8;
  mask |= mask >> 16;

  return mask;
}

void test_lower_one_mask() {
  struct test_case {
    int input;
    int expected;
  } test_cases[] = {
    {6, 0x3F},
    {17, 0x1FFFF},
    {32, (int)0xFFFFFFFF}
  };

  for (int i = 0; i < sizeof(test_cases)/sizeof(test_cases[0]); ++i) {
    unsigned input = test_cases[i].input;
    int expected = test_cases[i].expected;
    int result = lower_one_mask(input);
    if (result == expected) {
      printf("Test passed for input %u: got %x\n", input, result);
    } else {
      printf("Test failed for input %u: expected %d, got %x\n", input, expected, result);
    }
  }
}

int main() {
  test_lower_one_mask();

  return 0;
}
