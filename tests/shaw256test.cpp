#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printstringasbinary(char *s) {
  // A small 9 characters buffer we use to perform the conversion
  char output[9];

  // Until the first character pointed by s is not a null character
  // that indicates end of string...
  while (*s) {
    // Convert the first character of the string to binary using itoa.
    // Characters in c are just 8 bit integers, at least, in noawdays computers.
    itoa(*s, output, 2);

    // print out our string and let's write a new line.
    puts(output);

    // we advance our string by one character,
    // If our original string was "ABC" now we are pointing at "BC".
    ++s;
  }
}

int main() {

}
