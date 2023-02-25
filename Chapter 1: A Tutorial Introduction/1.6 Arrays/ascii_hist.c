#include <stdio.h>

/* print a horizontal histogram of frequency 
of ASCII characters in an input */
main()
{
  int c, i, j;
  int ascii[256];

  for (i = 0; i < 256; ++i) {
    ascii[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    ++ascii[c];
  }

  printf("ASCII Character Frequency Histogram:\n");
  for (i = 0; i < 256; ++i) {
    if (ascii[i] > 0) {       
      if (i == ' ') {                   // check for white space chars and print axis
        printf("' ' |");
      } else if (i == '\n') {
        printf("\\");
        printf("n  |");
      } else if (i == '\t') {
        printf("\\");
        printf("t  |");
      } else {
        putchar(i);
        printf("   |");
      }
      
      for (j = 0; j < ascii[i]; ++j) {  // print bar
        printf("X");
      }
      printf("\n");
    }
  }
}
