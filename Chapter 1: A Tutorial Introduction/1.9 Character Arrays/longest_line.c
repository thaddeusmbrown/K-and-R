#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int getline_new(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main(int argc, char *argv[]) {
  int len;                // current input line size
  int max;                // maximum length seen so far
  char line[MAXLINE];     // current input line
  char longest[MAXLINE];  // longest line saved here

  max = 0;
  while ((len = getline_new(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0)  // there was a line
    printf("\nlength: %d\n%s\n", max, longest);
  return 0;
}

/* getline_new:  read a line into s, return length */
int getline_new(char s[], int lim) {
  int c, i;

  for (i=0; i<=lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  if (i == lim - 1) {
    s[i-1] = '\n';
    s[i] = '\0';
    if (c != '\n') {  // 1000 length word
      s[i-1] = '\n';
      s[i] = '\0';
      ++i;
    } else {          // 999 length word
      ;
    }
  } else {            // <=998 length word
    s[i] = c;
    s[i] = '\0';
  }
  return i;
}

/* copy:  copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
