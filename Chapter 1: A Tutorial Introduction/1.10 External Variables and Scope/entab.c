#include <stdio.h>

#define TABSTOP 8       /* fixed set of tab stops every 2 columns */
#define MAXLINE 1000    /* maximum input line size */
#define MAXLINES 10000  /* maximum output line size */

int getline_new(char line[], int lim);
int copy(char to[], char from[], int index_out);

/* replace spaces with tabs and minimum number of spaces */
int main(int argc, char *argv[]) {
  int len, index_out;
  char line[MAXLINE];   /* input line from terminal */
  char save[MAXLINES];  /* output line */

  index_out = 0;  /* index of output line; keeps track between input lines */
  while ((len = getline_new(line, MAXLINE)) != EOF)
    index_out = copy(save, line, index_out);
  printf("\n\nReplaced spaces with tabs and minimum number of spaces:\n%s", save);
  return 0;
}

/* take a new line in and replace spaces with tabs and minimum number of spaces */
int getline_new(char line[], int lim) {
  int next_char, index_in, index_out, space_count, tab_track;

  index_out = 0;
  space_count = 0;
  for (index_in = 0; index_in <= lim - 1 && (next_char = getchar()) != EOF && next_char != '\n'; ++index_in) {
    if (next_char == ' ') {
      ++space_count;
      printf("Index: %d\n", index_in);
      tab_track = index_in % TABSTOP - 1;
      while ((next_char = getchar()) == ' ') {
        ++space_count;
        ++index_in;
        // printf("Tracking Spaces 1: %d\n", space_count);
      }
      if (space_count >= TABSTOP - tab_track) {
        printf("Spaces: %d\n", space_count);
        printf("Tab Track: %d\n", tab_track);
        line[index_out] = '\t';
        space_count -= tab_track;
        ++index_out;
        // printf("Tracking Spaces 2: %d\n", space_count);
      }
      while (space_count >= TABSTOP) {
        line[index_out] = '\t';
        space_count -= TABSTOP;
        ++index_out;
        // printf("Tracking Spaces 3: %d\n", space_count);
      }
      while (space_count > 0) {
        line[index_out] = ' ';
        --space_count;
        ++index_out;
        // printf("Tracking Spaces 4: %d\n", space_count);

      }
      line[index_out] = next_char;
      ++index_out;
    } else {
      line[index_out] = next_char;
      ++index_out;
    }
  }

  /* put finishing touches on output line */
  line[index_out] = '\n';
  line[index_out + 1] = '\0';

  /* check if we're done, and if not, return the current output index so we know where to start adding to the output with the next input line */
  if (next_char == EOF) {
    return EOF;
  } else {
    return index_out;
  }
  return -1;
}

/* copy 'from' into 'to'; assume 'to' is big enough */
int copy(char to[], char from[], int index_out) {
  int index_in;

  index_in = 0;
  while ((to[index_in] = from[index_out]) != '\0') {
    ++index_in;
    ++index_out;
  }

  /* return index out so we know where to return to when we pick up with new input line */
  return index_out;
}