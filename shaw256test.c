#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char gnome[33];
int finalBin = 0;
int recursionAdd = 0;
int i;
int numI;
int ascii;
int binS;
int dig, revNumber;

int numToBin(ascii) {

  if (ascii == 10 && numI == 0) {
    return 0;
  }
  if (ascii == 0) {
    return finalBin;
  }

  finalBin = finalBin * 10;
  finalBin = ascii % 2 + finalBin;
  // printf("\nBIN: %d\n", finalBin);
  // printf("\nASCII: %d\n", ascii);
  numI++;
  return numToBin(ascii / 2, finalBin);
}

int main() {
  int n;
  printf("plug ur thing in: ");
  //  scanf("%s", gnome);
  fgets(gnome, 33, stdin);

  for (i = 0; gnome[i] != 0; i++) {
    finalBin = 0;
    n = 0;
    // printf("\ni is %d", i);
    // printf("\n it num %d", i);
    ascii = gnome[i];
    printf("\nSHIT %08d", numToBin(ascii));
    finalBin = 0;
    //  printf("\nchar %c", gnome[i]);
    // printf("\n%d", ascii);
    n = numToBin(ascii);
    // printf("\n%d", ascii);

    revNumber = 0;
    while (n > 0) {
      dig = n % 10;
      revNumber = (revNumber * 10) + dig;
      n = n / 10;
    }
    // double revNumber = (revNumber * 0.001) - 0.101;
    // double revNumber = revNumber;
    //  printf("\n rev %d", revNumber);
    numI = 0;
    /*if (revNumber == 101) {
      revNumber = 1;
    }*/
    printf("\n%d", revNumber);
  }
  // printf("\n\n%d", numToBin(ascii));
}
