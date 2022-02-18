#include <stdio.h>
#include <string.h>

int main() {

  char string1[12] = "234";
  char string2[12] = "234";
  char string3[12];
  int len;

  /* copies string1 into string3 */
  strcpy(string3, string1);
  printf("strcpy( string3, string1) :  %s\n", string3);

  /* concatenates string1 and string2 */
  strcat(string1, string2);
  printf("strcat( string1, string2):   %s\n", string1);

  /* total lenghth of string1 after concatenation */
  len = strlen(string1);
  printf("strlen(string1) :  %d\n", len);

  return 0;
}
