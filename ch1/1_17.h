#include <stdio.h>

#define MAXLINE 1000
#define MINLINE 80

void eighty_plus() {
  int len;
  char line[MAXLINE];
  char longest[MAXLINE];

  while ( (len = getLine(line, MAXLINE)) > 0 ) {
    if (len > MINLINE) {
      printf("%s", line);
    }
  }
}
