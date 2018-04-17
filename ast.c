// Tanvi Aggarwal 2015A7PS0140P

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "parser.h"
#include "parserDef.h"
#include "lexer.h"

//This function takes parsetree as input and creates AST in-place (it reuses nodes from parsetree)
void createASTHelper(parseTree root){
	tree* temp = root;
	createAST(root);
	printf("created AST successfully.\n");
	// printNodeInfo(temp->firstChild);
	printParseTree(temp);
	// printParseTree(root);
}
// void createAST(parseTree root){
// 	// printParseTree(root);
// 	char * c = (char*)malloc(sizeof(char)*20);
// 	// memset(c,0,20);
// 	// IDtoterm(root->id, c);
// 	// printf("Node id %s\n", c );
// 	if(root==NULL){
// 		printf("reaching here\n");
// 		return;
// 	}
// 	// switch(root->ruleUsed){
// 	// 	case 0:
// 	// 		temp = root->firstChild;
// 	// 		free(root);
// 	// 		createAST(temp);
// 	// 		break;
// 	// 	case 1:
// 	// 		break;
// 	// 	case 2:
// 	// 		break;
// 	// 	case 3:
// 	// 		break;
// 	// 	case 4:
// 	// 		break;
// 	// 	case 5:
// 	// 		break;
// 	// 	case 6:
// 	// 		break;
// 	// 	case 7:
// 	// 		break;
// 	// 	case 8:
// 	// 		break;
// 	// 	case 9:
// 	// 		break;
// 	// 	case 10:
// 	// 		break;
// 	// 	case 11:
// 	// 		break;
// 	// 	case 12:
// 	// 		break;
// 	// 	case 13:
// 	// 		break;
// 	// 	case 14:
// 	// 		break;
// 	// 	case 15:
// 	// 		break;
// 	// 	case 16:
// 	// 		break;
// 	// 	case 17:
// 	// 		break;
// 	// 	case 18:
// 	// 		break;
// 	// 	case 19:
// 	// 		break;
// 	// 	case 20:
// 	// 		break;
// 	// 	case 21:
// 	// 		break;
// 	// 	case 22:
// 	// 		break;
// 	// 	case 23:
// 	// 		break;
// 	// 	case 24:
// 	// 		break;
// 	// 	case 25:
// 	// 		break;
// 	// 	case 26:
// 	// 		break;
// 	// 	case 27:
// 	// 		break;
// 	// 	case 28:
// 	// 		break;
// 	// 	case 29:
// 	// 		break;
// 	// 	case 30:
// 	// 		break;
// 	// 	case 31:
// 	// 		break;
// 	// 	case 32:
// 	// 		break;
// 	// 	case 33:
// 	// 		break;
// 	// 	case 34:
// 	// 		break;
// 	// 	case 35:
// 	// 		break;
// 	// 	case 36:
// 	// 		break;
// 	// 	case 37:
// 	// 		break;
// 	// 	case 38:
// 	// 		break;
// 	// 	case 39:
// 	// 		break;
// 	// 	case 40:
// 	// 		break;
// 	// 	case 41:
// 	// 		break;

// 	// }
// 	// return;
// 	if(root->sibling == NULL && root->firstChild != NULL){
// 		if(root->id == 0 || root->id == 5 || root->id == 9 || root->id == 12 || root->id == 13 || root->id == 19 ||root->id == 22 || root->id == 23){
// 			memset(c,0,20);
// 			IDtoterm(root->id, c);
// 			// printf("Node id %s\n", c );
	
// 			printf("skipped this node - %s\n", c);
// 			createAST(root->firstChild);
// 			// printParseTree(root);

// 		}
// 		else{
// 			root->parent->firstChild = root->firstChild;
// 			root->firstChild->parent = root->parent;
// 			tree* temp = root->firstChild->sibling;
// 			while(temp){
// 				temp->parent = root->parent;
// 				temp = temp->sibling;
// 			}
// 			tree* temp2 = root->firstChild;
// 			memset(c,0,20);
// 			IDtoterm(root->id, c);
// 			printf("shifted children of this node upwards - %s\n", c);
// 			free(root);

// 			createAST(temp2);
// 			// printParseTree(root);
			
// 			// free(root);
// 		}
// 	}
// 	else if(root->sibling == NULL && root->firstChild == NULL){
// 		if(root->id == 50 || root->id == 51 || root->id == 52 || root->id == 53 || root->id == 54 || root->id == 55 ||root->id == 58 || root->id == 59 || root->id == 64 || root->id == 65 || root->id == 66 || root->id == 67 || root->id == 68 || root->id == 69 ||root->id == 70 || root->id == 71 || root->id == 72 || root->id == 73 || root->id == 74 || root->id == 75 || root->id == 76 || root->id == 77 ||root->id == 78 || root->id == 79||root->id == 80 || root->id == 81 ){
// 			memset(c,0,20);
// 			IDtoterm(root->id, c);
// 			printf("useful terminal - %s\n", c);			
// 		}
// 		else{
// 			root->parent->firstChild = NULL;
// 			memset(c,0,20);
// 			IDtoterm(root->id, c);
// 			printf("removed useless terminal - %s\n", c);
// 			free(root);

