// Tanvi Aggarwal 2015A7PS0140P

#include <stdio.h>

#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "parserDef.h"
#include "ast.h"
#include "symbolTable.h"
#include "typeChecker.h"

void semanticCheck(tree* ast, hashnode* hashnode);


#endif