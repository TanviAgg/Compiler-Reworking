// Tanvi Aggarwal 2015A7PS0140P

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"
#include "lexerDef.h"

/*

FILE *getStream(FILE *fp): This function takes the input from the file pointed to by 'fp'. 
This file is the source code written in the given language. The function uses efficient 
techniques to bring the fixed sized piece of source code into the memory for processing 
so as to avoid intensive I/O operations mixed with CPU intensive tasks. The function also 
maintains the file pointer after every access so that it can get more data into the memory
on demand.

*/

FILE *getStream(FILE *fp, buffer buff, bufferSize k)
{
	int inputSize;
	if(!feof(fp))
		inputSize = fread(buff, 1, k, fp);
	buff[inputSize] = 0;
	return fp;
}

/*

tokenInfo  getNextToken( ): This function reads input character stream and uses efficient
mechanism to recognize lexemes. The function tokenizes the lexeme appropriately and returns 
all relevant information it collects in this phase (lexical analysis phase) encapsulated as 
tokenInfo. The function also displays lexical errors appropriately.

*/


tokenInfo getNextToken(FILE *fp, buffer buff, bufferSize k)
{	
	tokenInfo token;
	int index = 0;
	int error = 0;
	state = 0; //starting state
	token.value = (char*) malloc(sizeof(char)*k);	
	char* lexeme = (char*) malloc(sizeof(char)*k);
	memset(lexeme, 0, sizeof(lexeme));
	//printf("%ld-%s buffer info\n", strlen(buff), buff);
	while(1){
		if(offset == k || buff[offset] == '\0' || strlen(buff) == 0){
			if(feof(fp)){
				token.value = "$";
				token.id = ENDOFINPUT;
				token.lineNo = lineNo;
				return token;
			}
			memset(buff, 0, sizeof(buff));
			fp = getStream(fp, buff, k);
			offset = 0;
			//printf("Printing buffer content: %s\n", buff);
		}
		// printf("***Printing lexeme - %s\n",lexeme);
		switch(state){
			case 0:
				switch(buff[offset]){
					case '\t':
					case ' ':
					case '\r':
						state = 0;
						offset++;
						break;
					
					case '\n':
						state = 0;
						lineNo++;
						offset++;
						break;

					case '#':
						state = 6;
						offset++;
						break;
					
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
						state = 36;
						lexeme[index++] = buff[offset++];
						break;
					
					case '=':
						state = 1;
						lexeme[index++] = buff[offset++];
						break;
					
					case '[':
						state = 7;
						offset++;
						token.id = SQO;
						token.lineNo = lineNo;
						token.value = "[";
						return token;

					case ']':
						state = 8;
						offset++;
						token.id = SQC;
						token.lineNo = lineNo;
						token.value = "]";
						return token;
					
					case '.':
						state = 9;
						lexeme[index++] = buff[offset++];
						break;
					
					case 'a':
					case 'b':
					case 'c':
					case 'd':
					case 'e':
					case 'f':
					case 'g':
					case 'h':
					case 'i':
					case 'j':
					case 'k':
					case 'l':
					case 'm':
					case 'n':
					case 'o':
					case 'p':
					case 'q':
					case 'r':
					case 's':
					case 't':
					case 'u':
					case 'v':
					case 'w':
					case 'x':
					case 'y':
					case 'z':
					case 'A':
					case 'B':
					case 'C':
					case 'D':
					case 'E':
					case 'F':
					case 'G':
					case 'H':
					case 'I':
					case 'J':
					case 'K':
					case 'L':
					case 'M':
					case 'N':
					case 'O':
					case 'P':
					case 'Q':
					case 'R':
					case 'S':
					case 'T':
					case 'U':
					case 'V':
					case 'W':
					case 'X':
					case 'Y':
					case 'Z':
						state = 46;
						lexeme[index++] = buff[offset++];
						break;

					case ')':
						state = 22;
						offset++;
						token.id = CL;
						token.lineNo = lineNo;
						token.value = ")";
						return token;

					case '(':
						state = 21;
						offset++;
						token.id = OP;
						token.lineNo = lineNo;
						token.value = "(";
						return token;

					case '<':
						state = 23;
						lexeme[index++] = buff[offset++];
						break;

					case ';':
						state = 26;
						offset++;
						token.id = SEMICOLON;
						token.lineNo = lineNo;
						token.value = ";";
						return token;

					case ',':
						state = 27;
						offset++;
						token.id = COMMA;
						token.lineNo = lineNo;
						token.value = ",";
						return token;

					case '>':
						state = 28;
						lexeme[index++] = buff[offset++];
						break;

					case '+':
						state = 30;
						offset++;
						token.id = PLUS;
						token.lineNo = lineNo;
						token.value = "+";
						return token;

					case '-':
						state = 32;
						offset++;
						token.id = MINUS;
						token.lineNo = lineNo;
						token.value = "-";
						return token;

					case '"':
						state = 33;
						lexeme[index++] = buff[offset++];
						break;

					case '*':
						state = 41;
						offset++;
						token.id = MUL;
						token.lineNo = lineNo;
						token.value = "*";
						return token;

					case '/':
						state = 42;
						offset++;
						token.id = DIV;
						token.lineNo = lineNo;
						token.value = "/";
						return token;

					case '_':
						state = 43;
						lexeme[index++] = buff[offset++];
						break;

					case '@':
						state = 49;
						offset++;
						token.id = SIZE;
						token.lineNo = lineNo;
						token.value = "@";
						return token;

					case '\0':
						token.id = ENDOFINPUT;
						token.value = "$";
						token.lineNo = lineNo;
						return token;

					default:
						errorInLexer = 1;
						printf("LEXICAL ERROR 1: UNKNOWN SYMBOL <%c> AT LINE <%d>.\n", buff[offset], lineNo);
						error = 1;
						offset++;
						break;
				}
				break;
			
			case 1:
				if(buff[offset] == '='){
					state = 3;
					lexeme[index++] = buff[offset++];
					index = 0;
					token.id = EQ;
					token.lineNo = lineNo;
					strcpy(token.value, lexeme);
					memset(lexeme, 0, sizeof(lexeme));
					return token;
				}
				else if(buff[offset] == '/'){
					state = 4;
					lexeme[index++] = buff[offset++];
				}
				else{
					state = 2;
					index = 0;
					token.id = ASSIGNOP;
					token.lineNo = lineNo;
					token.value = "=";
					memset(lexeme, 0, sizeof(lexeme));
					return token;
				}
				break;
			
			case 4:
				if(buff[offset] == '='){
					state = 5;
					lexeme[index++] = buff[offset++];
					index = 0;
					token.id = NE;
					token.lineNo = lineNo;
					strcpy(token.value, lexeme);
					memset(lexeme, 0, sizeof(lexeme));
					return token;
				}
				else{
					lexeme[index++] = buff[offset++];
					printf("LEXICAL ERROR 2: UNKNOWN PATTERN <%s> AT LINE <%d>.\n",lexeme, lineNo);
					errorInLexer = 1;
					error = 1;
					break;
				}
				break;
			
			case 6:
				while(buff[offset++] != '\n'){
					if(offset == k || buff[offset] == '\0'){
						if(feof(fp)){
							break;
						}
						memset(buff, 0, sizeof(buff));
						fp = getStream(fp, buff, k);
						offset = 0;
					}
				}
				token.value = "COMMENT";
				token.id = COMMENT;
				token.lineNo = lineNo;
				lineNo++;
				return token;
				break;

			case 9:
				switch(buff[offset]){
					case 'a':
						lexeme[index++] = buff[offset++];
						if(buff[offset] == 'n'){
							lexeme[index++] = buff[offset++];
							if(buff[offset] == 'd'){
								lexeme[index++] = buff[offset++];
								if(buff[offset] == '.'){
									lexeme[index++] = buff[offset++];
									state = 13;
									index = 0;
									token.id = AND;
									token.lineNo = lineNo;
									strcpy(token.value, lexeme);
									memset(lexeme, 0, sizeof(lexeme));
									return token;
								}
								else{
									lexeme[index++] = buff[offset++];
									printf("LEXICAL ERROR 2: UNKNOWN PATTERN <%s> AT LINE <%d>.\n",lexeme, lineNo);
									errorInLexer = 1;
									error = 1;
									break;
								}
							}
							else{
								lexeme[index++] = buff[offset++];
								printf("LEXICAL ERROR 2: UNKNOWN PATTERN <%s> AT LINE <%d>.\n",lexeme, lineNo);
								errorInLexer = 1;
								error = 1;
								break;
							}
						}
						else{
							lexeme[index++] = buff[offset++];
							printf("LEXICAL ERROR 2: UNKNOWN PATTERN <%s> AT LINE <%d>.\n",lexeme, lineNo);
							errorInLexer = 1;
							error = 1;
							break;
						}
						break;
					case 'o':
						lexeme[index++] = buff[offset++];
						if(buff[offset] == 'r'){
							lexeme[index++] = buff[offset++];
							if(buff[offset] == '.'){
								lexeme[index++] = buff[offset++];
								state = 16;
								index = 0;
								token.id = OR;
								token.lineNo = lineNo;
								strcpy(token.value, lexeme);
								memset(lexeme, 0, sizeof(lexeme));
								return token;
							}
							else{
								lexeme[index++] = buff[offset++];
								printf("LEXICAL ERROR 2: UNKNOWN PATTERN <%s> AT LINE <%d>.\n",lexeme, lineNo);
								errorInLexer = 1;
								error = 1;
								break;
							}
						}
						else{
							lexeme[index++] = buff[offset++];
							printf("LEXICAL ERROR 2: UNKNOWN PATTERN <%s> AT LINE <%d>.\n",lexeme, lineNo);
							errorInLexer = 1;
							error = 1;
							break;
						}
						break;
					case 'n':
						lexeme[index++] = buff[offset++];
						if(buff[offset] == 'o'){
							lexeme[index++] = buff[offset++];
							if(buff[offset] == 't'){
								lexeme[index++] = buff[offset++];
								if(buff[offset] == '.'){
									lexeme[index++] = buff[offset++];
									state = 20;
									index = 0;
									token.id = NOT;
									token.lineNo = lineNo;
									strcpy(token.value, lexeme);
									memset(lexeme, 0, sizeof(lexeme));
									return token;
								}
								else{
									lexeme[index++] = buff[offset++];
									printf("LEXICAL ERROR 2: UNKNOWN PATTERN <%s> AT LINE <%d>.\n",lexeme, lineNo);
									errorInLexer = 1;
									error = 1;
									break;
								}
							}
							else{
								lexeme[index++] = buff[offset++];
								printf("LEXICAL ERROR 2: UNKNOWN PATTERN <%s> AT LINE <%d>.\n",lexeme, lineNo);
								errorInLexer = 1;
								error = 1;
								break;
							}
						}
						else{
							lexeme[index++] = buff[offset++];
							printf("LEXICAL ERROR 2: UNKNOWN PATTERN <%s> AT LINE <%d>.\n",lexeme, lineNo);
							errorInLexer = 1;
							error = 1;
							break;
						}
						break;
				}
				break;
			
			case 23:
				if(buff[offset] == '='){
					state = 25;
					offset++;
					index = 0;
					token.id = LE;
					token.lineNo = lineNo;
					token.value = "<=";
					memset(lexeme, 0, sizeof(lexeme));
					return token;
				}
				else{
					state = 24;
					index = 0;
					token.id = LT;
					token.lineNo = lineNo;
					token.value = "<";
					memset(lexeme, 0, sizeof(lexeme));
					return token;
				}
				break;
			
			case 28:
				if(buff[offset] == '='){
					state = 31;
					offset++;
					index = 0;
					token.id = GE;
					token.lineNo = lineNo;
					token.value = ">=";
					memset(lexeme, 0, sizeof(lexeme));
					return token;
				}
				else{
					state = 29;
					index = 0;
					token.id = GT;
					token.lineNo = lineNo;
					token.value = ">";
					memset(lexeme, 0, sizeof(lexeme));
					return token;
				}
				break;
			
			case 33:
				switch(buff[offset]){
					case 'a':
					case 'b':
					case 'c':
					case 'd':
					case 'e':
					case 'f':
					case 'g':
					case 'h':
					case 'i':
					case 'j':
					case 'k':
					case 'l':
					case 'm':
					case 'n':
					case 'o':
					case 'p':
					case 'q':
					case 'r':
					case 's':
					case 't':
					case 'u':
					case 'v':
					case 'w':
					case 'x':
					case 'y':
					case 'z':
					case ' ':
						lexeme[index++] = buff[offset++];
						state = 34;
						break;
					default:
						lexeme[index++] = buff[offset++];
						printf("LEXICAL ERROR 2: UNKNOWN PATTERN <%s> AT LINE <%d>.\n",lexeme, lineNo);
						errorInLexer = 1;
						error = 1;
						break;
				}
				break;

			case 34:
				switch(buff[offset]){
					case 'a':
					case 'b':
					case 'c':
					case 'd':
					case 'e':
					case 'f':
					case 'g':
					case 'h':
					case 'i':
					case 'j':
					case 'k':
					case 'l':
					case 'm':
					case 'n':
					case 'o':
					case 'p':
					case 'q':
					case 'r':
					case 's':
					case 't':
					case 'u':
					case 'v':
					case 'w':
					case 'x':
					case 'y':
					case 'z':
					case ' ':
						lexeme[index++] = buff[offset++];
						state = 34;
						break;
					case '"':
						state = 35;
						lexeme[index++] = buff[offset++];
						lexeme[index] = '\0';
						index = 0;
						token.id = STR;
						token.lineNo = lineNo;
						strcpy(token.value, lexeme);
						memset(lexeme, 0, sizeof(lexeme));
						return token;

					default:
						lexeme[index++] = buff[offset++];
						if (offset == k || buff[offset] == '\0'){
							if (feof(fp)){
								break;
							}
							memset(buff, 0, sizeof(buff));
							fp = getStream(fp, buff, k);
							offset = 0;
							break;
						}
						else{
							printf("LEXICAL ERROR 2: UNKNOWN PATTERN <%s> AT LINE <%d>.\n",lexeme, lineNo);
							errorInLexer = 1;
							error = 1;
							break;
						}
				}
				break;

			case 36:
				switch(buff[offset]){
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
						state = 36;
						lexeme[index++] = buff[offset++];
						break;
					case '.':
						state = 38;
						lexeme[index++] = buff[offset++];
						break;
					default:
						state = 37;
						index = 0;
						token.id = NUM;
						token.lineNo = lineNo;
						strcpy(token.value, lexeme);
						memset(lexeme, 0, sizeof(lexeme));
						return token;
						break;
				}
				break;
			
			case 38:
				switch(buff[offset]){
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
						state = 39;
						lexeme[index++] = buff[offset++];
						break;
					default:
						lexeme[index++] = buff[offset++];
						printf("LEXICAL ERROR 2: UNKNOWN PATTERN <%s> AT LINE <%d>.\n",lexeme, lineNo);
						errorInLexer = 1;
						error = 1;
						break;
				}
				break;
			
			case 39:
				switch(buff[offset]){
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
						state = 40;
						lexeme[index++] = buff[offset++];
						index = 0;
						token.id = RNUM;
						token.lineNo = lineNo;
						strcpy(token.value, lexeme);
						memset(lexeme, 0, sizeof(lexeme));
						return token;
						break;
					default:
						lexeme[index++] = buff[offset++];
						printf("LEXICAL ERROR 2: UNKNOWN PATTERN <%s> AT LINE <%d>.\n",lexeme, lineNo);
						errorInLexer = 1;
						error = 1;
						break;
				}
				break;
			
			case 43:
				switch(buff[offset]){
					case 'm':
						lexeme[index++] = buff[offset++];
						state = 50;
						break;
					case 'a':
					case 'b':
					case 'c':
					case 'd':
					case 'e':
					case 'f':
					case 'g':
					case 'h':
					case 'i':
					case 'j':
					case 'k':
					case 'l':
					//case m:
					case 'n':
					case 'o':
					case 'p':
					case 'q':
					case 'r':
					case 's':
					case 't':
					case 'u':
					case 'v':
					case 'w':
					case 'x':
					case 'y':
					case 'z':
					case 'A':
					case 'B':
					case 'C':
					case 'D':
					case 'E':
					case 'F':
					case 'G':
					case 'H':
					case 'I':
					case 'J':
					case 'K':
					case 'L':
					case 'M':
					case 'N':
					case 'O':
					case 'P':
					case 'Q':
					case 'R':
					case 'S':
					case 'T':
					case 'U':
					case 'V':
					case 'W':
					case 'X':
					case 'Y':
					case 'Z':
						state = 51;
						lexeme[index++] = buff[offset++];
						break;
					default:
						lexeme[index++] = buff[offset++];
						printf("LEXICAL ERROR 2: UNKNOWN PATTERN <%s> AT LINE <%d>.\n",lexeme, lineNo);
						errorInLexer = 1;
						error = 1;
						break;
				}
				break;
			case 50:
				switch(buff[offset]){
					case 'a':
						lexeme[index++] = buff[offset++];
						state = 52;
						break;
					//case 'a':
					case 'b':
					case 'c':
					case 'd':
					case 'e':
					case 'f':
					case 'g':
					case 'h':
					case 'i':
					case 'j':
					case 'k':
					case 'l':
					case 'm':
					case 'n':
					case 'o':
					case 'p':
					case 'q':
					case 'r':
					case 's':
					case 't':
					case 'u':
					case 'v':
					case 'w':
					case 'x':
					case 'y':
					case 'z':
					case 'A':
					case 'B':
					case 'C':
					case 'D':
					case 'E':
					case 'F':
					case 'G':
					case 'H':
					case 'I':
					case 'J':
					case 'K':
					case 'L':
					case 'M':
					case 'N':
					case 'O':
					case 'P':
					case 'Q':
					case 'R':
					case 'S':
					case 'T':
					case 'U':
					case 'V':
					case 'W':
					case 'X':
					case 'Y':
					case 'Z':
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
						state = 51;
						lexeme[index++] = buff[offset++];
						break;
					default:
						state = 56;
						lexeme[index] = '\0';
						index = 0;
						token.id = FUNID;
						token.lineNo = lineNo;
						strcpy(token.value, lexeme);
						memset(lexeme, 0, sizeof(lexeme));
						return token;
						break;
				}
				break;
			case 52:
				switch(buff[offset]){
					case 'i':
						lexeme[index++] = buff[offset++];
						state = 53;
						break;
					case 'a':
					case 'b':
					case 'c':
					case 'd':
					case 'e':
					case 'f':
					case 'g':
					case 'h':
					//case 'i':
					case 'j':
					case 'k':
					case 'l':
					case 'm':
					case 'n':
					case 'o':
					case 'p':
					case 'q':
					case 'r':
					case 's':
					case 't':
					case 'u':
					case 'v':
					case 'w':
					case 'x':
					case 'y':
					case 'z':
					case 'A':
					case 'B':
					case 'C':
					case 'D':
					case 'E':
					case 'F':
					case 'G':
					case 'H':
					case 'I':
					case 'J':
					case 'K':
					case 'L':
					case 'M':
					case 'N':
					case 'O':
					case 'P':
					case 'Q':
					case 'R':
					case 'S':
					case 'T':
					case 'U':
					case 'V':
					case 'W':
					case 'X':
					case 'Y':
					case 'Z':
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
						state = 51;
						lexeme[index++] = buff[offset++];
						break;
					default:
						state = 56;
						lexeme[index] = '\0';
						index = 0;
						token.id = FUNID;
						token.lineNo = lineNo;
						strcpy(token.value, lexeme);
						memset(lexeme, 0, sizeof(lexeme));
						return token;
						break;
				}
				break;
			case 53:
				switch(buff[offset]){
					case 'n':
						lexeme[index++] = buff[offset++];
						state = 54;
						break;
					case 'a':
					case 'b':
					case 'c':
					case 'd':
					case 'e':
					case 'f':
					case 'g':
					case 'h':
					case 'i':
					case 'j':
					case 'k':
					case 'l':
					case 'm':
					//case 'n':
					case 'o':
					case 'p':
					case 'q':
					case 'r':
					case 's':
					case 't':
					case 'u':
					case 'v':
					case 'w':
					case 'x':
					case 'y':
					case 'z':
					case 'A':
					case 'B':
					case 'C':
					case 'D':
					case 'E':
					case 'F':
					case 'G':
					case 'H':
					case 'I':
					case 'J':
					case 'K':
					case 'L':
					case 'M':
					case 'N':
					case 'O':
					case 'P':
					case 'Q':
					case 'R':
					case 'S':
					case 'T':
					case 'U':
					case 'V':
					case 'W':
					case 'X':
					case 'Y':
					case 'Z':
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
						state = 51;
						lexeme[index++] = buff[offset++];
						break;
					default:
						state = 56;
						lexeme[index] = '\0';
						index = 0;
						token.id = FUNID;
						token.lineNo = lineNo;
						strcpy(token.value, lexeme);
						memset(lexeme, 0, sizeof(lexeme));
						return token;
						break;
				}
				break;
			case 54:
				switch(buff[offset]){
					case 'a':
					case 'b':
					case 'c':
					case 'd':
					case 'e':
					case 'f':
					case 'g':
					case 'h':
					case 'i':
					case 'j':
					case 'k':
					case 'l':
					case 'm':
					case 'n':
					case 'o':
					case 'p':
					case 'q':
					case 'r':
					case 's':
					case 't':
					case 'u':
					case 'v':
					case 'w':
					case 'x':
					case 'y':
					case 'z':
					case 'A':
					case 'B':
					case 'C':
					case 'D':
					case 'E':
					case 'F':
					case 'G':
					case 'H':
					case 'I':
					case 'J':
					case 'K':
					case 'L':
					case 'M':
					case 'N':
					case 'O':
					case 'P':
					case 'Q':
					case 'R':
					case 'S':
					case 'T':
					case 'U':
					case 'V':
					case 'W':
					case 'X':
					case 'Y':
					case 'Z':
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
						state = 51;
						lexeme[index++] = buff[offset++];
						break;
					default:
						state = 55;
						index = 0;
						token.id = MAIN;
						token.lineNo = lineNo;
						strcpy(token.value, lexeme);
						memset(lexeme, 0, sizeof(lexeme));
						return token;
						break;
				}
				break;
			case 51:
				switch(buff[offset]){
					case 'a':
					case 'b':
					case 'c':
					case 'd':
					case 'e':
					case 'f':
					case 'g':
					case 'h':
					case 'i':
					case 'j':
					case 'k':
					case 'l':
					case 'm':
					case 'n':
					case 'o':
					case 'p':
					case 'q':
					case 'r':
					case 's':
					case 't':
					case 'u':
					case 'v':
					case 'w':
					case 'x':
					case 'y':
					case 'z':
					case 'A':
					case 'B':
					case 'C':
					case 'D':
					case 'E':
					case 'F':
					case 'G':
					case 'H':
					case 'I':
					case 'J':
					case 'K':
					case 'L':
					case 'M':
					case 'N':
					case 'O':
					case 'P':
					case 'Q':
					case 'R':
					case 'S':
					case 'T':
					case 'U':
					case 'V':
					case 'W':
					case 'X':
					case 'Y':
					case 'Z':
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
						state = 51;
						lexeme[index++] = buff[offset++];
						break;
					default:
						state = 56;
						lexeme[index] = '\0';
						index = 0;
						token.id = FUNID;
						token.lineNo = lineNo;
						strcpy(token.value, lexeme);
						memset(lexeme, 0, sizeof(lexeme));
						return token;
						break;
				}
				break;
			
			case 46:
				while( (97 <= buff[offset] && buff[offset] <= 122) || (65 <= buff[offset] && buff[offset] <= 90)){
					lexeme[index++] = buff[offset++];
					if (offset == k || buff[offset] == '\0'){
						if (feof(fp)){
							break;
						}
						memset(buff, 0, sizeof(buff));
						fp = getStream(fp, buff, k);
						offset = 0;
					}
				}
				lexeme[index] = '\0';
				// printf("****Printing lexeme- %s\n", lexeme);
				if(48 <= buff[offset] && buff[offset] <= 57){
					lexeme[index++] = buff[offset++];
					state = 47;
					index = 0;
					token.id = ID;
					token.lineNo = lineNo;
					strcpy(token.value, lexeme);
					memset(lexeme, 0, sizeof(lexeme));
					return token;
				}
				else if(strcmp(lexeme, "end")==0){
					token.id = END;
					token.lineNo = lineNo;
					index = 0;
					strcpy(token.value, lexeme);
					memset(lexeme, 0, sizeof(lexeme));
					return token;
				}
				else if(strcmp(lexeme, "int")==0){
					token.id = INT;
					token.lineNo = lineNo;
					index = 0;
					strcpy(token.value, lexeme);
					memset(lexeme, 0, sizeof(lexeme));
					return token;
				}
				else if(strcmp(lexeme, "real")==0){
					token.id = REAL;
					token.lineNo = lineNo;
					index = 0;
					strcpy(token.value, lexeme);
					memset(lexeme, 0, sizeof(lexeme));
					return token;
				}
				else if(strcmp(lexeme, "string")==0){
					token.id = STRING;
					token.lineNo = lineNo;
					index = 0;
					strcpy(token.value, lexeme);
					memset(lexeme, 0, sizeof(lexeme));
					return token;
				}
				else if(strcmp(lexeme, "matrix")==0){
					token.id = MATRIX;
					token.lineNo = lineNo;
					index = 0;
					strcpy(token.value, lexeme);
					memset(lexeme, 0, sizeof(lexeme));
					return token;
				}
				else if(strcmp(lexeme, "if")==0){
					token.id = IF ;
					token.lineNo = lineNo;
					index = 0;
					strcpy(token.value, lexeme);
					memset(lexeme, 0, sizeof(lexeme));
					return token;
				}
				else if(strcmp(lexeme, "else")==0){
					token.id = ELSE;
					token.lineNo = lineNo;
					index = 0;
					strcpy(token.value, lexeme);
					memset(lexeme, 0, sizeof(lexeme));
					return token;
				}
				else if(strcmp(lexeme, "endif")==0){
					token.id = ENDIF;
					token.lineNo = lineNo;
					index = 0;
					strcpy(token.value, lexeme);
					memset(lexeme, 0, sizeof(lexeme));
					return token;
				}
				else if(strcmp(lexeme, "read")==0){
					token.id = READ;
					token.lineNo = lineNo;
					index = 0;
					strcpy(token.value, lexeme);
					memset(lexeme, 0, sizeof(lexeme));
					return token;
				}
				else if(strcmp(lexeme, "print")==0){
					token.id = PRINT;
					token.lineNo = lineNo;
					index = 0;
					strcpy(token.value, lexeme);
					memset(lexeme, 0, sizeof(lexeme));
					return token;
				}
				else if(strcmp(lexeme, "function")==0){
					token.id = FUNCTION;
					token.lineNo = lineNo;
					lexeme[index] = '\0';
					index = 0;
					strcpy(token.value, lexeme);
					memset(lexeme, 0, sizeof(lexeme));
					return token;
				}
				else{
					state = 47;
					index = 0;
					token.id = ID;
					token.lineNo = lineNo;
					strcpy(token.value, lexeme);
					memset(lexeme, 0, sizeof(lexeme));
					return token;
				}

				break;

			default:
				printf("ERROR: WRONG STATE");
				break;

		}
	}

}


