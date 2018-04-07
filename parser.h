// Tanvi Aggarwal 2015A7PS0140P

#include <stdio.h>

#ifndef PARSER_H
#define PARSER_H

#include "parserDef.h"
int termToID(char *term);
int terminalToID(char *terminal);
int nonterminalToID(char *nonterminal);
void idToTerminal(int id, char*c);

void createFirstSet(char *firstsFile, int FirstsTable[][numberTerminals+1]);
void createFollowSet(char *followsFile, int FollowsTable[][numberTerminals]);
void readGrammar(char *grammarFile, node grammar[]);
void createParseTable(int ParseTable[][numberTerminals]);

parseTree parseInputSourceCode(char *testcaseFile);
//parseTree parseInputSourceCode(char *testcaseFile, int ParseTable[][numberTerminals]);
void printParseTree(parseTree PT);
void printParseTreeHelper(parseTree pt);

int errorInParser;

#endif