#include <stdio.h>
#include <stdlib.h>

char bi[64] = "0110000101100010";

int main()
{
    //  char pen[32] = {'0', '1', '0', '0', '0', '1', '0', '1',
    //                  '0', '1', '0', '1', '0', '1', '0', '1'};
    //  char ben[32] = {'0', '0', '0', '0', '0', '1', '0', '1',
    //                  '0', '1', '0', '1', '0', '1', '0', '1'};
    char fin[32];

    for (int i = 0; i < 16; ++i)
        fin[i] = bi[i] ^ bi[i];

    for (int i = 0; i < 16; ++i)
        printf("%c", fin[i]);
}