// 			// printParseTree(root);

// 			// free(root);
// 		}

// 	}
// 	else if(root->firstChild == NULL){
// 		if(root->id == 50 || root->id == 51 || root->id == 52 || root->id == 53 || root->id == 54 || root->id == 55 ||root->id == 58 || root->id == 59 || root->id == 64 || root->id == 65 || root->id == 66 || root->id == 67 || root->id == 68 || root->id == 69 ||root->id == 70 || root->id == 71 || root->id == 72 || root->id == 73 || root->id == 74 || root->id == 75 || root->id == 76 || root->id == 77 ||root->id == 78 || root->id == 79||root->id == 80 || root->id == 81 ){
// 			memset(c,0,20);
// 			IDtoterm(root->id, c);
// 			printf("useful terminal, moving to sibling - %s\n", c);
			
// 			createAST(root->sibling);
// 			// printParseTree(root);

// 		}
// 		else{
// 			root->parent->firstChild = root->sibling;
// 			tree *temp = root->sibling;
// 			memset(c,0,20);
// 			IDtoterm(root->id, c);
// 			printf("removed useless terminal and moving to sibling - %s\n", c);
// 			free(root);

// 			createAST(temp);
// 			// printParseTree(root);

// 			// free(root);

// 		}
// 	}
// 	else{
// 		memset(c,0,20);
// 		IDtoterm(root->id, c);
// 		printf("going to sibling now - %s\n", c);

// 		createAST(root->sibling);
// 		printf("going to firstChild now - %s\n", c);

// 		createAST(root->firstChild);
// 		// printParseTree(root);

