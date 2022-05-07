#include <stdio.h>
#include <stdlib.h>

#define BINARY "0000000000000000"
#define BINARYTWO "0101001010101010"
//#define BINARY "0000100100001010"
//#define BINARY "0110000101100010"

char bi[64] = BINARY;

char *addbin(char a[32], char b[32])
{
	char t[32];
	char *fin = malloc(sizeof(char) * 32);
	char c = '0';

	for (int i = 32; i >= 0; --i) {
		t[i] = (a[i] ^ b[i]) ^ c;
		c = ((a[i] ^ b[i]) & c) | (a[i] & b[i]);
	}

	for (int i = 0; i < 32; ++i)
		fin[i] = t[i];

	return fin;
}

int main()
{
	char one[32] = BINARY;
	char two[32] = BINARYTWO;
	printf("%s", addbin(one, two));
}

//int main()
//{
//    char fin[32] = { '0' };
//    char c = '0';
//
//    for (int i = 16; i > 0; --i) {
//        fin[i] = (bi[i - 8] ^ bi[i]) ^ c;
//        c = ((bi[i - 8] ^ bi[i]) & c) | (bi[i - 8] & bi[i]);
//    }
//
//    for (int i = 0; i < 16; ++i)
//        printf("%c", fin[i]);
//}
