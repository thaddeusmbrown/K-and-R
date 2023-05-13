#include <stdio.h>
#include <limits.h>

unsigned rightrot(unsigned x, int n);

int main(int argc, char *argv[]) {
  int x = 216;
  int n = 4;

  printf("The number of bits in an int is INT_BIT: %ld\n", sizeof(int)*CHAR_BIT);
  printf("x = %d\nn = %d\nAnswer is: %d\n", x, n, rightrot(x, n));
}

/* rightrot:  return x rotated to the right by n bit positions */
unsigned rightrot(unsigned x, int n) {
  unsigned left_out, right_out;
  const unsigned long INT_BIT = sizeof(int)*CHAR_BIT;
  right_out = x >> n;
  left_out = x & (~0 << (INT_BIT - n));

  printf("left_out:  %d\nright_out:  %d", left_out, right_out);

  return left_out | right_out;
}
