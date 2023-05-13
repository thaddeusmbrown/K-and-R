#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

int main(int argc, char *argv[]) {
  int x = 217;
  int p = 4;
  int n = 3;

  printf("x = %d\np = %d\nn = %d\n\nAnswer is: %d\n", x, p, n, getbits(x, p, n));
}

/* getbits:  get n bits from position p */
unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p + 1 - n)) & ~(~0 << n);
}
