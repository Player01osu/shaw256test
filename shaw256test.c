#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char gnome[33];
int finalBin = 0;
int recursionAdd = 0;
int i;
int numI = 0;
int begPad = 0;
int ascii;
int binS;
int dig, revNumber;

int numToBin(ascii) {

  if (ascii == 10 && numI == 0) {
    return 0;
  }
  if (ascii == 0) {
    while (numI < 8) {
      finalBin = finalBin * 10;
      numI++;
    }
    return finalBin;
  }

  finalBin = finalBin * 10;
  finalBin = ascii % 2 + finalBin;
  if (finalBin == 0) {
    begPad++;
  }
  numI++;
  return numToBin(ascii / 2, finalBin);
}

int main() {
  int n;
  printf("plug ur thing in: ");
  fgets(gnome, 33, stdin);

  for (i = 0; gnome[i] != 0; i++) {
    finalBin = 0;
    n = 0;
    ascii = gnome[i];
    finalBin = 0;

    // calls numToBin function and passes ascii, sets n to that //
    n = numToBin(ascii);
    int padEnd = 0;
    int ii = 0;

    // reverse binary //
    revNumber = 0;
    while (n > 0) {
      dig = n % 10;
      ii++;
      revNumber = (revNumber * 10) + dig;
      n = n / 10;
    }
    while (begPad != 0) {
      revNumber = revNumber * 10;
      begPad--;
    }

    printf("\nFinal Binary: %08d", revNumber);
    numI = 0;
    /*if (revNumber == 101) {
      revNumber = 1;
    }*/
    // printf("\n%d", revNumber);
  }
  // printf("\n\n%d", numToBin(ascii));
}
