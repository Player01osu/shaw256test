#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BINARY "00000000000000000011111111111111"
#define LENGTH 32
#define BUFFERSIZE 32

char buffer[BUFFERSIZE];

char *rotr(char bi[32], unsigned short __)
{
    // right rotate string
    if (bi == NULL)
        return 0;
    char *rotr = malloc(300);

    strncpy(buffer, bi, LENGTH);
    for (int k = 0; k < __; ++k) { // k determines how many right shift
        for (int j = 0; j < (LENGTH - 1); ++j) {
            char c = buffer[1];
            for (int i = 1; i < LENGTH; ++i)
                rotr[i] = buffer[(i + 1) % LENGTH]; // left shift
            rotr[0] = c;
            strncpy(buffer, rotr, LENGTH);
        }
    }
    return rotr;
}

char *shr(char bi[32], unsigned short __)
{
    // right shift string
    if (bi == NULL)
        return 0; // return empty string
    strncpy(buffer, bi, LENGTH);
    size_t len = sizeof(*bi);
    char *shr = malloc(len * 25);

    shr[0] = '\0';
    for (int j = 0; j < __; ++j) {
        for (int i = 1; i < LENGTH; ++i)
            shr[i] = buffer[i - 1];
        shr[j] = '0'; // fill empty char w/ zeros
        strncpy(buffer, shr, LENGTH);
    }
    return shr;
}

char *x(char s1[32], char s2[32])
{
    // xors string
    if (s1 == NULL || s2 == NULL)
        return 0; // return empty string
    char *xorf = malloc(sizeof(char) * 25);
    for (size_t i = 0; i < strlen(s1); ++i)
        xorf[i] = (s1[i] ^ s2[i]) + 48;
    return xorf;
}

char *lsig0(char bi[32])
{
    // xor of rotr 7 rotr 18 and shr 3
    if (bi == NULL)
        return 0; // return empty string

    return x(x(rotr(bi, 7), rotr(bi, 18)), shr(bi, 3));
}

int main()
{
    char bi[32] = BINARY;
    printf("%s\n", lsig0(bi));
}
