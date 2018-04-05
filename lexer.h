// Tanvi Aggarwal 2015A7PS0140P

#include <stdio.h>
#include "lexerDef.h"

#ifndef LEXER_H
#define LEXER_H

FILE *getStream(FILE *fp, buffer buff, bufferSize k);

tokenInfo getNextToken(FILE *fp, buffer buff, bufferSize k);

void removeComments(char *testcaseFile);

int errorInLexer;

#endif