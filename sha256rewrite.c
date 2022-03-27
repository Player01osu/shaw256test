//#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 256
#define CBUFFERSIZE 512

static char buffer[BUFFERSIZE];

char userIn[120], userInB[120], c;
int bi[512];

/*typedef union messu { // message schedules
  struct mess {
    int *w0[16], *w1[16], *w2[16], *w3[16], *w4[16], *w5[16], *w6[16], *w7[16],
        *w8[16], *w9[16], *w10[16], *w11[16], *w12[16], *w13[16], *w14[16],
        *w15[16], *w16[16], *w17[16], *w18[16], *w19[16], *w20[16], *w21[16],
        *w22[16], *w23[16], *w24[16], *w25[16], *w26[16], *w27[16], *w28[16],
        *w29[16], *w30[16], *w31[16], *w32[16], *w33[16], *w34[16], *w35[16],
        *w36[16], *w37[16], *w38[16], *w39[16], *w40[16], *w41[16], *w42[16],
        *w43[16], *w44[16], *w45[16], *w46[16], *w47[16], *w48[16], *w49[16],
        *w50[16], *w51[16], *w52[16], *w53[16], *w54[16], *w55[16], *w56[16],
        *w57[16], *w58[16], *w59[16], *w60[16], *w61[16], *w62[16], *w63[16];
  } mess;
  int *s[1024];
} messu;

messu setsched(int bi[512]) { // set message schedule
  messu ssched;
  // struct mess *sched_ptr = &sched;
  for (int i = 0; i < 512; ++i)
    ssched.s[i] = &bi[i];
  return ssched;
}*/

char *stringtobinary(char *s) {
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

void preprocess() {
  // converts input to binary, adds bit bit
  // pad with 0 til 64 before 512, fill rest
  // with length of string binary pad in
  // front with 64 zeros

  short int pi;

  // char cbuffer[CBUFFERSIZE];
  //  strcpy(cbuffer, stringtobinary(userIn));
  // for (int i = 0; stringtobinary(userIn)[i] != '\000'; ++i)
  // cbuffer[i] = stringtobinary(userIn)[i];

  for (pi = 0; stringtobinary(userIn)[pi] != '\000'; ++pi) {
    char cbuffer[CBUFFERSIZE];
    // if (pi != strlen(stringtobinary(userIn))) {
    // char *pen[CBUFFERSIZE];
    // pen[pi] = &stringtobinary(userIn)[pi];
    cbuffer[pi] = stringtobinary(userIn)[pi];
    // bi[pi] = atoi(&stringtobinary(userIn)[pi]);
    bi[pi] = atoi(&cbuffer[pi]);
    // bi[pi] = atoi(pen[pi]);
    // }
  }
  bi[pi] = 1;

  /*int a[64] = {0}, n = strlen(stringtobinary(userIn));
  for (int i = 0; n > 0; i++) { // lazy dec to bin
    a[i] = n % 2;
    n = n / 2;
  }
  for (int ii = 0, i = 512; i > 449; --i, ++ii) { // append to end
    int b = a[ii];
    bi[i] = b;
  }*/
}

int main() {

  printf("insert string: ");
  fgets(userInB, 120, stdin);

  for (int i = 0; userInB[i] != '\n'; ++i) // removes '\n'
    userIn[i] = userInB[i];

  preprocess(); // binary 512 bits
  // setsched(bi); // assigns message schedule

  for (int i = 0; i != 513; ++i)
    printf("%d", bi[i]);
  printf("\n");
  // for (int i = 0; i < 16; ++i)
  // printf("%d", *setsched(bi).mess.w1[i]);
  return EXIT_SUCCESS;
}
