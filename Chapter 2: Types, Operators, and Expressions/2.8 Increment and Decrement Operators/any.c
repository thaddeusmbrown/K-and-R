#include <stdio.h>

/* any:  returns first location in s1 where any character from s2 occurs, or -1 if s1 contains no characters from s2 */
int any(char s1[], char s2[]);

int main(int argc, char *argv[]) {
  char s1[100] = "Hello, World.";
  char s2[100] = "It was the best of times.  It was the worst of times.";
  int index;

  printf("s1: %s\n", s1);
  printf("s2: %s\n", s2);
  index = any(s1, s2);
  if (index >= 0) {
    printf("The first char in s2 that is present in s1 is '%c', which occurs at index %d.\n", s1[index], index);
  } else {
    printf("There is no char in s2 that matches a char in s1.\n");
  }
}

int any(char s1[], char s2[]) {
  int i = 0,
      j = 0,
      index = -1;

  while (s1[i]) {
    while (s2[j]) {
      if (s1[i] == s2[j] && index == -1) {
        index = i;
      }
      ++j;
    }
    ++i;
    j = 0;
  }
  return index;
}
