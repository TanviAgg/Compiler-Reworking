#Tanvi Aggarwal - 2015A7PS0140P
all :
	gcc -c lexer.c parser.c driver.c
	gcc -o stage1exe lexer.o parser.o driver.o