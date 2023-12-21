#include <stdio.h>

#include "ch1.h"

void reverseLine(char line[], int length) {
  int i = 0;

  for (int j = length - 2; j >= i; j--) {
    char temp = line[i];
    line[i] = line[j];
    line[j] = temp;
    i++;
  }
}

void reversedLine() {
  int len;
  char line[MAXLINE];

  while ( (len = getLine(line, MAXLINE)) > 0 ) {
    reverseLine(line, len);
    printf("%s", line);
  }
}
