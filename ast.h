// Tanvi Aggarwal 2015A7PS0140P

#include <stdio.h>

#ifndef AST_H
#define AST_H

#include "parserDef.h"

parseTree createAST(parseTree root);
tree* createASTHelper(parseTree root);
void countNumberOfNodesAST(parseTree root);

int numberNodesAST;

#endif