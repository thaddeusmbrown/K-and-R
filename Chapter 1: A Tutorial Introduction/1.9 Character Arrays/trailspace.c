#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */
#define MAXLINES 10000 /* maximum output line size */

int getline_new(char line[], int maxline);
int copy(char to[], char from[], int index);

/* remove trailing white space and blank lines */
int main(int argc, char *argv[]) {
  int len, index;
  char line[MAXLINE];
  char save[MAXLINES];

  index = 0;
  while ((len = getline_new(line, MAXLINE)) != EOF) {
    if (len > 0)
      index = copy(save, line, index);
  }
  printf("\n\nRemoved trailing whitespace and blank lines:\n%s", save);
  return 0;
}

/* getline_new: read a line into s, return length */
int getline_new(char s[], int lim) {
  int c, i, j, index_last, white_space;

  for(i=0;i<=lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
  }

  index_last = 0; // index of first white-space character
  white_space = 0; // white space bit
  for(j=0;j<=i;++j) {
    if (s[j] == ' ' || s[j] == '\t') {
      if (white_space == 0){
        index_last = j;
        white_space = 1;
      }
    } else if (white_space == 1) {
      index_last = j;
      white_space = 0;
    } else {
      index_last = j;
    }
  }
  s[index_last] = '\n';
  s[index_last + 1] = '\0';
  if (c == EOF) {
    return EOF;
  } else {
    return index_last;
  }
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
