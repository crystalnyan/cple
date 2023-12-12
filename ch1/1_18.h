#include <stdio.h>

#define MAXLINE 1000

int trimLine(char line[], int length) {
  int i = length;

  for (int j = i - 2; j >= 0; j--) {
    if (line[j] == '\t' || line[j] == ' ') {
        i--;
        line[j] = '\n';
        line[j+1] = '\0';
    } else {
      break;
    }
  }

  return i;
}

int getTrimmedLine(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  i = trimLine(s, i);

  return i;
}

void trimmedLine() {
  int len;
  char line[MAXLINE];

  while ( (len = getTrimmedLine(line, MAXLINE)) > 0 ) {
      printf("trimmed: %s", line);
      printf("length: %d\n", len);
  }
}
