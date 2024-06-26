#include <assert.h>
#include <string.h>

/* Copy integer into buffer if space is available */
void copy_int(int val, void* buf, int maxbytes) { 
  if (maxbytes >= (int) sizeof(val)) {     
    memcpy(buf, (void*) &val, sizeof(val));
  }
}

int main() {
  int val = 1234;
  {
    char* buf;
    *buf = 0;
    copy_int(val, buf, 1);
    assert(*buf == 0);
  }
  {
    long* buf;
    *buf = 0;
    copy_int(val, buf, sizeof(long));
    assert(*buf == val);
  }
}
