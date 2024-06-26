int int_shifts_are_arithmetic() {
  int x = ~0;
  return (x >> 1) == -1; // return 1 if arithmetic right shift, 0 of logical
}