/*

void removeComments(char *testcaseFile, char *cleanFile): This function is an additional plug 
in to clean the source code by removal of comments. The function takes as input the source 
code and writes the clean code in the file appropriately. The function is not used by the 
parser but is invoked in the driver file for the purpose of demonstrating the capability of 
your lexer for comment removal. 

*/

void removeComments(char *testcaseFile)
{
	FILE *fp = fopen(testcaseFile, "r");
	if(fp == NULL)
		printf("Invalid file\n");
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while((read = getline(&line, &len, fp)) != -1){
		if(line[0] == '\n' || line[0] == '#')
			continue;
		int i = 0;
		while((i != read) && (line[i] != '#')){
			i++;
		}
		if(i == read){
			printf("%s", line);
		}
		else{			
			line[i] = '\0';
			printf("%s\n", line);
		}
	}

	fclose(fp);
}

// void main(){
// 	char* b = (char*) malloc(sizeof(char)*20);
// 	int k = 20;
// 	FILE *fp = fopen("testing.txt", "r");
	
// 	tokenInfo t = getNextToken(fp, b, k);
// 	printf(" Type:%d, value: %s, line no: %d\n", t.id, t.value, t.lineNo);
// 	while(t.id != 38 ){
// 		t = getNextToken(fp, b, k);
// 	printf(" Type:%d, value: %s, line no: %d\n", t.id, t.value, t.lineNo);
	
// 	}
// 	//removeComments("testing.txt");
// }