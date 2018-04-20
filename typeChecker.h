// Tanvi Aggarwal 2015A7PS0140P

#include <stdio.h>

#ifndef TYPECHECKER_H
#define TYPECHECKER_H

#include "parserDef.h"
#include "ast.h"
#include "symbolTable.h"

void typeCheck(tree* ast, hashnode* hashnode);

#endif