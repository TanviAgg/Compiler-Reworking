// Tanvi Aggarwal 2015A7PS0140P

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "parserDef.h"
#include "lexer.h"
//#include "lexer.c"

/*

FirstAndFollow  *ComputeFirstAndFollowSets(grammar G): This function takes as input the grammar G, computes FIRST and FOLLOW information and populates appropriate data structure. First and Follow set automation must be attempted, keeping in view the programming confidence and available time with you. 

The weight for the above is only 5 marks out of 45 marks reserved for stage 1 module. If a student opts  not to develop the module for computation of First and follow sets, then he/she can use the manually computed FIRST and FOLLOW sets, and populate in the appropriate data structures.

*/
int IDtoterm(int id, char *c){
	switch(id){
	case 0: strcpy(c, "mainFunction");
break;
	case 1: strcpy(c, "stmtsAndFunctionDefs");
break;
	case 2: strcpy(c, "moreStmtAndFunctionDefs");
break;
	case 3: strcpy(c, "stmtOrFunctionDef") ;
break;
	case 4: strcpy(c, "stmt") ;
break;
	case 5: strcpy(c, "functionDef") ;
break;
	case 6: strcpy(c, "parameter_list") ;
break;
	case 7: strcpy(c, "type") ;
break;
	case 8: strcpy(c, "remainingList");
break;
	case 9: strcpy(c, "declarationStmt") ;
break;
	case 10: strcpy(c, "var_list") ;
break;
	case 11: strcpy(c, "more_ids") ;
break;
	case 12: strcpy(c, "assignmentStmt_type1") ;
break;
	case 13: strcpy(c, "assignmentStmt_type2") ;
break;
	case 14: strcpy(c, "leftHandSide_singleVar") ;
break;
	case 15: strcpy(c, "leftHandSide_listVar");
break;
	case 16: strcpy(c, "rightHandSide_type1") ;
break;
	case 17: strcpy(c, "rightHandSide_type2"); 
break;
	case 18: strcpy(c, "sizeExpression") ;
break;
	case 19: strcpy(c, "ifStmt") ;
break;
	case 20: strcpy(c, "matchIfStmt");
break;
	case 21: strcpy(c, "otherStmts") ;
break;
	case 22: strcpy(c, "ioStmt") ;
break;
	case 23: strcpy(c, "funCallStmt");
break;
	case 24: strcpy(c, "inputParameterList") ;
break;
	case 25: strcpy(c, "listVar") ;
break;
	case 26: strcpy(c, "arithmeticExpression") ;
break;
	case 27: strcpy(c, "arithmeticTerm") ;
break;
	case 28: strcpy(c, "arithmeticExp") ;
break;
	case 29: strcpy(c, "arithmeticT") ;
break;
	case 30: strcpy(c, "factor") ;
break;
	case 31: strcpy(c, "operator_lowPrecedence") ;
break;
	case 32: strcpy(c, "operator_highPrecedence") ;
break;
	case 33: strcpy(c, "constrainedVars") ;
break;
	case 34: strcpy(c, "var") ;
break;
	case 35: strcpy(c, "matrix") ;
break;
	case 36: strcpy(c, "rows") ;
break;
	case 37: strcpy(c, "moreRows") ;
break;
	case 38: strcpy(c, "row");
break;
	case 39: strcpy(c, "remainingColElements");
break;
	case 40: strcpy(c, "matrixElement") ;
break;
	case 41: strcpy(c, "logicalOp") ;
break;
	case 42: strcpy(c, "booleanExpression") ;
break;
	case 43: strcpy(c, "relationalOp") ;
break;
	case 44: strcpy(c, "MAIN") ;
break;
	case 45: strcpy(c, "SQO") ;
break;
	case 46: strcpy(c, "SQC") ;
break;
	case 47: strcpy(c, "END") ;
break;
	case 48: strcpy(c, "SEMICOLON") ;
break;
	case 49: strcpy(c, "FUNCTION") ;
break;
	case 50: strcpy(c, "ASSIGNOP") ;
break;
	case 51: strcpy(c, "FUNID") ;
break;
	case 52: strcpy(c, "ID") ;
break;
	case 53: strcpy(c, "INT");
break;
	case 54: strcpy(c, "REAL") ;
break;
	case 55: strcpy(c, "STRING") ;
break;
	case 56: strcpy(c, "MATRIX") ;
break;
	case 57: strcpy(c, "COMMA") ;
break;
	case 58: strcpy(c, "SIZE") ;
break;
	case 59: strcpy(c, "IF") ;
break;
	case 60: strcpy(c, "OP") ;
break;
	case 61: strcpy(c, "CL") ;
break;
	case 62: strcpy(c, "ELSE") ;
break;
	case 63: strcpy(c, "ENDIF");
break;
	case 64: strcpy(c, "READ") ;
break;
	case 65: strcpy(c, "PRINT");
break;
	case 66: strcpy(c, "PLUS") ;
break;
	case 67: strcpy(c, "MINUS");
break;
	case 68: strcpy(c, "MUL") ;
break;
	case 69: strcpy(c, "DIV") ;
break;
	case 70: strcpy(c, "NUM") ;
break;
	case 71: strcpy(c, "RNUM");
break;
	case 72: strcpy(c, "STR") ;
break;
	case 73: strcpy(c, "AND") ;
break;
	case 74: strcpy(c, "OR") ;
break;
	case 75: strcpy(c, "NOT");
break;
	case 76: strcpy(c, "LT") ;
break;
	case 77: strcpy(c, "LE") ;
break;
	case 78: strcpy(c, "EQ") ;
break;
	case 79: strcpy(c, "GT") ;
break;
	case 80: strcpy(c, "GE") ;
break;
	case 81: strcpy(c, "NE") ;
break;
	case 82: strcpy(c, "ENDOFINPUT") ;
break;
	case 83: strcpy(c, "eps") ;
break;
	default:
	return -1;
}
}
int terminalToID(char *terminal){
	if(strcmp(terminal, "MAIN")==0) return 0;
	else if(strcmp(terminal, "SQO")==0) return 1;
	else if(strcmp(terminal, "SQC")==0) return 2;
	else if(strcmp(terminal, "END")==0) return 3;
	else if(strcmp(terminal, "SEMICOLON")==0) return 4;
	else if(strcmp(terminal, "FUNCTION")==0) return 5;
	else if(strcmp(terminal, "ASSIGNOP")==0) return 6;
	else if(strcmp(terminal, "FUNID")==0) return 7;
	else if(strcmp(terminal, "ID")==0) return 8;
	else if(strcmp(terminal, "INT")==0) return 9;
	else if(strcmp(terminal, "REAL")==0) return 10;
	else if(strcmp(terminal, "STRING")==0) return 11;
	else if(strcmp(terminal, "MATRIX")==0) return 12;
	else if(strcmp(terminal, "COMMA")==0) return 13;
	else if(strcmp(terminal, "SIZE")==0) return 14;
	else if(strcmp(terminal, "IF")==0) return 15;
	else if(strcmp(terminal, "OP")==0) return 16;
	else if(strcmp(terminal, "CL")==0) return 17;
	else if(strcmp(terminal, "ELSE")==0) return 18;
	else if(strcmp(terminal, "ENDIF")==0) return 19;
	else if(strcmp(terminal, "READ")==0) return 20;
	else if(strcmp(terminal, "PRINT")==0) return 21;
	else if(strcmp(terminal, "PLUS")==0) return 22;
	else if(strcmp(terminal, "MINUS")==0) return 23;
	else if(strcmp(terminal, "MUL")==0) return 24;
	else if(strcmp(terminal, "DIV")==0) return 25;
	else if(strcmp(terminal, "NUM")==0) return 26;
	else if(strcmp(terminal, "RNUM")==0) return 27;
	else if(strcmp(terminal, "STR")==0) return 28;
	else if(strcmp(terminal, "AND")==0) return 29;
	else if(strcmp(terminal, "OR")==0) return 30;
	else if(strcmp(terminal, "NOT")==0) return 31;
	else if(strcmp(terminal, "LT")==0) return 32;
	else if(strcmp(terminal, "LE")==0) return 33;
	else if(strcmp(terminal, "EQ")==0) return 34;
	else if(strcmp(terminal, "GT")==0) return 35;
	else if(strcmp(terminal, "GE")==0) return 36;
	else if(strcmp(terminal, "NE")==0) return 37;
	else if(strcmp(terminal, "ENDOFINPUT")==0) return 38;
	else if(strcmp(terminal, "eps")==0) return 39;
	else return -1;
}

