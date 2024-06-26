/*
 * returns 1 if at least one odd bit is 1
*/
int any_odd_one(unsigned x) {
  return !!(x & 0xAAAAAAAA);
}
