#include <stdio.h>
#include <limits.h>

unsigned rightrot(unsigned x, int n);

int main(int argc, char *argv[]) {
  unsigned int x = 216;

  printf("x = %u\n\n", x);
  for (int n = 0; n <= 32; n++)
    printf("n = %u\nAnswer is: %u\n\n", n, rightrot(x, n));
}

/* rightrot:  return x rotated to the right by n bit positions */
unsigned rightrot(unsigned x, int n) {
  unsigned int left_out, right_out, result;
  const unsigned long INT_BIT = sizeof(int)*CHAR_BIT;
 
  right_out = x >> n;
  left_out = (x << (INT_BIT - n)) & (~0 << (INT_BIT - n));
  result = left_out | right_out;

  return result;
}
