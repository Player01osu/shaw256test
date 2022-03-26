CC=gcc
DEP=sha256rewrite.c
FLAGS=-Wall -g3 -J4

clean:
	rm -f sha256.out

install:
	$(CC) $(DEP) $(FLAGS) -o sha256.out
