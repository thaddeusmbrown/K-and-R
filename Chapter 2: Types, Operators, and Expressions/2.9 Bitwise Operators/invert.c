#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(int argc, char *argv[]) {
  int x = 216;
  int p = 4;
  int n = 3;

  printf("x = %d\np = %d\nn = %d\nAnswer is: %d\n", x, p, n, invert(x, p, n));
}

/* invert:  return x with the n bits that begin at position p (i.e., 1 changed into 
   0 and vice versa), leaving the others unchanged. */
unsigned invert(unsigned x, int p, int n) {
  return x ^ (~(~0 << n) << (p + 1 - n));
}
