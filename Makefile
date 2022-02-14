all : someGame

clean :
	-rm someGame

someGame : someGame.c
	gcc someGame.c -o someGame