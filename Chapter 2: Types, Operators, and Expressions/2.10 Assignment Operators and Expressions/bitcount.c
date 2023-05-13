#include <stdio.h>

/* bitcount:  count 1 bits in x */
int bitcount(unsigned x);

int main(int argc, char *argv[]) {
  int x = 216;
  
  printf("For input of %u, output is %u\n", x, bitcount(x));
}

int bitcount(unsigned x) {
  int b;

  for (b = 0; x != 0; x >>= 1)
    if (x & 01)
      b++;
  return b;
}