int nonterminalToID(char *nonterminal){
	if(strcmp(nonterminal, "mainFunction")==0) return 0;
	else if(strcmp(nonterminal, "stmtsAndFunctionDefs")==0) return 1;
	else if(strcmp(nonterminal, "moreStmtAndFunctionDefs")==0) return 2;
	else if(strcmp(nonterminal, "stmtOrFunctionDef")==0) return 3;
	else if(strcmp(nonterminal, "stmt")==0) return 4;
	else if(strcmp(nonterminal, "functionDef")==0) return 5;
	else if(strcmp(nonterminal, "parameter_list")==0) return 6;
	else if(strcmp(nonterminal, "type")==0) return 7;
	else if(strcmp(nonterminal, "remainingList")==0) return 8;
	else if(strcmp(nonterminal, "declarationStmt")==0) return 9;
	else if(strcmp(nonterminal, "var_list")==0) return 10;
	else if(strcmp(nonterminal, "more_ids")==0) return 11;
	else if(strcmp(nonterminal, "assignmentStmt_type1")==0) return 12;
	else if(strcmp(nonterminal, "assignmentStmt_type2")==0) return 13;
	else if(strcmp(nonterminal, "leftHandSide_singleVar")==0) return 14;
	else if(strcmp(nonterminal, "leftHandSide_listVar")==0) return 15;
	else if(strcmp(nonterminal, "rightHandSide_type1")==0) return 16;
	else if(strcmp(nonterminal, "rightHandSide_type2")==0) return 17;
	else if(strcmp(nonterminal, "sizeExpression")==0) return 18;
	else if(strcmp(nonterminal, "ifStmt")==0) return 19;
	else if(strcmp(nonterminal, "matchIfStmt")==0) return 20;
	else if(strcmp(nonterminal, "otherStmts")==0) return 21;
	else if(strcmp(nonterminal, "ioStmt")==0) return 22;
	else if(strcmp(nonterminal, "funCallStmt")==0) return 23;
	else if(strcmp(nonterminal, "inputParameterList")==0) return 24;
	else if(strcmp(nonterminal, "listVar")==0) return 25;
	else if(strcmp(nonterminal, "arithmeticExpression")==0) return 26;
	else if(strcmp(nonterminal, "arithmeticTerm")==0) return 27;
	else if(strcmp(nonterminal, "arithmeticExp")==0) return 28;
	else if(strcmp(nonterminal, "arithmeticT")==0) return 29;
	else if(strcmp(nonterminal, "factor")==0) return 30;
	else if(strcmp(nonterminal, "operator_lowPrecedence")==0) return 31;
	else if(strcmp(nonterminal, "operator_highPrecedence")==0) return 32;
	else if(strcmp(nonterminal, "constrainedVars")==0) return 33;
	else if(strcmp(nonterminal, "var")==0) return 34;
	else if(strcmp(nonterminal, "matrix")==0) return 35;
	else if(strcmp(nonterminal, "rows")==0) return 36;
	else if(strcmp(nonterminal, "moreRows")==0) return 37;
	else if(strcmp(nonterminal, "row")==0) return 38;
	else if(strcmp(nonterminal, "remainingColElements")==0) return 39;
	else if(strcmp(nonterminal, "matrixElement")==0) return 40;
	else if(strcmp(nonterminal, "logicalOp")==0) return 41;
	else if(strcmp(nonterminal, "booleanExpression")==0) return 42;
	else if(strcmp(nonterminal, "relationalOp")==0) return 43;
	else return -1;
}

