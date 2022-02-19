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
int numI = 0;
int begPad = 0;
int ascii;
int binS;
unsigned int strToInt[300];
int dig, revNumber;
int addBin;

// takes ascii and converts it to binary, does so recursively
int numToBin(ascii) {
  // return 0 on return ascii // biproduct of fgets
  if (ascii == 10 && numI == 0) {
    return 0;
  }
  // once done recursing, it will == 0, pad ending with 0 until finalBin is 8
  // bits
  if (ascii == 0) {
    while (numI < 8) {
      finalBin = finalBin * 10;
      numI++;
    }
    return finalBin;
  }

  // actual binary alg, move down 1 decimal, divide by 2 get remainder, append
  // to finalBin
  finalBin = finalBin * 10;
  finalBin = ascii % 2 + finalBin;
  // if the binary starts with zeros, count how many zeros and append them later
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

  // iterates through array of user input, converts to ascii, binary, then
  // appends it to revPadded
  for (int i = 0; gnome[i] != 0; i++) {
    numI = 0;
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

    // pads each byte with 0 to beg
    sprintf(revPadded, "%08d", revNumber);
    // appends revPadded to addedBin
    strncat(addedBin, revPadded, 8);
  }

  int strLength = 0;

  // iterates through to check for length of string
  for (int vi = 0; addedBin[vi] != 0; vi++) {
    strLength++;
  }

  // append 0 to end of string until string length == 448
  while (strLength < 448) {
    strncat(addedBin, &bruhz, 1);
    strLength++;
  }

  // need this to properly check char in array
  char testOZ;

  // Converting string addedBin to an int
  for (int iii; addedBin[iii] != 0; iii++) {
    // Compare if char in array addedBin is zero
    testOZ = addedBin[iii];

    if (strcmp(&testOZ, zero) == 0) {
      strToInt[iii] = 0;
    }
    // Compare if char in array addedBin is one
    if (strcmp(&testOZ, one) == 0) {
      strToInt[iii] = 1;
    }
  }
  printf("\nunsigned int is: ");

  for (int i = 0; i < 448; i++) {
    printf("%u", strToInt[i]);
  }
}
