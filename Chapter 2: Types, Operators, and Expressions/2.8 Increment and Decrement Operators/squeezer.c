#include <stdio.h>

/* squeeze:  delete all chars from s2 from s1 */
void squeeze(char s1[], char s2[]);

int main(int argc, char *argv[]) {
  char s1[100] = "Hello, World.",
       s2[100] = "lor,!!!";

  printf("Input:  %s\n", s1);
  squeeze(s1, s2);
  printf("Output: %s\n", s1);
}

void squeeze(char s1[], char s2[]) {
  int i, j, k;
  int match = 0;

  for (i = j = 0; s1[i] != '\0'; i++) {
    for (k = 0; s2[k] != '\0'; k++) {
      if (s1[i] == s2[k]) {
        match = 1;
      }
    }
    if (!match) {
      s1[j++] = s1[i];
    }
    match = 0;
  }
  s1[j] = '\0';
}
