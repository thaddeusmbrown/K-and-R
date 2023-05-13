#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main(int argc, char *argv[]) {
  int x = 216;
  int n = 0;

  printf("x = %d\nn = %d\nAnswer is: %d\n", x, n, rightrot(x, n));
}

/* invert:  return x with the n bits that begin at position p (i.e., 1 changed into 
   0 and vice versa), leaving the others unchanged. */
unsigned invert(unsigned x, int p, int n) {
  return x ^ (~(~0 << n) << (p + 1 - n));
}
