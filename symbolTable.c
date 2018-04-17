// Tanvi Aggarwal 2015A7PS0140P

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "parser.h"
#include "parserDef.h"
#include "lexer.h"
#include "symbolTable.h"

int hashFunction(char *c){
	int sum = 0;
	while(*c != '\0'){
		sum += (*c - '\0');
		c++;
	}
	return sum%100;
}

parseTree populateSymbolTable(parseTree root);
