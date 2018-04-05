// Tanvi Aggarwal 2015A7PS0140P

#include <stdlib.h>

#ifndef LEXERDEF_H
#define LEXERDEF_H

enum TokenType{MAIN, SQO, SQC, END, SEMICOLON, FUNCTION, ASSIGNOP, FUNID, ID, INT, REAL, STRING, MATRIX, COMMA, SIZE, IF, OP, CL, ELSE, ENDIF, READ, PRINT, PLUS, MINUS, MUL, DIV, NUM, RNUM, STR, AND, OR, NOT, LT, LE, EQ, GT, GE, NE, ENDOFINPUT, COMMENT};

typedef struct
{
	enum TokenType id;
	char *value;
	int lineNo;
	
}tokenInfo;

int lineNo;
int state;
int offset;

typedef int bufferSize;
typedef char *buffer;

#endif