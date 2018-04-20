#Tanvi Aggarwal - 2015A7PS0140P
all :
	gcc -c lexer.c parser.c driver.c ast.c symbolTable.c
	gcc -o compiler lexer.o parser.o driver.o ast.o symbolTable.o