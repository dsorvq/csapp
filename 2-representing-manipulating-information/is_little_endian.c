#include <stdio.h>

int is_little_endian() {
  int ret;
  unsigned int x = 0xFF;
  unsigned char* ucpx = (unsigned char*)&x;

  if (*ucpx == 0xFF) {
    // first byte is 0xFF, so this must be little endian
    ret = 1;
  } else {
    ret = 0;
  }

  return ret;
}

int main() {
  if (is_little_endian()) {
    puts("This machine uses little endian");
  } else {
    puts("This machine uses big endian");
  }

  return 0;
}
