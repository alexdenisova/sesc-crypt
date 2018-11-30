run: crypt
	./crypt

crypt: crypt.c
	gcc -Wall -std=c11 crypt.c -o crypt

build: crypt
