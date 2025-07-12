#include <stdio.h>
#define MAX 1000

int get_line(char str[], int lim);
int myatoi(char str[]);
int lowerc(int c);

int main() {
	int d, conv, i, c;
	char str[MAX];
	
	while ((d = get_line(str, MAX)) > 0) {
		for (i = 0; i < d; ++i)
			putchar(lowerc(str[i]));
	}		

	return 0;
}

int get_line(char str[], int lim) {
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != '\n' && c != EOF; ++i)
		str[i] = c;
	if (c == '\n') {
		str[i] = c;
		++i;
	}
	str[i] = '\0';
	return i;
}
	
int myatoi(char str[]) {
	int i, n;

	n = 0;
	for (i = 0; str[i] >= '0' && str[i] <= '9'; ++i) 
		n = 10 * n + (str[i] - '0');
	return n;
}

int lowerc(int c) {
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else 
		return c;
}
