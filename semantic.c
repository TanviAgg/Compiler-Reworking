// Tanvi Aggarwal 2015A7PS0140P

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "parser.h"
#include "parserDef.h"
#include "lexer.h"
#include "symbolTable.h"
#include "typeChecker.h"
#include "semantic.h"

void semanticCheck(tree* ast, hashnode* hashnode);
