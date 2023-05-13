#include <stdio.h>

/* squeeze:  delete all c from s */
void squeeze(char s[], int c);

int main(int argc, char *argv[]) {
  char c = 'l',
       s[1000] = "Hello, World.";

  printf("Input:  %s\n", s);
  squeeze(s, c);
  printf("Output: %s\n", s);
}

void squeeze(char s[], int c) {
  int i, j;

  for (i = j = 0; s[i] != '\0'; i++)
    if (s[i] != c)
      s[j++] = s[i];
  s[j] = '\0';
}
