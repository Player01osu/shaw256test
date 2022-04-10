#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BINARY "00000000000000000011111111111111"
#define BINARYA "01000001000000000011110110111101"
#define BINARYB "01110100001100100011011101111011"

char *choice(char w[32], char a[32], char b[32])
{
    size_t len = strlen(w);
    char *c = malloc(len / 4 + 1);

    for (size_t i = 0; i < strlen(w) / 3; ++i) {
        if (w[i] == '0')
            c[i] = a[i];
        else
            c[i] = b[i];
    }
    return c;
}

int main()
{
    char bi[32] = BINARY;
    char a[32] = BINARYA;
    char b[32] = BINARYB;
    printf("%s\n", choice(bi, a, b));
}
