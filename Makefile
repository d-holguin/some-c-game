CC=gcc
CFLAGS=-Wall -g

clean :
	-rm main

main : main.c
	gcc main.c -o main