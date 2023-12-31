#include <stdio.h>

#include "ch1.h"

int getLine(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0') {
    i++;
  }
}

void longest_line() {
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ( (len = getLine(line, MAXLINE)) > 0 ) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0){
    printf("longest line: %s", longest);
    printf("length: %d\n", max);
  }
}
