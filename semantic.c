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

void semanticCheck(tree* root, hashnode* symbolTable){
	if(root == NULL){
		// printf("Root is null, returning\n");
		return;
	}
	if(root->firstChild){
		// printf("I have a child :(\n");
		semanticCheck(root->firstChild, symbolTable);
	}
	if(root->id == 9){
		// printf("Declaration Node\n");
		//create an entry and add to symbolTable
		if(root->firstChild->id == 53){
			// printf("adding entries\n");
			tree *temp = root->firstChild->sibling;
			while(temp){
				hashEntry *newID = (hashEntry *)malloc(sizeof(hashEntry));
				// hashEntry *newID;
				strcpy(newID->name, temp->lexeme);
				strcpy(newID->type, "INT");
				newID->width = 2;
				newID->offset = offset;
				offset += 2;
				// printf("adding entries\n");

				addEntryToTable(newID, symbolTable, temp->lineNo);
				temp = temp->sibling;
			}
		} //int
		else if(root->firstChild->id == 54){
			//printf("Function def\n");
			tree *temp = root->firstChild->sibling;
			while(temp){
				hashEntry *newID = (hashEntry *)malloc(sizeof(hashEntry));
				// hashEntry *newID;
				strcpy(newID->name, temp->lexeme);
				strcpy(newID->type, "REAL");
				newID->width = 4;
				newID->offset = offset;
				offset += 4;
				// printf("adding entries\n");
				addEntryToTable(newID, symbolTable, temp->lineNo);
				temp = temp->sibling;
			}

		} //real
		else if(root->firstChild->id == 55){
			tree *temp = root->firstChild->sibling;
			while(temp){
				hashEntry *newID = (hashEntry *)malloc(sizeof(hashEntry));
				// hashEntry *newID;
				strcpy(newID->name, temp->lexeme);
				strcpy(newID->type, "STRING");
				newID->width = 20; ///how?
				newID->offset = offset;
				offset += 20;
				// printf("adding entries\n");
				addEntryToTable(newID, symbolTable, temp->lineNo);
				temp = temp->sibling;
			}

		} //string
		else if(root->firstChild->id == 56){
			tree *temp = root->firstChild->sibling;
			while(temp){
				hashEntry *newID = (hashEntry *)malloc(sizeof(hashEntry));
				// hashEntry *newID;
				strcpy(newID->name, temp->lexeme);
				strcpy(newID->type, "MATRIX");
				newID->width = 2;////*****how much space?
				newID->offset = offset;
				offset += 2;
				// printf("adding entries\n");
				addEntryToTable(newID, symbolTable, temp->lineNo);
				temp = temp->sibling;
			}

		} //matrix

	}
	else if(root->id == 6 && root->parent->id== 5 && root->sibling->id != 50){
		// printf("Parameter List\n");
		//create an entry and add to symbolTable
		tree *temp = root->firstChild;
		while(temp){
			if(temp->firstChild->id == 53){
				// printf("adding entries\n");
				hashEntry *newID = (hashEntry *)malloc(sizeof(hashEntry));
				// hashEntry *newID;
				strcpy(newID->name, temp->sibling->lexeme);
				strcpy(newID->type, "INT");
				newID->width = 2;
				newID->offset = offset;
				offset += 2;
				// printf("adding entries\n");
				addEntryToTable(newID, symbolTable, temp->lineNo);
				if(temp && temp->sibling)
					temp = temp->sibling->sibling;
			} //int
			else if(temp->firstChild->id == 54){
				// printf("adding entries\n");
				hashEntry *newID = (hashEntry *)malloc(sizeof(hashEntry));
				// hashEntry *newID;
				strcpy(newID->name, temp->sibling->lexeme);
				strcpy(newID->type, "REAL");
				newID->width = 4;
				newID->offset = offset;
				offset += 4;
				// printf("adding entries\n");
				addEntryToTable(newID, symbolTable, temp->lineNo);
				if(temp && temp->sibling)
					temp = temp->sibling->sibling;
			} //REAL
			else if(temp->firstChild->id == 55){
				// printf("adding entries\n");
				hashEntry *newID = (hashEntry *)malloc(sizeof(hashEntry));
				// hashEntry *newID;
				strcpy(newID->name, temp->sibling->lexeme);
				strcpy(newID->type, "STRING");
				newID->width = 20;
				newID->offset = offset;
				offset += 20;
				// printf("adding entries\n");
				addEntryToTable(newID, symbolTable,temp->lineNo);
				if(temp && temp->sibling)
					temp = temp->sibling->sibling;
			} //STRING
			else if(temp->firstChild->id == 56){
				// printf("adding entries\n");
				hashEntry *newID = (hashEntry *)malloc(sizeof(hashEntry));
				// hashEntry *newID;
				strcpy(newID->name, temp->sibling->lexeme);
				strcpy(newID->type, "MATRIX");
				newID->width = 2;
				newID->offset = offset;
				offset += 2;
				// printf("adding entries\n");
				addEntryToTable(newID, symbolTable, temp->lineNo);
				if(temp && temp->sibling)
					temp = temp->sibling->sibling;
			} //MATRIX
			
			// symbolTableHelper(root->sibling, symbolTable);
		}
	}
	else if(root->id == 5){
		// printf("functionDef node.\n");
		//create a new symbolTable and change to that
		tree* tempt = root->firstChild;
		tree* temp = tempt->firstChild;
		while(tempt&& tempt->id != 51){
			tempt = tempt->sibling;
		}


		// printf("adding new hashnode\n");
		hashnode* newHashnode = (hashnode *)malloc(sizeof(hashnode));
		newHashnode->scopeID = tempt->lexeme;
		newHashnode->sibling = NULL;
		newHashnode->parent = symbolTable;
		newHashnode->nesting_level = symbolTable->nesting_level + 1;
		if(symbolTable->firstChild == NULL)
			symbolTable->firstChild = newHashnode;
		else{
			hashnode *temp2 = symbolTable->firstChild;
			while(temp2->sibling != NULL){
				temp2 = temp2->sibling;
			}
			temp2->sibling = newHashnode;
		}
		newHashnode->firstChild = NULL;
		// printf("fine\n");

		symbolTable = newHashnode;
		while(temp){
			if(temp->firstChild->id == 53){
				// printf("adding entries\n");
				hashEntry *newID = (hashEntry *)malloc(sizeof(hashEntry));
				// hashEntry *newID;
				strcpy(newID->name, temp->sibling->lexeme);
				strcpy(newID->type, "INT");
				newID->width = 2;
				newID->offset = offset;
				offset += 2;
				// printf("adding entries\n");
				addEntryToTable(newID, symbolTable,temp->sibling->lineNo);
				if(temp && temp->sibling)
					temp = temp->sibling->sibling;
				
			} //int
			else if(temp->firstChild->id == 54){
				// printf("adding entries\n");
				hashEntry *newID = (hashEntry *)malloc(sizeof(hashEntry));
				// hashEntry *newID;
				strcpy(newID->name, temp->sibling->lexeme);
				strcpy(newID->type, "REAL");
				newID->width = 4;
				newID->offset = offset;
				offset += 4;
				// printf("adding entries\n");
				addEntryToTable(newID, symbolTable,temp->sibling->lineNo);
				if(temp && temp->sibling)
					temp = temp->sibling->sibling;
			} //REAL
			else if(temp->firstChild->id == 55){
				// printf("adding entries\n");
				hashEntry *newID = (hashEntry *)malloc(sizeof(hashEntry));
				// hashEntry *newID;
				strcpy(newID->name, temp->sibling->lexeme);
				strcpy(newID->type, "STRING");
				newID->width = 20;
				newID->offset = offset;
				offset += 20;
				// printf("adding entries\n");
				addEntryToTable(newID, symbolTable,temp->sibling->lineNo);
				if(temp && temp->sibling)
					temp = temp->sibling->sibling;
			} //STRING
			else if(temp->firstChild->id == 56){
				// printf("adding entries\n");
				hashEntry *newID = (hashEntry *)malloc(sizeof(hashEntry));
				// hashEntry *newID;
				strcpy(newID->name, temp->sibling->lexeme);
				strcpy(newID->type, "MATRIX");
				newID->width = 2;
				newID->offset = offset;
				offset += 2;
				// printf("adding entries\n");
				addEntryToTable(newID, symbolTable,temp->sibling->lineNo);
				if(temp && temp->sibling)
					temp = temp->sibling->sibling;
			} 
		}

	}
	if(root->firstChild && root->firstChild->sibling){
		// printf("Siblings are annoying \n");
		tree* temp2 = root->firstChild->sibling;
		while(temp2){
			semanticCheck(temp2, symbolTable);			
			temp2 = temp2->sibling;
		}
	}
}
