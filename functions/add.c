#include <stdio.h>
#include <stdlib.h>

#define BINARY "0000100100001010"
//#define BINARY "0110000101100010"

char bi[64] = BINARY;

int main()
{
    char fin[32] = { '0' };
    char c = '0';

    for (int i = 16; i > 0; --i) {
        fin[i] = (bi[i - 8] ^ bi[i]) ^ c;
        c = ((bi[i - 8] ^ bi[i]) & c) | (bi[i - 8] & bi[i]);
    }

    for (int i = 0; i < 16; ++i)
        printf("%c", fin[i]);
}
