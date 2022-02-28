CC=gcc
CFLAGS=-Wall 

clean :
	-rm main

main : main.c
	gcc main.c -o main