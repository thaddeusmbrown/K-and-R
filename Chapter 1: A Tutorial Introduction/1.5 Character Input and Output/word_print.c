#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* print input one word per line */
main()
{
  int c, state;

  state = OUT;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {           // skip whitespace
      state = OUT;
    } else if (state == OUT) {                          // enter a word for first time
      state = IN;
      putchar(c);
      c = getchar();
      while (!(c == ' ' || c == '\n' || c == '\t')) {   // loop through word
        putchar(c);
        c = getchar();
      }
      state = OUT;                                      // reset state and go to new line
      putchar('\n');
    }
  }
}
