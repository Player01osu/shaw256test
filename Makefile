
clean:
	rm shaw256test.out

install:
	gcc shaw256test.c -lm -o shaw256test.out
