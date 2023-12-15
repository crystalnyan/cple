#include <stdio.h>

#include "ch1.h"

#define TAB_STOP_AT 4

void entabLine(char line[], char to[], int lim) {
  int blankCount = 0;
  int column = 0;
  int newColumn = 0;

  while (line[column] != '\0') {
    if (line[column] == ' '){
      blankCount++;

      int blanks = TAB_STOP_AT - (column % TAB_STOP_AT);

      for (int j = 1 ; j < blanks && column < lim - 1; j++) {

        if (blankCount == blanks) {
            continue;
        }

        if (line[column + j] == ' ') {
          blankCount++;
        }
      }

      if (blankCount == blanks) {
        to[newColumn] ='*';
        column += blankCount;
        newColumn++;
        blankCount = 0;
        continue;
      } else {
        to[newColumn] = ' ';
        column++;
        newColumn++;
      }


    } else {
      to[newColumn] = line[column];
      column++;
      newColumn++;
    }
  }

  to[column+1] = '\0';
}

void entab() {
  char line[MAXLINE];
  char result[MAXLINE];

  while ( getLine(line, MAXLINE) > 0 ) {
    entabLine(line, result, MAXLINE);
    printf("RES: %s", result);
  }

}