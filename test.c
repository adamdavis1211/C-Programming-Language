#include <stdio.h>
#include "util.c"

int mystrlen(char s[]);

int main() {
	char str[] = "12345678";
	printf("%d\n", mystrlen(str));
}

/* strelen: return length of string s */
int mystrlen(char s[]) {
	int n;

	for (n = 0; *s != '\0'; s++)
		n++;
	return n;

}

int v2mystrlen(char *s) {
	char *p = s;

	while (*p != '\0')
		p++;
	return p - s;
}
