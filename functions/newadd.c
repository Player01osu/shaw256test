#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *addbin(char a[32], char b[32])
{
	char t[32];
	char *fin = malloc(sizeof(char) * 32);
	char c = '0';

	for (int i = 31; i >= 0; --i) {
		t[i] = (a[i] ^ b[i]) ^ c;
		c = ((a[i] ^ b[i]) & c) | (a[i] & b[i]);
	}
	strncpy(fin, t, 32);

//	for (int i = 0; i < 32; ++i)
//		fin[i] = t[i];

	return fin;
}

#define BIN1 "00000000000000000000000000001111"
#define BIN2 "00000000000000000000000000000111"

int main()
{
	printf("%s", addbin(BIN1, BIN2));
}
