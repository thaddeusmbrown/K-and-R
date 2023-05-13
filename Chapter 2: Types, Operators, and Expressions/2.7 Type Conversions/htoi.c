#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

long int htoi(char s[]);

int main(int argc, char *argv[]) {
  char in[MAXLINE] = "0x0123456789AbCdEf";
  long int out = htoi(in);

  printf("Input: %s\nInteger Output: %ld\nHexadecimal Output: %lx\n", in, out, out);
}

long int htoi(char s[]) {
  int start_index, i;
  long int n;

  if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    start_index = 2;
  else
    start_index = 0;

  n = 0;
  for (i = start_index; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'); ++i) {
    if (s[i] >= '0' && s[i] <= '9')
      n = 16 * n + (s[i] - '0');
    else
      n = 16 * n + (toupper(s[i]) - 55);
  }
  return n;
}
