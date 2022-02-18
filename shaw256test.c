#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define zero "0"
#define one "1"

char gnome[33];
char addedBin[498];
int finalBin = 0;
int recursionAdd = 0;
int i;
int numI = 0;
int begPad = 0;
int ascii;
int binS;
int dig, revNumber;
int addBin;

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
  char padSixtyFour[84];
  int n;
  char revPadded[18 + 1];
  char bruhz = '0';
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

    // adds zero padding to end of binary
    while (begPad != 0) {
      revNumber = revNumber * 10;
      begPad--;
    }

    // printf("\nFinal Binary: %08d", revNumber);
    numI = 0;

    sprintf(revPadded, "%08d", revNumber);
    // printf("\n%s", revPadded);

    strncat(addedBin, revPadded, 8);

    // printf("\nadded %s", addedBin);
  }

  int strLength = 0;

  for (int vi = 0; addedBin[vi] != 0 && addedBin[vi] != 0; vi++) {
    strLength++;
    // printf("\n string length: %d", strLength);
  }

  while (strLength < 448) {
    strncat(addedBin, &bruhz, 1);
    strLength++;
  }
  printf("\n string pad %s", addedBin);
  printf("\nstring length final is:%d", strLength);
  long double unpaddedAdded = 0;
  char testOZ;

  char *ptr;
  long ret;

  ret = strtoul(addedBin, &ptr, 10);
  printf("\nThe number(unsigned long integer) is %lu\n", ret);

  // Converting string addedBin to an int
  /*for (int iii; addedBin[iii] != 0; iii++) {
    // Compare if char in array addedBin is zero
    testOZ = addedBin[iii];

    if (strcmp(&testOZ, zero) == 0) {
      unpaddedAdded = (unpaddedAdded * 10);
    }
    // Compare if char in array addedBin is one
    if (strcmp(&testOZ, one) == 0) {
      unpaddedAdded = (unpaddedAdded * 10) + 1;
    }
  }*/

  unpaddedAdded = unpaddedAdded / 100000000;

  // printf("\nunpaddedAdded is %Lf", unpaddedAdded);

  // printf("\nPADDEDADDED is %0448Lf", unpaddedAdded);
  //  printf("\n\n%d", numToBin(ascii));
}
