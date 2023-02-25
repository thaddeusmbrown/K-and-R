#include <stdio.h>

/* print a horizontal histogram of word length of input.
This will accept words with max length of twenty since I do 
not know how to work with arrays that might need to be increased
in size */
main()
{
  int c, i, j, length;
  int wlength[20];

  for (i = 0; i < 20; ++i) {
    wlength[i] = 0;
  }

  length = 0;
  while ((c = getchar()) != EOF) {
    if (!(c == ' ' || c == '\n' || c == '\t')) {        // find start of a word
      ++length;
      c = getchar();
      while (!(c == ' ' || c == '\n' || c == '\t')) {   // loop through word, keeping track of length
        ++length;
        c = getchar();
      }
      ++wlength[length - 1];                                // increment word count of that length and reset
      length = 0;
    }
  }
  printf("Word Length Histogram\n");
  for (i = 0; i < 20; ++i) {
    printf("%3d: |", i + 1);
    for (j = 0; j < wlength[i]; ++j) {
      printf("X");
    }
    printf("\n");
  }
}
