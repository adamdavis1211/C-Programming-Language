#include <ctype.h>
#include <stdio.h>
#define MAX 1000

void mystrcpy(char *, char *);
void v1mystrcpy(char *, char *);
void v3mystrcpy(char *, char *);

int main() {
	char s[MAX];
	char t[] = "testing out final version\n";	
	v3mystrcpy(s, t);
	printf("%s", s);
	return 0;
}

/* my_atof: convert string s into double */
double my_atof(char s[]) {
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++);	/* skip white space */
	sign = (s[i] == '-') ? -1 : 1;	
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	return sign * val / power;
}

/* strcpy: copy t to s; array subscript version */
void mystrcpy(char *s, char *t) {
	int i;

	i = 0;
	while ((s[i] = t[i]) != '\0')
		i++;
}

/* strcpy: copy t into s; pointer version */
void v1mystrcpy(char *s, char *t) {
	int i;

	i = 0;
	while ((*s = *t) != '\0') {
		s++;
		t++;
	}
}

/* strcpy: copy t into s; pointer version 2 */
void v2mystrcpy(char *s, char *t) {
	while ((*s++ = *t++) != '\0')
		;
}

/* final version */
void v3mystrcpy(char *s, char *t) {
	while (*s++ = *t++)
		;
}
