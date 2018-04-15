// Tanvi Aggarwal 2015A7PS0140P

#include <stdio.h> 
#include <stdlib.h>

#ifndef PARSERDEF_H
#define PARSERDEF_H
#define numberNonterminals 44
#define numberTerminals 39 //exclusing eps, including ENDOFINPUT
#define numberRules 86

int FirstsTable[numberTerminals+numberNonterminals+1][numberTerminals+1];  //extra for eps
int FollowsTable[numberNonterminals][numberTerminals];
int ParseTable[numberNonterminals][numberTerminals];

struct node;
typedef struct node node;
struct node{
	int data;
	node *next;
};

node grammar[numberRules];

typedef struct node stack;

stack *top;
int pop();
void push(int);
void push_rhs(int);

struct tree{
	int id;
	struct tree *firstChild;
	struct tree *sibling;
	char *lexeme;
	struct tree *parent;
	int lineNo;
	int ruleUsed;
};

typedef struct tree tree;
typedef struct tree *parseTree;

// parseTree root;
#endif