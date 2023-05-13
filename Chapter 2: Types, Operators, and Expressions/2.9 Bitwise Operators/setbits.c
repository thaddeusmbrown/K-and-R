#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(int argc, char *argv[]) {
  int x = 216;
  int p = 4;
  int n = 3;
  int y = 7;

  printf("x = %d\np = %d\nn = %d\ny = %d\nAnswer is: %d\n", x, p, n, y, setbits(x, p, n, y));
}

/* setbits:  get n bits from position p */
unsigned setbits(unsigned x, int p, int n, unsigned y) {
  return x | ((~(~0 << n) & y) << (p + 1 - n));
}