int termToID(char *term){
	if(strcmp(term, "mainFunction")==0) return 0;
	else if(strcmp(term, "stmtsAndFunctionDefs")==0) return 1;
	else if(strcmp(term, "moreStmtAndFunctionDefs")==0) return 2;
	else if(strcmp(term, "stmtOrFunctionDef")==0) return 3;
	else if(strcmp(term, "stmt")==0) return 4;
	else if(strcmp(term, "functionDef")==0) return 5;
	else if(strcmp(term, "parameter_list")==0) return 6;
	else if(strcmp(term, "type")==0) return 7;
	else if(strcmp(term, "remainingList")==0) return 8;
	else if(strcmp(term, "declarationStmt")==0) return 9;
	else if(strcmp(term, "var_list")==0) return 10;
	else if(strcmp(term, "more_ids")==0) return 11;
	else if(strcmp(term, "assignmentStmt_type1")==0) return 12;
	else if(strcmp(term, "assignmentStmt_type2")==0) return 13;
	else if(strcmp(term, "leftHandSide_singleVar")==0) return 14;
	else if(strcmp(term, "leftHandSide_listVar")==0) return 15;
	else if(strcmp(term, "rightHandSide_type1")==0) return 16;
	else if(strcmp(term, "rightHandSide_type2")==0) return 17;
	else if(strcmp(term, "sizeExpression")==0) return 18;
	else if(strcmp(term, "ifStmt")==0) return 19;
	else if(strcmp(term, "matchIfStmt")==0) return 20;
	else if(strcmp(term, "otherStmts")==0) return 21;
	else if(strcmp(term, "ioStmt")==0) return 22;
	else if(strcmp(term, "funCallStmt")==0) return 23;
	else if(strcmp(term, "inputParameterList")==0) return 24;
	else if(strcmp(term, "listVar")==0) return 25;
	else if(strcmp(term, "arithmeticExpression")==0) return 26;
	else if(strcmp(term, "arithmeticTerm")==0) return 27;
	else if(strcmp(term, "arithmeticExp")==0) return 28;
	else if(strcmp(term, "arithmeticT")==0) return 29;
	else if(strcmp(term, "factor")==0) return 30;
	else if(strcmp(term, "operator_lowPrecedence")==0) return 31;
	else if(strcmp(term, "operator_highPrecedence")==0) return 32;
	else if(strcmp(term, "constrainedVars")==0) return 33;
	else if(strcmp(term, "var")==0) return 34;
	else if(strcmp(term, "matrix")==0) return 35;
	else if(strcmp(term, "rows")==0) return 36;
	else if(strcmp(term, "moreRows")==0) return 37;
	else if(strcmp(term, "row")==0) return 38;
	else if(strcmp(term, "remainingColElements")==0) return 39;
	else if(strcmp(term, "matrixElement")==0) return 40;
	else if(strcmp(term, "logicalOp")==0) return 41;
	else if(strcmp(term, "booleanExpression")==0) return 42;
	else if(strcmp(term, "relationalOp")==0) return 43;
	else if(strcmp(term, "MAIN")==0) return 44;
	else if(strcmp(term, "SQO")==0) return 45;
	else if(strcmp(term, "SQC")==0) return 46;
	else if(strcmp(term, "END")==0) return 47;
	else if(strcmp(term, "SEMICOLON")==0) return 48;
	else if(strcmp(term, "FUNCTION")==0) return 49;
	else if(strcmp(term, "ASSIGNOP")==0) return 50;
	else if(strcmp(term, "FUNID")==0) return 51;
	else if(strcmp(term, "ID")==0) return 52;
	else if(strcmp(term, "INT")==0) return 53;
	else if(strcmp(term, "REAL")==0) return 54;
	else if(strcmp(term, "STRING")==0) return 55;
	else if(strcmp(term, "MATRIX")==0) return 56;
	else if(strcmp(term, "COMMA")==0) return 57;
	else if(strcmp(term, "SIZE")==0) return 58;
	else if(strcmp(term, "IF")==0) return 59;
	else if(strcmp(term, "OP")==0) return 60;
	else if(strcmp(term, "CL")==0) return 61;
	else if(strcmp(term, "ELSE")==0) return 62;
	else if(strcmp(term, "ENDIF")==0) return 63;
	else if(strcmp(term, "READ")==0) return 64;
	else if(strcmp(term, "PRINT")==0) return 65;
	else if(strcmp(term, "PLUS")==0) return 66;
	else if(strcmp(term, "MINUS")==0) return 67;
	else if(strcmp(term, "MUL")==0) return 68;
	else if(strcmp(term, "DIV")==0) return 69;
	else if(strcmp(term, "NUM")==0) return 70;
	else if(strcmp(term, "RNUM")==0) return 71;
	else if(strcmp(term, "STR")==0) return 72;
	else if(strcmp(term, "AND")==0) return 73;
	else if(strcmp(term, "OR")==0) return 74;
	else if(strcmp(term, "NOT")==0) return 75;
	else if(strcmp(term, "LT")==0) return 76;
	else if(strcmp(term, "LE")==0) return 77;
	else if(strcmp(term, "EQ")==0) return 78;
	else if(strcmp(term, "GT")==0) return 79;
	else if(strcmp(term, "GE")==0) return 80;
	else if(strcmp(term, "NE")==0) return 81;
	else if(strcmp(term, "ENDOFINPUT")==0) return 82;
	else if(strcmp(term, "eps")==0) return 83;
	else return -1;
}
void createFirstSet(char *firstsFile, int FirstsTable[][numberTerminals+1])
{
	FILE* fp = fopen(firstsFile, "r");
	if(fp == NULL)
		printf("Invalid file\n");
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *token;

	int i, j;

	while((read = getdelim(&line, &len,';', fp)) != -1){
		// printf("line--%s\n",line);
		token = strtok(line, ",");
		i = termToID(token);
		token = strtok(NULL,",");

		while(token){
			j = termToID(token)-44;
			// printf("%d, %s\n", j, token);
			if(j >= 0)
				FirstsTable[i][j] = 1;
			token = strtok(NULL,",");
		}
	}
	fclose(fp);
	// for(i = 44; i<84; i++){
	// 	FirstsTable[i][i-44] = 1;
	// }		
}
void createFollowSet(char *followsFile, int FollowsTable[][numberTerminals])
{

	FILE* fp = fopen(followsFile, "r");
	if(fp == NULL)
		printf("Invalid file\n");
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *token;

	int i, j;

	while((read = getdelim(&line, &len, ';',fp)) != -1){
		// printf("line--%s\n",line);
		token = strtok(line, ",");
		i = termToID(token);
		token = strtok(NULL,",");

		while(token){
			j = termToID(token)-44;
			if(j>=0)
				FollowsTable[i][j] = 1;
			token = strtok(NULL,",");
		}
	}	
	fclose(fp);
}
void readGrammar(char *grammarFile, node grammar[])
{
	FILE* fp = fopen(grammarFile, "r");
	if(fp == NULL)
		printf("Invalid file\n");
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *token;
	int nodeIndex = 0;
	int i, j;
	node *newNode, *newNode2;
	while((read = getdelim(&line, &len, ';',fp)) != -1){
		// printf("line--%s\n",line);
		token = strtok(line, ",");
		i = termToID(token);
		grammar[nodeIndex].data = i;
		token = strtok(NULL,",");
		j = termToID(token);
		if( j >= 0){
			newNode = (node*)malloc(sizeof(node));
			newNode->data = j;
			grammar[nodeIndex++].next = newNode;
		}			
		token = strtok(NULL,",");

		while(token){
			j = termToID(token);
			if( j >= 0){
				newNode2 = (node*)malloc(sizeof(node));
				newNode2->data = j;
				newNode->next = newNode2;
				newNode = newNode2;
			}			
			token = strtok(NULL,",");
		}
	}
	fclose(fp);	
}
/*

void createParseTable(FirstAndFollow F, table T): This function takes as input the FIRST and FOLLOW information above to populate the parse table T appropriately. Hand coded parse table will not be accepted.

*/
void createParseTable(int ParseTable[][numberTerminals])
{
	int i, j;
	for(i = 0; i < numberRules; i++){
		if(grammar[i].next->data != 83){
			for(j = 0; j < numberTerminals; j++){
				if(FirstsTable[grammar[i].next->data][j] == 1){
					ParseTable[grammar[i].data][j] = i+1;
				}
			}
		}
		else{
			for(j = 0; j < numberTerminals; j++){
				if(FollowsTable[grammar[i].data][j] == 1){
					ParseTable[grammar[i].data][j] = i+1;
				}
			}
		}
	}
}

