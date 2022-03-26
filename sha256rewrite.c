#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 256

static char buffer[BUFFERSIZE];

char userIn[120], userInB[120], c;
int bi[513];

char *stringToBinary(char *s) {
  // Converts string to binary
  if (s == NULL)
    return 0; /* no input string */
  size_t len = strlen(s);
  char *binary = malloc(len * 8 + 1); // each char is one byte (8 bits) and + 1
                                      // at the end for null terminator
  binary[0] = '\0';
  for (size_t i = 0; i < len; ++i) {
    char ch = s[i];
    for (int j = 7; j >= 0; --j) {
      if (ch & (1 << j)) {
        strcat(binary, "1");
      } else {
        strcat(binary, "0");
      }
    }
  }
  return binary;
}

typedef struct messched {
  short int w0[32], w1[32], w2[32], w3[32], w4[32], w5[32], w6[32], w7[32],
      w8[32], w9[32], w10[32], w11[32], w12[32], w13[32], w14[32], w15[32];
} messched;

void preprocess() {
  // converts input to binary, adds bit bit
  // pad with 0 til 64 before 512, fill rest
  // with length of string binary pad in
  // front with 64 zeros

  short int pi;

  for (pi = 0; stringToBinary(userIn)[pi] != '\000'; ++pi) {
    if (pi != strlen(stringToBinary(userIn))) {
      char cbuffer[512];
      cbuffer[pi] = stringToBinary(userIn)[pi];
      bi[pi] = atoi(&cbuffer[pi]);
    }
  }
  bi[pi] = 1;

  int a[64] = {0}, n = strlen(stringToBinary(userIn));
  for (int i = 0; n > 0; i++) {
    a[i] = n % 2;
    n = n / 2;
  }
  for (int ii = 0, i = 512; i > 449; --i, ++ii) {
    int b = a[ii];
    bi[i] = b;
  }
}
int main() {

  printf("insert string: ");
  fgets(userInB, 120, stdin);

  for (int i = 0; userInB[i] != '\n'; ++i) // removes '\n'
    userIn[i] = userInB[i];

  preprocess();

  for (int i = 0; i != 513; ++i)
    printf("%d", bi[i]);
  return EXIT_SUCCESS;
}
