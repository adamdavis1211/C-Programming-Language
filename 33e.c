#include <stdio.h>
#include <ctype.h>
#define MAX 1000

/* Write a function expand(s1, s2) that expands shorthand notations like a-z in the string
 * s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and 
 * digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading
 * or trailing '-' is taken literally */

void expand(char s1[], char s2[]);

/* pseudo algorithm:
 * 	1. get to first digit or letter.
 * 	2. get to second digit or letter.
 * 	3. compute and store interval.
 * 	4. repeat until '\0'
 *
 */

int main() {
	char s1[MAX], s2[MAX];
	int c, i;

	i = 0;
	while ((c = getchar()) != EOF && i < MAX-1)
		s1[i++] = c;
	s1[i] = '\0';
	expand(s1, s2);
}

void expand(char s1[],char s2[]) {
	int first, second, i, j;

	first = s1[0];
	second = s1[2];
	for (i = first, j = 0; i <= second; i++)
		s2[j++] = i;
	s2[j] = '\0';
	printf("%s\n", s2);
}
