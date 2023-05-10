#include <stdio.h>

#define TABSTOP 8       /* fixed set of tab stops every 2 columns */
#define MAXLINE 1000    /* maximum input line size */
#define MAXLINES 10000  /* maximum output line size */

int getline_new(char line[], int lim);
int copy(char to[], char from[], int index);

/* replace tabs with appropriate number of spaces */
int main(int argc, char *argv[]) {
  int len, index;
  char line[MAXLINE];
  char save[MAXLINES];

  index = 0;
  while ((len = getline_new(line, MAXLINE)) != EOF) {
    if (len > 0)
      index = copy(save, line, index);
  }
  printf("\n\nReplaced tabs with spaces:\n%s", save);
  return 0;
}

/* take a new line in and replace tabs with appropriate number of spaces */
int getline_new(char s[], int lim) {
  int c, i, j, diff;

  j = 0;
  for (i = 0; i <= lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    if (c == '\t') {
      diff = j % TABSTOP;
      while (diff < TABSTOP) {
        s[j] = ' ';
        ++j;
        ++diff;
      }
    } else {
      s[j] = c;
      ++j;
    }
  }
  s[j] = '\n';
  s[j + 1] = '\0';
  if (c == EOF) {
    return EOF;
  } else {
    return j;
  }
  return -1;
}

/* copy 'from' into 'to'; assume to is big enough */
int copy(char to[], char from[], int index) {
  int i;

  i = 0;
  while ((to[index] = from[i]) != '\0') {
    ++i;
    ++index;
  }
  return index;
}
