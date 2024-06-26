#include <stdio.h>

/*
 * return 0 if x have odd number of 1 bits
*/
int odd_ones(unsigned x) {
  x ^= (x >> 16);
  x ^= (x >> 8);
  x ^= (x >> 4);
  x ^= (x >> 2);
  x ^= (x >> 1);

  return x & (0x1);
}

void test_odd_ones() {
  struct test_case {
    unsigned input;
    int expected;
  } test_cases[] = {
    {0, 0},
    {0xFFFFFFFFu, 0},
    {1, 1},
    {0x10101011, 1},
    {0x01010101, 0}
  };

  for (int i = 0; i < sizeof(test_cases)/sizeof(test_cases[0]); ++i) {
    unsigned input = test_cases[i].input;
    int expected = test_cases[i].expected;
    int result = odd_ones(input);
    if (result == expected) {
      printf("Test passed for input %u: got %x\n", input, result);
    } else {
      printf("Test failed for input %u: expected %d, got %x\n", input, expected, result);
    }
  }
}

int main() {
  test_odd_ones();

  return 0;
}
