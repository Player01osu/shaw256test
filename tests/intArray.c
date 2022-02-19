#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  unsigned int intArray[20];
  char charArray[20];
  int ascii;

  fgets(charArray, 20, stdin);

  for (int i; ascii != 10; i++) {
    ascii = charArray[i];
    // printf("\n%d", ascii);

    intArray[i] = ascii;
    printf("\n%u", intArray[i]);
  }
}
