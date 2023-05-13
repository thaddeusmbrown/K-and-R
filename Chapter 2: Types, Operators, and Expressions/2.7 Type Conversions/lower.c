#include <stdio.h>

#define MAXLINE 14

int lower(int c);

int main(int argc, char *argv[]) {
  char in[MAXLINE] = "HeLlO, wOrLd.";
  char out[MAXLINE];

  for (int i = 0; i < MAXLINE; ++i) {
    out[i] = lower(in[i]);
  }
  printf("%s\n%s\n", in, out);
}

int lower(int c) {
  if (c >= 'A' && c <= 'Z')
    return c + 'a' - 'A';
  else
    return c;
}
