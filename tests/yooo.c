#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char gnome[40];
int finalBin = 0;
int recursionAdd = 0;

int numToBin(ascii) {

  if (ascii == 0) {
    return finalBin;
  }

  finalBin = finalBin * 10;
  finalBin = ascii % 2 + finalBin;
  // printf("\nBIN: %d\n", finalBin);
  return numToBin(ascii / 2, finalBin);
}

int main() {
  int n;
  printf("plug ur thing in: ");
  //  scanf("%s", gnome);
  fgets(gnome, 40, stdin);

  int i;
  int ascii;
  int binS;
  int dig, revNumber;

  for (i = 0; gnome[i] != 0; i++) {
    finalBin = 0;
    n = 0;
    // printf("\ni is %d", i);
    // printf("\n it num %d", i);
    ascii = gnome[i];
    // printf("\nSHIT %d", numToBin(ascii));
    // finalBin = 0;
    // printf("\nchar %c", gnome[i]);
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
    if (revNumber == 101) {
      revNumber = 0;
    }
    printf("\n%d", revNumber);
  }
  // printf("\n\n%d", numToBin(ascii));
}
