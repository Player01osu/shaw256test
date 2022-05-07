CC=gcc
DEP=sha256.c
FLAGS=-Wall -g3 -lm -std=c99

clean:
	rm -f sha256.out

install:
	$(CC) $(DEP) $(FLAGS) -o sha256.out
