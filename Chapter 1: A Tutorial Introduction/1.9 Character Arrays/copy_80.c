#include <stdio.h>
#define MAXLINELENGTH 1000 /* maximum input line size */
#define MINLENGTH 81 /* minimum length of word*/
#define MAXPRINTLINE 10000 /* maximum length of string for printed lines */

int getline_new(char line[], int maxline);
int copy(char to[], char from[], int index);

/* print all lines longer than 80 characters (not including new line and null) and less than 1000 characters */
int main(int argc, char *argv[]) {
  int len, index;                // current input line size
  char line[MAXLINELENGTH];     // current input line
  char printlines[MAXPRINTLINE];  // saved lines here

  index = 0;
  while ((len = getline_new(line, MAXLINELENGTH)) > 0)
    if (len >= MINLENGTH) {
      index = copy(printlines, line, index);
    }
  printlines[index+1] = '\0';
  printf("Lines longer than %d characters:\n%s\n", MINLENGTH - 1, printlines); // print
  return 0;
}

/* getline_new:  read a line into s, return length */
int getline_new(char s[], int lim) {
  int c, i;

  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) 
    s[i]=c;
  if (c == '\n') {
    s[i] = c;
  }
  s[i] = '\0';
  return i;
}

/* copy:  copy 'from' into 'to'; assume to is big enough */
int copy(char to[], char from[], int index) {
  int from_i;
  from_i = 0;
  while ((to[index] = from[from_i]) != '\n' && index < MAXPRINTLINE - 1) {
    ++index;
    ++from_i;
  }
  ++index;
  return index;
}
