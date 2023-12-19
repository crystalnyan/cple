#include <stdio.h>

#include "ch1.h"

#define LIMIT 10

void foldLine(char line[], char  first[], char second[]) {
  int current = 0;
  int index = 0;

  // get first half upto nth exclusive
  while (current != LIMIT - 1) {
    first[index] = line[current];
    index++;
    current++;
  }

  first[LIMIT - 1] = '\n';
  first[LIMIT] = '\0';

  trimLine(first, LIMIT);

  index = 0;
  while (line[current] != '\0') {
    second[index] = line[current];
    index++;
    current++;
  }

  second[index] = '\0';
}

void fold() {
  int len;

  char line[MAXLINE];
  // two lines to hold each half AND '\n', '\0' at the end of each
  char first[LIMIT + 1];
  char second[MAXLINE];

  while ( (len = getLine(line, MAXLINE)) > 0 ) {
    if (len < LIMIT) {
      printf("LINE SHOULD BE LONGER THAN LIMIT. TRY AGAIN\n");
      continue;
    }

    foldLine(line, first, second);

    printf("\n\n--\n\n");

    printf("line: %s", line);
    printf("1st: %s", first);
    printf("2nd: %s", second);
  }
}