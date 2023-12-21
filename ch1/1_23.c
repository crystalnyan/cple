#include <stdio.h>

#include "ch1.h"

#define IN 1
#define OUT 0

int openDoubleQuote = OUT;
int openLineComment = OUT;
int openMultilineComment = OUT;

// 1. everything after // but not before is removed
// 2. anything inside "" should be immutable if it is outside  comments
// 3. everything inside /* is deleted, * starts a line inside this type of comment, */ but not * / closes it

// we assume the program has no errors regarding unclosed comments, etc.
// as the next exercise aims on checking that one

int removeSingleLineComment(char line[]) {
  int i = 0;
  while (line[i] != '\0') {

    // check for double quotes that cancel single line comment
    if (line[i] == '"' && !openLineComment) {
      if (!openDoubleQuote) {
        openDoubleQuote = IN;
      } else {
        openDoubleQuote = OUT;
      }

      i++;
      continue;
    }

    // if / appears check next char for / and  change state to openLineComment if needed
    if (line[i] == '/' && !openLineComment && !openDoubleQuote) {
      if (line[i+1] == '/') {
        openLineComment = IN;
      }
    }

    if (openLineComment) {
      line[i] = '\n';
      i++;
      line[i] = '\0';
      openLineComment = OUT;
    } else {
      i++;
    }
  }

  return i; // number of elements in the array after removing a comment
}

/*void append(char from[], char to[], int pos) {
  int i = 0;

  while (from[i] != '\0') {
    char[]
  }
}*/

void removedComments() {
  int len;
  char line[MAXLINE];

  //char programResult[MAXLINE+MAXLINE];
  //int pos = 0;

  while ( (len = getLine(line, MAXLINE)) > 0 ) {
    printf("\noriginal program:\n%s", line);

    int newLineLen = removeSingleLineComment(line);
    //append(line, programResult, pos);
    //pos += newLineLen;

    printf("\nuncommented program:\n%s", line);
  }
}