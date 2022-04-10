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

    for (int k = 0; k < 3; ++k) { // k determines how many right shift
        for (int j = 0; j < 15; ++j) {
            buffer[0] = bi[1];
            for (int i = 1; i < 16; ++i)
                bi[i % 16] = bi[(i + 1) % 16]; // left shift
            bi[0] = buffer[0];
        }
    }

    printbin(bi);
}
