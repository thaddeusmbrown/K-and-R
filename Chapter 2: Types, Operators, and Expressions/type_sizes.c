#include <stdio.h>
#include <limits.h>
#include <float.h>

/* Determine the ranges of char, short, int, and long variables, both signed and unsigned 
through printing from standard headers and by direct computation. Also determine the ranges
of the various floating-point types. */
int main(int argc, char *argv[]) {
  printf("From Standard Headers:\n\n");

  /* unsigned integrals */
  printf("unsigned char max: %u\n", UCHAR_MAX);
  printf("unsigned short max: %u\n", USHRT_MAX);
  printf("unsigned int max: %u\n", UINT_MAX);
  printf("unsigned long max: %lu\n\n", ULONG_MAX);

  /* signed integrals */
  printf("signed char:\n");
  printf("min: %d\n", CHAR_MIN);
  printf("max: %d\n\n", CHAR_MAX);

  printf("signed short:\n");
  printf("min: %d\n", SHRT_MIN);
  printf("max: %d\n\n", SHRT_MAX);

  printf("signed int:\n");
  printf("min: %d\n", INT_MIN);
  printf("max: %d\n\n", INT_MAX);

  printf("signed long:\n");
  printf("min: %ld\n", LONG_MIN);
  printf("max: %ld\n\n\n", LONG_MAX);

  printf("Determined Computationally:\n\n");

  /* unsigned integrals */
  unsigned char uc = 0;
  unsigned short us = 0;
  unsigned int ui = 0;
  unsigned long ul = 0;

  printf("unsigned char max: %u\n", --uc);
  printf("unsigned short max: %u\n", --us);
  printf("unsigned int max: %u\n", --ui);
  printf("unsigned long max: %lu\n\n", --ul);
  
  /* signed integrals */
  signed char c = 0;
  signed short s = 0;
  signed int i = 0;
  signed long l1 = -2;
  signed long l2 = -1;

  while (c >= 0) {
    ++c;
  }
  printf("signed char:\n");
  printf("min: %d\n", c);
  printf("max: %d\n\n", --c);

  while (s >= 0) {
    ++s;
  }
  printf("signed short:\n");
  printf("min: %d\n", s);
  printf("max: %d\n\n", --s);

  while (i >= 0) {
    ++i;
  }
  printf("signed int:\n");
  printf("min: %d\n", i);
  printf("max: %d\n\n", --i);

  while (l1 < 0) {
    l1 = l1 * 2;
    l2 = l2 * 2;
  }
  while (l2 < 0) {
    --l2;
  }
  ++l2;
  printf("signed long:\n");
  printf("min: %ld\n", l2);
  printf("max: %ld\n\n\n", --l2);
}
