/*
 * Assumes int width at least 32 bits and checks if it is exacly 32 bits
*/
int int_size_is_32() { 
  int set_msb = 1 << 31; 
  int beyond_msb = set_msb << 1; 

  return set_msb && !beyond_msb;
}
