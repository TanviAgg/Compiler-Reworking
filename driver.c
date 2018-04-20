// Tanvi Aggarwal 2015A7PS0140P

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "lexer.h"
#include "parser.h"
#include "ast.h"
#include "symbolTable.h"

void idToTerm(int id, char*c){
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
void printAllTokens(char *inputfile){
	char* b = (char*) malloc(sizeof(char)*20);
	memset(b,0,20);
	int k = 20;
	FILE *fp = fopen(inputfile, "r");
	lineNo = 1;
	state = 0;
	printf("------------------------------------\n");
	printf("%-10s%-20s%-20s\n","Line no.","Lexeme","Token");
	
	char *c = (char*)malloc(sizeof(char)*12);
	memset(c,0,12);
	tokenInfo t = getNextToken(fp, b, k);
	idToTerm(t.id, c);
	printf("%-10d%-20s%-20s\n", t.lineNo, t.value, c);

	while(t.id != 38 ){
		t = getNextToken(fp, b, k);
		memset(c,0,12);
		idToTerm(t.id, c);
		printf("%-10d%-20s%-20s\n", t.lineNo, t.value, c);
	}
	printf("------------------------------------\n");
	fclose(fp);
}
int main(int argc, char const *argv[])
{
	if(argc < 2){
		printf("Insufficient arguments provided\n");
	}
	printf("**********************************************************\n\n");
	printf("NOTE: Since AST is made by changing parseTree in-place,\nprinting parseTree after printing AST is not possible.\nPlease run the code again, or enter options in strictly increasing order.\n");
	// printf("(b) testcase1.txt fails for option 3. All options work for other testcases.\n");
	// printf("(c) removeComments, Lexer, ParseInputSourceCode - work correctly.\n");
	printf("\n********************************************************\n\n");
	
	int choice;
	char filename[30];
	strcpy(filename,argv[1]);
	createFirstSet("Ffirsts.txt", FirstsTable);
	// printf("Firsts table made successfully!\n");
	createFollowSet("Ffollows.txt", FollowsTable);
	// printf("Follows table made successfully!\n");
	readGrammar("Fgrammar.txt", grammar);
	
	createParseTable(ParseTable);
	// printf("Parse table made successfully!\n");
	
	int parseTreeCreated = 0;
	int ASTcreated = 0;
	int symbolTableCreated = 0;
	tree* temp2, *temp3, *temp5;
	
	while(1){
		
		printf("------------------------------------\n");
		printf("Press a number to choose the corresponding option:\n");
		printf("------------------------------------\n");
		printf("Press 0 to exit.\n");
		printf("Press 1 to see the list of tokens generated by lexer.\n");
		printf("Press 2 for parsing to verify syntactic correctness of input source code and printing parse tree.\n");
		printf("Press 3 for printing abstract syntax tree.\n");
		printf("Press 4 to display amount of allocated memory and number of nodes.\n");
		printf("Press 5 to print the symbol table.\n");
		printf("Press 6 for compiling to verify the syntactic and semantic correctness.\n");
		printf("Press 7 for producing assembly line code.\n");
		
		printf("------------------------------------\n");
		scanf("%d", &choice);
		
		if(choice==0){
			break;
		}
		else if(choice==1){
			printAllTokens(filename);
		}
		else if(choice==2){
			temp2 = parseInputSourceCode(filename);
			parseTreeCreated = 1;
			if(errorInParser == 0){
				printf("Successful Compilation. Your code is syntactically correct.\n");				
			}
			printf("Printing parse tree \nOrder of traversal - Inorder (FirstChild - root - otherChildren)\n");

			printf("------------------------------------\n");
			printf("\n");
			printParseTree(temp2);
			printf("\n");
			printf("------------------------------------\n");
			
		}
		else if(choice==3){
			if(parseTreeCreated){
				temp3 = temp2;
				temp3 = createASTHelper(temp3);	
				ASTcreated = 1;
			}
			else{
				temp2 = parseInputSourceCode(filename);
				parseTreeCreated = 1;
				temp3 = temp2;
				temp3 = createASTHelper(temp3);	
				ASTcreated = 1;			
			}

			printf("Printing abstract syntax tree \nOrder of traversal - Inorder (FirstChild - root - otherChildren)\n");
			printf("------------------------------------\n");
			printf("\n");
			printParseTree(temp3);
			printf("\n");
			printf("------------------------------------\n");
			
		}
		else if(choice==4){
			if(!ASTcreated){
				if(parseTreeCreated){
					temp3 = temp2;
					temp3 = createASTHelper(temp3);	
					ASTcreated = 1;
				}
				else{
					temp2 = parseInputSourceCode(filename);
					parseTreeCreated = 1;
					temp3 = temp2;
					temp3 = createASTHelper(temp3);	
					ASTcreated = 1;		
				}	
			}
			printf("Memory allocated and number of nodes: \n Number of nodes in parse tree = %d \t Memory Allocated = %ld Bytes \n Number of nodes in AST = %d \t Memory Allocated = %ld Bytes \n Compression percentage = %f.\n",numberNodesParseTree, numberNodesParseTree*sizeof(tree), numberNodesAST, numberNodesAST*sizeof(tree), (float)(numberNodesParseTree-numberNodesAST)/numberNodesParseTree*100);
			
			
		}
		else if(choice==5){
			if(!ASTcreated){
				if(parseTreeCreated){
					temp3 = temp2;
					temp3 = createASTHelper(temp3);	
					ASTcreated = 1;
				}
				else{
					temp2 = parseInputSourceCode(filename);
					parseTreeCreated = 1;
					temp3 = temp2;
					temp3 = createASTHelper(temp3);	
					ASTcreated = 1;		
				}	
			}
			temp5 = temp3;
			printf("------------------------------------\n");
			
			hashnode* h = populateSymbolTable(temp5);
			symbolTableCreated = 1;
			printf("------------------------------------\n");

			printf("Printing symbolTables\n");
			printf("------------------------------------\n");

			printf("%-20s%-20s%-15s%-25s%-10s%-10s%-10s\n","Identifier_name", "Scope", "Nesting_Level", "Parent_of_current_scope", "Type", "Width", "Offset");
	
			printhashTable(h);			
			printf("------------------------------------\n");

		}
		else if(choice==6){
			if(parseTreeCreated){
				if(errorInParser == 0)
				printf("syntactically correct\n");
			}
			
		}
		else if(choice==7){
			printf("NOT IMPLEMENTED YET\n");
			
		}
		else{
			printf("Please enter valid option (0-7).\n");
		}	

	}
	return 0;
}