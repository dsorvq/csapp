#include <limits.h>
#include <stdio.h>

int leftmost_one(unsigned x) {
  /*
   * -> 01xxxx
   * -> 011xxx
   * -> 01111x
   * -> 011111 
  */
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;

  // 011111 -> 001111 + 1 -> 010000
  return (x >> 1) + (x && 1);
}

void test_leftmost_one() {
  struct test_case {
    unsigned input;
    int expected;
  } test_cases[] = {
    {0, 0},
    {1, 1},
    {2, 2},
    {3, 2},
    {8, 8},
    {15, 8},
    {16, 16},
    {255, 128},
    {256, 256},
    {1023, 512},
    {UINT_MAX, INT_MIN},
  };

  for (int i = 0; i < sizeof(test_cases)/sizeof(test_cases[0]); ++i) {
    unsigned input = test_cases[i].input;
    int expected = test_cases[i].expected;
    int result = leftmost_one(input);
    if (result == expected) {
      printf("Test passed for input %u: got %d\n", input, result);
    } else {
      printf("Test failed for input %u: expected %d, got %d\n", input, expected, result);
    }
  }
}

int main() {
  test_leftmost_one();

  return 0;
}
