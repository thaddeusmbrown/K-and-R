#include <stdio.h>

#define MAXLINE 1000

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
  return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
