#include <stdio.h>

/*
 * Assumes 0 <= n < w
*/
unsigned rotate_left(unsigned x, int n) {
  unsigned w = sizeof(int) * 8;
  return (x << n) | (x >> (w - n - !(n)));
}

void test_rotate_left() {
  struct test_case {
    unsigned input1;
    int input2;
    int expected;
  } test_cases[] = {
    {0x12345678, 4, 0x23456781},
    {0x12345678, 20, 0x67812345},
    {0x12345678, 0, 0x12345678}
  };

  for (int i = 0; i < sizeof(test_cases)/sizeof(test_cases[0]); ++i) {
    unsigned input1 = test_cases[i].input1;
    int input2 = test_cases[i].input2;
    int expected = test_cases[i].expected;
    int result = rotate_left(input1, input2);
    if (result == expected) {
      printf("Test passed for input %x, %d: got %x\n", input1, input2, result);
    } else {
      printf("Test failed for input %x, %d: expected %x, got %x\n", input1, input2, expected, result);
    }
  }
}

int main() {
  test_rotate_left();

  return 0;
}
