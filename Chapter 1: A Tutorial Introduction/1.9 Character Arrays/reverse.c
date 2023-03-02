#include <stdio.h>
#define MAXLINE 1000    // maximum input length
#define MAXLINES 10000  // maximum output length

int getline_new(char line[], int maxline);
void reverse(char s[], int i);
int copy(char to[], char from[], int index);

/* reverse lines in input */
int main(int argc, char *argv[]) {
  int len, index;
  char line[MAXLINE];
  char save[MAXLINES];

  index = 0;
  while ((len = getline_new(line, MAXLINE)) != EOF) {
    index = copy(save, line, index);
  }
  printf("\n\nReversed strings:\n%s", save);
  return 0;
}

/* getline_new:  read a line into s, return length */
int getline_new(char s[], int lim) {
  int c, i;
  
  for(i=0;i<=lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
  }

  reverse(s, i);

  if (c == EOF) {
    return EOF;
  } else {
    return i;
  }
}

void reverse(char s[], int i) {
  int j, end, tmp;

  j = 0;
  end = i - 1;
  for(j=0;j<=end/2;++j) {
    tmp = s[j];
    s[j] = s[end - j];
    s[end - j] = tmp;
  }
  s[i + 1] = '\0';
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
