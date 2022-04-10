#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BINARY "1000111000001011"
#define BUFFERSIZE 32

void printbin(char bi[32])
{
    for (int i = 0; i < 16; ++i)
        printf("%c", bi[i]);
}

int main()
{
    char bi[32] = BINARY;
    char buffer[BUFFERSIZE];
    for (int j = 0; j < 5; ++j) {
        strncpy(buffer, bi, 16);
        for (int i = 1; i < 16; ++i)
            bi[i] = buffer[i - 1];
        bi[j] = '0';
    }

    printbin(bi);
}
