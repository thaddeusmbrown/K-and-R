#include <stdio.h>

/* power:  raise base to n-th power; n>=0; version 2*/
int power(int base, int n) {
  int p;

  for (p = 1; n > 0; --n)
    p = p * base;
  return p;
}

int main(int argc, char *argv[]) {
  int i;

  for (i = 0; i < 10; ++i)
    printf("%d %d %d\n", i, power(2,i), power(-3,i));
}