int pop(){
	int v;
	stack *temp;
	if(top==NULL){
		printf("stack is empty!");
		return 0;
	}
	else{
		v = top->data;
		temp = top;
		top = top->next;
		free(temp);
		return v;
	}
}
void push(int val){
	stack *temp;
	temp = (stack *)malloc(sizeof(stack));

	temp->data = val;
	temp->next = top;
	top = temp;
}
void push_rhs(int rule){
	stack *temp, *temp2, *firstRule, *temp3;
	temp = (stack *)malloc(sizeof(stack));
	temp->data = grammar[rule].next->data;
	temp2 = grammar[rule].next->next;
	firstRule = temp;
	while(temp2){
		temp3 = (stack *)malloc(sizeof(stack));
		temp3->data = temp2->data;
		temp3->next = temp2->next;
		temp2 = temp2->next;
		temp->next = temp3;
		temp = temp3;
	}
	temp->next = top;
	top = firstRule;
}

void printStack(){
	stack * temp = top;
	printf("Stack: ");
	while(temp){
		printf("%d->",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

tree* expand_node(tree* node, int rule, int lineNo){
	tree *temp, *temp3;
	stack *temp2;

	temp = (tree*)malloc(sizeof(tree));
	temp->id = grammar[rule].next->data;
	temp->lineNo = lineNo;
	temp->ruleUsed = 0;
	temp->lexeme = NULL;
	temp->firstChild = NULL;
	temp->parent = node;
	node->firstChild = temp;

	temp2 = grammar[rule].next->next;
	while(temp2){
		temp3 = (tree*)malloc(sizeof(tree));
		temp3->lineNo = lineNo;
		temp3->ruleUsed = 0;
		temp3->id = temp2->data;
		temp3->lexeme = NULL;
		temp3->firstChild = NULL;
		temp3->sibling = NULL;
		temp3->parent = node;
		temp2 = temp2->next;
		temp->sibling = temp3;
		temp = temp3;
	}
	return node;
}

void printParseTree(tree* root){
	printf("%-20s%-8s%-10s%-14s%-24s%-20s%-20s\n","lexemeCurrentNode","LineNo","token","valueIfnumber", "parentNodeSymbol", "isLeafNode(yes/no)","NodeSymbol");
	tree* temp = root;
	if(temp->firstChild){
		printParseTreeHelper(temp->firstChild);
	}
	printf("%-20s%-8s%-10s%-14s%-24s%-20s%-20s\n", "----", "0", "----", "----", "ROOT", "no", "mainFunction");
	
	if(root->firstChild && root->firstChild->sibling){
		tree* temp2 = root->firstChild->sibling;
		while(temp2){
			printParseTreeHelper(temp2);
			temp2 = temp2->sibling;
		}
	}

}
void printParseTreeHelper(tree *root){
	if(root == NULL){
		return;
	}
	printParseTreeHelper(root->firstChild);
	
	char *c = (char*)malloc(sizeof(char)*20);
	memset(c,0,20);
	IDtoterm(root->id,c);
	char *d = (char*)malloc(sizeof(char)*20);
	memset(d,0,20);
	IDtoterm(root->parent->id,d);
	if(root->id > 43){
		if(root->id == 83){
			printf("%-20s%-8d%-10s%-14s%-24s%-20s%-20s\n","----", root->lineNo, c,"----", d, "yes", c);
		}
		else if(root->id == 70 || root->id ==71)
			printf("%-20s%-8d%-10s%-14s%-24s%-20s%-20s\n",root->lexeme, root->lineNo, c,root->lexeme, d, "yes", c);
		else{
			printf("%-20s%-8d%-10s%-14s%-24s%-20s%-20s\n",root->lexeme, root->lineNo, c,"----", d, "yes", c);
		}
	}
	else{
		printf("%-20s%-8d%-10s%-14s%-24s%-20s%-20s\n","----", root->lineNo, "----","----", d, "no", c);
	}
	if(root->firstChild && root->firstChild->sibling){
		tree* temp2 = root->firstChild->sibling;
		while(temp2){
			printParseTreeHelper(temp2);
			temp2 = temp2->sibling;
		}
	}
	return;
}

// void printParseTreeHelper(tree *root){
// 	if(root == NULL){
// 		return;
// 	}
// 	printParseTreeHelper(root->firstChild);
	
// 	char *c = (char*)malloc(sizeof(char)*20);
// 	memset(c,0,20);
// 	IDtoterm(root->id,c);
// 	char *d = (char*)malloc(sizeof(char)*20);
// 	memset(d,0,20);
// 	IDtoterm(root->parent->id,d);
// 	if(root->id > 43){
// 		if(root->id == 83){
// 			printf("%-5d%-20s%-8d%-10s%-14s%-24s%-20s%-20s\n",root->ruleUsed,"----", root->lineNo, c,"----", d, "yes", c);
// 		}
// 		else if(root->id == 70 || root->id ==71)
// 			printf("%-5d%-20s%-8d%-10s%-14s%-24s%-20s%-20s\n",root->ruleUsed,root->lexeme, root->lineNo, c,root->lexeme, d, "yes", c);
// 		else{
// 			printf("%-5d%-20s%-8d%-10s%-14s%-24s%-20s%-20s\n",root->ruleUsed,root->lexeme, root->lineNo, c,"----", d, "yes", c);
// 		}
// 	}
// 	else{
// 		printf("%-5d%-20s%-8d%-10s%-14s%-24s%-20s%-20s\n",root->ruleUsed,"----", root->lineNo, "----","----", d, "no", c);
// 	}
// 	if(root->firstChild && root->firstChild->sibling){
// 		tree* temp2 = root->firstChild->sibling;
// 		while(temp2){
// 			printParseTreeHelper(temp2);
// 			temp2 = temp2->sibling;
// 		}
// 	}
// 	return;
// }

void printNodeInfo(tree *node){
	char* c, *d, *e;
	c = (char*)malloc(sizeof(char)*20);
	memset(c,0,20);
	IDtoterm(node->id,c);
	printf("****ID - %s (%d), line no. - %d\n", c, node->id, node->lineNo);
	if(node->firstChild)
		printf("****child exists");
	if(node->lexeme)
		printf("****lexeme - %s\n", node->lexeme);
	if(node->sibling){
		memset(c,0,20);
		IDtoterm(node->sibling->id,c);
		printf("****sibling id - %s(%d), line no.- %d\n", c, node->sibling->id , node->sibling->lineNo );
	}
	memset(c,0,20);
	IDtoterm(node->parent->id,c);
	printf("****Parent id - %s(%d)\n",c, node->parent->id);
	printf("\n");

	return;

}

parseTree parseInputSourceCode(char *testcaseFile){
	char* b = (char*) malloc(sizeof(char)*20);
	int k = 20;
	FILE *fp = fopen(testcaseFile, "r");
	char inputToken[20];
	char expectedToken[20];
	//char testfile[100];
	//int inputsize = fread(testfile,1,100,fp);
	//printf("%s\n", testfile);
	//rewind(fp);
	int temp;
	memset(b,0,sizeof(b));
	tokenInfo L = getNextToken(fp, b, k); //getNextToken returns terminals between 0-39
	// printf("Token - %d, %s\n",L.id, L.value);
	push(termToID("ENDOFINPUT"));
	push(termToID("mainFunction"));
	parseTree root = (parseTree)malloc(sizeof(tree));
	root->id = L.id;
	root->lineNo = 0;
	root->lexeme = NULL;
	root->firstChild = NULL;
	root->parent = NULL;
	root->sibling = NULL;
	// printStack();

	// printNodeInfo(root);


	tree* temptree = root;

	while(L.id != (termToID("ENDOFINPUT")-44)){
		if(top->data < 44){
			if(ParseTable[top->data][L.id] != 0){
				temp =  pop();
				if(grammar[ParseTable[temp][L.id]-1].next->data != termToID("eps")){
					push_rhs(ParseTable[temp][L.id]-1);
					temptree->ruleUsed = ParseTable[temp][L.id];
					temptree = expand_node(temptree,ParseTable[temp][L.id]-1, L.lineNo)->firstChild;
					// tree* tocheck = temptree;
					// while(tocheck){
					// 	printNodeInfo(tocheck);
					// 	tocheck = tocheck->sibling;
					// }
					// printNodeInfo(temptree);
				}
				
				else{
					temptree->ruleUsed = ParseTable[temp][L.id];
					temptree = expand_node(temptree,ParseTable[temp][L.id]-1, L.lineNo);
					
					if(temptree->sibling)
						temptree = temptree->sibling;
					else{
						temptree = temptree->parent;
						while(temptree->sibling==NULL){
							temptree = temptree->parent;
						}
						temptree = temptree->sibling;
					}
				}
				// printStack();
			}
			else{
				// printStack();
				printf("Line number:%d Syntax error: No such rule available in grammar.\n",L.lineNo);
				errorInParser = 1;
				return root;
				// L = getNextToken(fp, b, k);
				// // printf("Token - %d, %s\n",L.id, L.value);

				// //find semicolon
				// while(L.id != 4){
				// 	L = getNextToken(fp, b, k);
				// 	// printf("Token - %d, %s\n",L.id, L.value);
				// }
			}
		}
		else if((top->data >= 44) && (top->data != termToID("ENDOFINPUT"))){
			if((top->data - 44) == L.id){

				temptree->lexeme = L.value;
				temptree->lineNo = L.lineNo;
				// printf("Printed after line 724\n");
				// printNodeInfo(temptree);
				
				if(temptree->sibling)
					temptree = temptree->sibling;
				else{
					temptree = temptree->parent;
					while(temptree->sibling==NULL){
						if(temptree->parent){
							temptree = temptree->parent;
						}
						else{
							break;
						}
					}
					temptree = temptree->sibling;
				}
				temp = pop();
				// printStack();
				L = getNextToken(fp, b, k);
				// printf("Token - %d, %s\n",L.id, L.value);

				//ignore Comment token
				while(L.id == 39){

					L = getNextToken(fp, b, k);
					// printf("Token - %d, %s\n",L.id, L.value);
				}
			}
			else{
				// printStack();
				idToTerminal(top->data-44,expectedToken);
				idToTerminal(L.id,inputToken);
				printf("Line number:%d Syntax error: %s (expected token) not equal to %s (input token).\n",L.lineNo, expectedToken, inputToken);
				errorInParser = 1;
				return root;
				// L = getNextToken(fp, b, k);
				// // printf("Token - %d, %s\n",L.id, L.value);

				// //find semicolon
				// while(L.id != 4){
				// 	L = getNextToken(fp, b, k);
				// 	// printf("Token - %d, %s\n",L.id, L.value);
				// }
			}
		}
		else if(top->data == termToID("ENDOFINPUT")){
			// printStack();
			printf("Line number:%d Syntax error: Token mismatch (Reached bottom of stack).\n", L.lineNo);
			errorInParser = 1;
			return root;
		}
		
	}
	if((L.id == (termToID("ENDOFINPUT")-44)) && (top->data != termToID("ENDOFINPUT"))){
		printf("Line number:%d Syntax error: Stack not empty.\n", L.lineNo);
		// printStack();
		errorInParser = 1;
		return root;
	}
	else if((L.id == (termToID("ENDOFINPUT")-44)) && (top->data == termToID("ENDOFINPUT"))){
		printf("Successful Compilation. Your code is syntactically correct.\n");
		// printStack();
		return root;
	}
	fclose(fp);
}


/*

parseTree   parseInputSourceCode(char *testcaseFile, table T): This function takes as input the source code file and parses using the rules as per the predictive parse table T. The function gets the tokens using lexical analysis interface and establishes the syntactic structure of the input source code using rules in T. The function must report all errors appropriately if the source code is syntactically incorrect. Error recovery must be implemented to list all errors. Parsers which report one error at a time and quit before listing all errors are considered bad, therefore students are advised to implement error recovery appropriately.

If the source code is correct then the token and all its relevant information is added to the parse tree. The start symbol of the grammar is the root of the parse tree and the tree grows as syntax analysis moves in top down way. 

The function must display a message "Input source code is syntactically correct..........." for successful parsing.

*/

/*

void printParseTree(parseTree PT, char *outfile): This function provides an interface for observing the correctness of the creation of parse tree. The function prints the parse tree in inorder in the file outfile. The output is such that each line of the file outfile must contain the information corresponding to the currently visited node of the parse tree in the following format:

lexemeCurrentNode  lineno token valueIfNumber parentNodeSymbol

isLeafNode(yes/no) NodeSymbol

The lexeme of the current node is printed when it is the leaf node else a dummy string of characters "‐‐‐‐" is printed. The line number is one of the information collected by the lexical analyzer during single pass of the source code. The token name corresponding to the current node is printed third. If the lexeme is an integer or real number, then its value computed by the lexical analyzer should be printed at the fourth place. Print the grammar symbol (non terminal symbol) of the parent node of the currently visited node appropriately at fifth place (for the root node print ROOT for parent symbol) . The sixth column is for printing yes or no appropriately. Print the non terminal symbol of the node being currently visited at the 7th place, if the node is not the leaf node [Print the actual nonterminal symbol and not the enumerated values for the nonterminal]. Ensure appropriate justification so that the columns appear neat and straight. 

*/
// void main(){
// 	//printf("%d", terminalToID("SQO"));
// 	createFirstSet("Ffirsts.txt", FirstsTable);
// 	createFollowSet("Ffollows.txt", FollowsTable);
// 	int i, j;
// 	for(i = 0; i < 84; i++ ){
// 		printf("%d:",i);
// 		for(j = 0; j<40; j++)
// 			if(FirstsTable[i][j]==1)
// 			printf("%d,",j);
// 		printf("\n");
// 	}
// 	printf("\n");
// 	printf("\n");
// 	for(i = 0; i < 44; i++ ){
// 		printf("%d:",i);
// 		for(j = 0; j<39; j++)
// 			if(FollowsTable[i][j]==1)
// 			printf("%d,",j);
// 		printf("\n");
// 	}
// 	printf("\n");
// 	printf("\n");
// 	readGrammar("Fgrammar.txt", grammar);
// 	// int i,j;
// 	node* temp;
// 	for(i = 0; i < numberRules; i++){
// 		printf("%d->",grammar[i].data);
// 		temp = grammar[i].next;
// 		while(temp){
// 			printf("%d,",temp->data);
// 			temp = temp->next;
// 		}
// 		printf("\n");
// 	}
// 	printf("\n");
// 	printf("\n");
// 	createParseTable(ParseTable);
// 	for(i = 0; i < 44; i++ ){
// 		printf("%d:",i);
// 		for(j = 0; j<39; j++)
// 			printf("%d,",ParseTable[i][j]);
// 		printf("\n");
// 	}
// 	printf("\n");
// 	printf("\n");
// 	 // parseInputSourceCode("revised_testcases/testcase5.txt");
// 	// printf("Testcase 1\n");

// 	// parseInputSourceCode("revised_testcases/testcase2.txt");
// 	// printf("Testcase 2\n");
// 	// parseInputSourceCode("revised_testcases/testcase3.txt");
// 	// printf("Testcase 3\n");
// 	// parseInputSourceCode("revised_testcases/testcase4.txt");
// 	// printf("Testcase 4\n");
// 	// parseInputSourceCode("revised_testcases/testcase5.txt");
// 	// printf("Testcase 5\n");
// 	parseInputSourceCode("testing.txt");
// 	return;
// }
void idToTerminal(int id, char*c){
	switch(id){
		case 0: strcpy(c,"MAIN");
			break;
		case 1: strcpy(c,"SQO");
		break;
 
		case 2: strcpy(c,"SQC");
		break;
 
		case 3: strcpy(c,"END");
		break;
 
		case 4: strcpy(c,"SEMICOLON");
		break;
 
		case 5: strcpy(c,"FUNCTION");
		break;
 
		case 6: strcpy(c,"ASSIGNOP");
		break;
 
		case 7: strcpy(c,"FUNID");
		break;

		case 8: strcpy(c,"ID");
		break;

		case 9: strcpy(c,"INT");
		break;

		case 10: strcpy(c,"REAL");
		break;

		case 11: strcpy(c,"STRING");
		break;
 
		case 12: strcpy(c,"MATRIX");
		break;
 
		case 13: strcpy(c,"COMMA");
		break;
 
		case 14: strcpy(c,"SIZE");
		break;
 
		case 15: strcpy(c,"IF");
		break;
 
		case 16: strcpy(c,"OP");
		break;
 
		case 17: strcpy(c,"CL");
		break;
 
		case 18: strcpy(c,"ELSE");
		break;
 
		case 19: strcpy(c,"ENDIF");
		break;
 
		case 20: strcpy(c,"READ");
		break;
 
		case 21: strcpy(c,"PRINT");
		break;
 
		case 22: strcpy(c,"PLUS");
		break;
 
		case 23: strcpy(c,"MINUS");
		break;
 
		case 24: strcpy(c,"MUL");
		break;
 
		case 25: strcpy(c,"DIV");
		break;
 
		case 26: strcpy(c,"NUM");
		break;
 
		case 27: strcpy(c,"RNUM");
		break;
 
		case 28: strcpy(c,"STR");
		break;
 
		case 29: strcpy(c,"AND");
		break;
 
		case 30: strcpy(c,"OR");
		break;
 
		case 31: strcpy(c,"NOT");
		break;
 
		case 32: strcpy(c,"LT");
		break;
 
		case 33: strcpy(c,"LE");
		break;
 
		case 34: strcpy(c,"EQ");
		break;
 
		case 35: strcpy(c,"GT");
		break;
 
		case 36: strcpy(c,"GE");
		break;
 
		case 37: strcpy(c,"NE");
		break;
 
		case 38: strcpy(c,"ENDOFINPUT");
		break;
 
		case 39: strcpy(c,"COMMENT");
		break;
	}
}
