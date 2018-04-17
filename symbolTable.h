// Tanvi Aggarwal 2015A7PS0140P

#include <stdio.h>

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "parserDef.h"
#include "ast.h"

struct hashEntry{
	char *name;
	char *type;
	int width;
	int offset;
};

typedef struct hashEntry hashEntry;

struct hashnode{
	char *scopeID;
	hashEntry *hashtable[100];
	struct hashnode *firstChild;
	struct hashnode *sibling;
	struct hashnode *parent;
};

typedef struct hashnode hashnode;

int hashFunction(char *c);

parseTree populateSymbolTable(parseTree root);


#endif