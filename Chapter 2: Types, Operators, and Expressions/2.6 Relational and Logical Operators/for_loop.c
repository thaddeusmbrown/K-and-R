#include <stdio.h>

#define MAXLINES 40

int main(int argc, char *argv[]) {
  /* Write a for loop that is equivalent to:
  for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
    s[i]=c;

  without using '&&' or '||'. 
  */

  char c, s[MAXLINES];
  int lim = MAXLINES;
  for (int i=0; i<lim-1; ++i) {
    if ((c = getchar()) != '\n') {
      if (c != EOF) {
        s[i] = c;
      } else {
        i = lim;
      }
    } else {
      i = lim;
    }
  }
  printf("%s\n", s);
}
