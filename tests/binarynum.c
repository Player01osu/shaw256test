#include <math.h>
#include <stdio.h>
#include <stdlib.h>
// #include<iostream>

int userIn;
int finalBin = 0;
int recursionAdd = 1;
// function convert number to binary
int numToBin(userIn) {

  // if end con met, return finalBin
  if (userIn == 0) {
    return finalBin;
  }
  // recursivly add to end of int finalBin and find remainder of userIn
  finalBin = finalBin * 10;
  finalBin = userIn % 2 + finalBin;
  // printf("\n%d", finalBin);
  return numToBin(userIn / 2, finalBin);
}

int main() {
  int n;

  printf("input number to convert to binary: ");
  scanf("%d", &userIn);

  // print final binary from called function
  // printf("\nbinary is %d", numToBin(userIn));

  n = numToBin(userIn);

  printf("\n%d", n);
  // reverse
  int dig, revNumber;

  revNumber = 0;
  while (n > 0) {
    dig = n % 10;
    revNumber = (revNumber * 10) + dig;
    n = n / 10;
  }

  printf("\nrev %d", revNumber);

  return 1;
}
