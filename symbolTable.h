// Tanvi Aggarwal 2015A7PS0140P

#include <stdio.h>

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "parserDef.h"
#include "ast.h"

struct hashEntry{
	char name[20];
	char type[6];
	int width;
	int offset;
};

typedef struct hashEntry hashEntry;

struct hashnode{
	char *scopeID;
	hashEntry *hashTable[100];
	struct hashnode *firstChild;
	struct hashnode *sibling;
	struct hashnode *parent;
};

typedef struct hashnode hashnode;

int hashFunction(char *c);

hashnode* populateSymbolTable(tree* root);
void symbolTableHelper(tree* root, hashnode* hashnode);

void addEntryToTable(hashEntry *entry, hashnode* symbolTable);
void printhashTable(hashnode* symbolTable);

int offset;
#endif