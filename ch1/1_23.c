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

// removes all lines starting /* but has no way to check for */ (closing appearing)
int removeMultilineComment(char line[]) {
  // index from which there is no comment
  int startPos = 0;
  int endPos = 0;

  // find if there is opening comment (do not search if not OUT of multiline comment)
  int i = 0;
  while (line[i] != '\0' && !openMultilineComment) {
    if (line[i] == '/') {
      if (line[i+1] == '*') {
        openMultilineComment = IN;
        startPos = i;
        break;
      }
    }

    i++;
  }

  // if outside comment just return the length
  if (!openMultilineComment) {
    return i;
  }

  // find if there is closing comment
  int j = 0;
  while (line[j] != '\n') {
    if (line[j] == '*') {
      if (line[j+1] == '/') {
        openMultilineComment = OUT;
        endPos = j + 1;
        break;
      }
    }
    j++;
  }

  // if inside multiline comment and no closing was found return just a newline, and it is open since index 0
  // "* nyanya\n"
  if (openMultilineComment && startPos == 0) {
    line[0] = '\n';
    line[1] = '\0';
    return 1;
  }

  // if not found a closing comment but a starting is, save the line before it
  // "int a = 1; /* nyanya\n"
  if (openMultilineComment) {
    line[startPos] = '\n';
    line[startPos+1] = '\0';
    return startPos + 1;
  }

  // !!!!!!!!!!
  // OUT openMultilineComment

  // if found a closing comment remove it leaving the rest of the line, and it started at index 0
  // "* lyalyalya */ int a = 1;\n"
  if (endPos != 0 && startPos == 0) {
    j = 0;
    int index = endPos + 1;
    while (line[index] != '\0') {
      line[j] = line[index];
      j++;
      index++;
    }

    line[j] = '\0';
    return j;
  }

  // if a multiline command is in the middle
  // int a = 1; /* nya */ int c = 2;
  if (startPos != 0 &&  endPos != 0) {
    j = startPos;
    int index = endPos + 1;
    while (line[index] != 0) {
      line[j] = line[index];
      index++;
      j++;
    }

    line[j] = '\0';

    //number of elements
    return j;
  }
}

void append(char main[], char sub[], int pos) {
  int i = 0;

  int index = pos;
  while (sub[i] != '\0') {
    main[index] = sub[i];
    i++;
    index++;
  }

  main[index] = '\0';
}

void removedComments() {
  char line[MAXLINE];

  char programResult[MAXLINE+MAXLINE];
  int pos = 0;

  while ( getLine(line, MAXLINE) > 0 ) {
    //printf("\nnew line: %s", line);

    removeSingleLineComment(line);
    //printf("uncommented single comments: %s", line);

    int newLineLen = removeMultilineComment(line);
    //printf("uncommented multiline comments: %s", line);

    append(programResult, line, pos);
    pos += newLineLen;
  }

  printf("\nuncommented program:\n%s", programResult);
}