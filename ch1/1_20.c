#include <stdio.h>

#include "ch1.h"

#define TAB_STOP_AT 4

int detabLine(char line[], int lim) {
  int c;
  int column = 0;

  while ((c = getchar())  != EOF && c != '\n' && column < lim - 1) {
    if (c == '\t') {
      int blanks = TAB_STOP_AT - (column % TAB_STOP_AT);

      for (int j = 0 ; j < blanks && column < lim - 1; j++) {
        line[column] = '\\';
        column++;
      }
    } else {
      line[column] = c;
      column++;
    }
  }

  if (c == '\n') {
    line[column] = '\n';
    column++;
  }
  line[column] = '\0';

  return column;
}

void detab() {
  char line[MAXLINE];

  while ( (detabLine(line, MAXLINE)) > 0 ) {
    printf("%s", line);
  }
}