// 	}
// }
parseTree createAST(parseTree root){
	// printParseTree(root);
	char * c = (char*)malloc(sizeof(char)*20);
	// memset(c,0,20);
	// IDtoterm(root->id, c);
	// printf("Node id %s\n", c );
	if(root==NULL){
		printf("reaching here\n");
		return;
	}
	if(root->sibling == NULL && root->firstChild != NULL){
		if(root->id == 0 || root->id == 5 || root->id == 9 || root->id == 12 || root->id == 13 || root->id == 19 ||root->id == 22 || root->id == 23 || root->id == 26){
			switch(root->id){
				//arithmeticExpression
				case 26:
					root->firstChild = createAST(root->firstChild);
					return root;
					break;
				default:
					memset(c,0,20);
					IDtoterm(root->id, c);
					printf("skipped this node - %s\n", c);
					return root->firstChild = createAST(root->firstChild);
					break;

			}
		}
		else{
			root->parent->firstChild = root->firstChild;
			root->firstChild->parent = root->parent;
			tree* temp = root->firstChild->sibling;
			while(temp){
				temp->parent = root->parent;
				temp = temp->sibling;
			}
			tree* temp2 = root->firstChild;
			memset(c,0,20);
			IDtoterm(root->id, c);
			printf("shifted children of this node upwards - %s\n", c);
			free(root);
			// root = NULL;
			return temp2 = createAST(temp2);
			// printParseTree(root);
			
			// free(root);
		}
	}
	else if(root->sibling == NULL && root->firstChild == NULL){
		if(root->id == 50 || root->id == 51 || root->id == 52 || root->id == 53 || root->id == 54 || root->id == 55 ||root->id == 56 ||root->id == 58 || root->id == 59 || root->id == 64 || root->id == 65 || root->id == 66 || root->id == 67 || root->id == 68 || root->id == 69 ||root->id == 70 || root->id == 71 || root->id == 72 || root->id == 73 || root->id == 74 || root->id == 75 || root->id == 76 || root->id == 77 ||root->id == 78 || root->id == 79||root->id == 80 || root->id == 81 ){
			switch(root->id){
				case 66:
					if(root->parent->id == 31 || root->parent->id ==32){
						root->parent->id = root->id;
						root->parent->lexeme = (char*)malloc(sizeof(char));
						strcpy(root->parent->lexeme,"+");
						free(root);
						return NULL;
					}
					break;
				case 67:
					if(root->parent->id == 31 || root->parent->id ==32){
						root->parent->id = root->id;
						root->parent->lexeme = (char*)malloc(sizeof(char));
						strcpy(root->parent->lexeme,"-");
						free(root);
						return NULL;
					}
					break;
				case 68:
					if(root->parent->id == 31 || root->parent->id ==32){
						root->parent->id = root->id;
						root->parent->lexeme = (char*)malloc(sizeof(char));
						strcpy(root->parent->lexeme,"*");
						free(root);
						return NULL;
					}
					break;
				case 69:
					if(root->parent->id == 31 || root->parent->id ==32){
						root->parent->id = root->id;
						root->parent->lexeme = (char*)malloc(sizeof(char));
						strcpy(root->parent->lexeme,"/");
						free(root);
						return NULL;
					}
					break;
				default:
					memset(c,0,20);
					IDtoterm(root->id, c);
					printf("useful terminal - %s\n", c);	
					return root;

			}
					
		}
		else{
			root->parent->firstChild = NULL;
			memset(c,0,20);
			IDtoterm(root->id, c);
			printf("removed useless terminal - %s\n", c);
			free(root);
			return NULL;
			// root = NULL;
			// printParseTree(root);

			// free(root);
		}

	}
	else if(root->firstChild == NULL){
		if(root->id == 50 || root->id == 51 || root->id == 52 || root->id == 53 || root->id == 54 || root->id == 55 || root->id == 56 ||root->id == 58 || root->id == 59 || root->id == 64 || root->id == 65 || root->id == 66 || root->id == 67 || root->id == 68 || root->id == 69 ||root->id == 70 || root->id == 71 || root->id == 72 || root->id == 73 || root->id == 74 || root->id == 75 || root->id == 76 || root->id == 77 ||root->id == 78 || root->id == 79||root->id == 80 || root->id == 81 ){
			memset(c,0,20);
			IDtoterm(root->id, c);
			printf("useful terminal, moving to sibling - %s\n", c);
			
			root->sibling = createAST(root->sibling);
			return root;
			// printParseTree(root);

		}
		else{
			root->parent->firstChild = root->sibling;
			tree *temp = root->sibling;
			memset(c,0,20);
			IDtoterm(root->id, c);
			printf("removed useless terminal and moving to sibling - %s\n", c);
			free(root);
			// root = NULL;
			return temp = createAST(temp);
			// printParseTree(root);

			// free(root);

		}
	}
	else{
		memset(c,0,20);
		IDtoterm(root->id, c);
		printf("going to sibling now - %s\n", c);

		root->sibling = createAST(root->sibling);
		printf("going to firstChild now - %s\n", c);

		root->firstChild = createAST(root->firstChild);
		switch(root->id){
			//factor to var
			case 30:
				if(root->ruleUsed == 54){
					root->parent->firstChild = root->firstChild;
					root->firstChild->parent = root->parent;
					tree* tempr = root->firstChild;
					free(root);
					return tempr;
				}
				else{
					return root;
				}
				break;
			//type in declaration statement
			case 7:
				if(root->parent->ruleUsed == 21){
					root->parent->firstChild = root->firstChild;
					root->firstChild->parent = root->parent;
					tree* tempr = root->firstChild;
					free(root);
					return tempr;
				}
				else{
					return root;
				}
				break;
			//op_low/op_high
			// case 31:
			// case 32:
			//type
			// case 7:
			// //lhs_singlevar
			// case 14:
			// 	root->parent->firstChild = root->firstChild;
			// 	root->firstChild->parent = root->parent;
			// 	tree* tempr = root->firstChild;
			// 	tempr->sibling = root->sibling;
			// 	free(root);
			// 	return tempr;
			// 	break;
			//stmtOrFunctionDef
			// case 3:
			// 	printNodeInfo(root);
			// 	// printf("No prob till before this***************************\n");
			// 	// printf("%d\n",root->parent->firstChild != root);
			// 	if(root->parent->firstChild == root){
			// 		root->parent->firstChild = root->firstChild;
			// 		root->firstChild->parent = root->parent;
			// 		tree* tempr = root->firstChild;
			// 		tempr->sibling = root->sibling;
			// 		printf("No prob***************************\n");
			// 		free(root);
			// 		return tempr;

			// 	}
			// 	else{
			// 		tree* tempchild = root->parent->firstChild; 
			// 		printf("No prob till this 1***************************\n");

			// 		while(tempchild->sibling && (tempchild->sibling != root)){
			// 			tempchild = tempchild->sibling;
			// 		}
			// 		printf("No prob till this 2***************************\n");

			// 		tempchild->sibling = root->firstChild;
			// 		printf("No prob till this 3***************************\n");
					
			// 		root->firstChild->parent = root->parent;
			// 		printf("No prob till this 4***************************\n");
					
			// 		tree* tempr = root->firstChild;
			// 		tempr->sibling = root->sibling;
			// 		free(root);
			// 		return tempr;
			// 	}				
				
			// 	break;

			default:
				return root;
		}
		
		// printParseTree(root);

	}
	return root;
}
