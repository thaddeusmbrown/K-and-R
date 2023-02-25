#include <stdio.h>

/* copy input to output, replacing each string of
one or more blanks by a single blank */
main()
{
  int c, flag;

  flag = 0;
  while((c = getchar()) != EOF) {
    if (c != ' ') {
      putchar(c);
      flag = 0;
    } else if (!flag) {
      putchar(c);
      flag = 1;
    }
  }
}
