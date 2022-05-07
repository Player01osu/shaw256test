#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* macros */
#define MIN16 512
#define MIN15 480
#define MIN7 224
#define MIN2 64

/* function declarations */
char *addbin(char a[32], char b[32]);
char *choice(char w[32], char a[32], char b[32]);
void createmesssched(char *s);
char *init(char *s);
char *lsig(char s[32], bool isSigOne);
char *rotr(char s[32], unsigned short __);
char *shr(char s[32], unsigned short __);
char *stringtobinary(char *s);
char *x(char s1[32], char s2[32]);

char *stringtobinary(char *s)
{
	if (s == NULL)
		return 0; /* no input string */
	size_t len = strlen(s);
	char *binary = malloc(len * 8 + 1);

	/* at the end for null terminator */
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

/*
 * Sets up the binary to be hashed and compressed by adding '1' to
 * end, and encoding length to end of last 32 bits and malloc amount
 * of space by multiple of 512
 */
char *init(char *s)
{
	size_t lens = (sizeof(char) + strlen(s) / 512) * 512;
	char *padBin = malloc(lens);
	for (size_t i = 0; i < strlen(s); ++i)
		padBin[i] = s[i];
	for (size_t i = strlen(s) + 1; i < lens - 32; ++i)
		padBin[i] = '0';

	padBin[strlen(s)] = '1';

	int a[64] = { 0 }, n = strlen(s);
	for (int i = 0; n > 0; i++) { /* lazy dec to bin */
		a[i] = n % 2;
		n = n / 2;
	}
	for (int j = 0, i = 511; i > 448; --i, ++j) /* append to end */
		padBin[i] = a[j] + 48;
	return padBin;
}

/*
 * Returns a message schedule of 2048 bits. This is done
 * by taking a string, and performing shift and rotation
 * functions to them until the message schedule is fully
 * expanded.
 */
void createmesssched(char *s)
{
	char tm2[32], tm7[32], tm15[32], tm16[32];
	size_t lens = strlen(s);
	char *messSched = malloc(sizeof(char) * lens);

	strncpy(messSched, s, lens);

	for (size_t i = lens; i < lens * 4; i += 32) {
		for (int j = 0; j < 32; ++j) {
			tm16[j] = *(messSched + (i - MIN16) + j);
			tm15[j] = *(messSched + (i - MIN15) + j);
			tm7[j] = *(messSched + (i - MIN7) + j);
			tm2[j] = *(messSched + (i - MIN2) + j);
		}
		strncpy(tm15, lsig(tm15, false), 32);
		strncpy(tm2, lsig(tm2, true), 32);

		strncat(messSched, addbin(addbin(tm2, (addbin(tm16, tm15))), tm7), 32);
	}
	printf("message schedule: %s\n", messSched);
	free(s);
}

 /* xors two strings */
char *x(char s1[32], char s2[32])
{
	if (s1 == NULL || s2 == NULL)
		return 0; // return empty string
	char *xorf = malloc(sizeof(char) * 32);
	for (size_t i = 0; i < strlen(s1); ++i)
		xorf[i] = (s1[i] ^ s2[i]) + 48;
	return xorf;
}

char buffer[32];
#define LENGTH 32

 /* rotate strings right, string wrap */
char *rotr(char s[32], unsigned short __)
{
	if (s == NULL)
		return 0;
	char *rotr = malloc(sizeof(char) * 32);

	strncpy(buffer, s, LENGTH);
	for (int k = 0; k < __; ++k) { // k determines how many right shift
		for (int j = 0; j < (LENGTH - 1); ++j) {
			char c = buffer[1];
			for (int i = 1; i < LENGTH; ++i)
				rotr[i] = buffer[(i + 1) % LENGTH]; // left shift
			rotr[0] = c;
			strncpy(buffer, rotr, LENGTH);
		}
	}
	return rotr;
}

 /* shift string right, bits loss */
char *shr(char s[32], unsigned short __)
{
	if (s == NULL)
		return 0; // return empty string
	strncpy(buffer, s, LENGTH);
	size_t len = sizeof(*s);
	char *shr = malloc(len * 32);

	shr[0] = '\0';
	for (int j = 0; j < __; ++j) {
		for (int i = 1; i < LENGTH; ++i)
			shr[i] = buffer[i - 1];
		shr[j] = '0'; // fill empty char w/ zeros
		strncpy(buffer, shr, LENGTH);
	}
	return shr;
}

char *lsig(char s[32], bool isSigOne)
{
	if (s == NULL)
		return 0; /* empty string */
	if (!isSigOne)
		return x(x(rotr(s, 7), rotr(s, 18)), shr(s, 3));
	else
		return x(x(rotr(s, 17), rotr(s, 19)), shr(s, 10));
}

/*char *usig(char bi[32], unsigned short o, unsigned short t, unsigned short r)
{
	// xor of rotr 2 rotr 13 and rotr 22
	if (bi == NULL)
		return 0; // return empty string

	return x(x(rotr(bi, o), rotr(bi, t)), rotr(bi, r));
}*/

char *addbin(char a[32], char b[32])
{
	char t[32];
	char *fin = malloc(sizeof(char) * 32);
	char c = '0';

	for (int i = 31; i >= 0; --i) {
		t[i] = (a[i] ^ b[i]) ^ c;
		c = ((a[i] ^ b[i]) & c) | (a[i] & b[i]);
	}

	for (int i = 0; i < 32; ++i)
		fin[i] = t[i];

	return fin;
}

 /* choice of char a or b based off w */
char *choice(char w[32], char a[32], char b[32])
{
	char *c = malloc(strlen(w) / 4 + 1);

	for (size_t i = 0; i < strlen(w) / 3; ++i)
		c[i] = (w[i] == '0') ? a[i] : b[i];
	return c;
}

int main(int argc, char **argv)
{
	char userIn[126];
	char rawBin[512];

	if (argc == 1)
		fgets(userIn, 126, stdin);
	else
		strncpy(userIn, argv[1], 126);

	userIn[strcspn(userIn, "\n")] = '\0'; /* remove newline char */

	strcpy(rawBin, stringtobinary(userIn));

	createmesssched(init(rawBin));

	free(stringtobinary(userIn));

	return 0;
}
