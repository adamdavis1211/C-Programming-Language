#include <stdio.h>
#define COLS 20
#define MAX 1000
#define TABDIST(x) TAB - ((x) % TAB)
#define TAB 8

int get_line(char str[], int max);
void reformatprint(char str[], int max);

int main() {
	int d, i, j;
	int lbf;		/* line break flag */
	int plb; 		/* previous last blank */
	int lb; 		/* last blank */
	char input[MAX];

	for (i = 0; i < COLS; ++i) 
		putchar('0');
	putchar('\n');

	while ((d = get_line(input, MAX)) > 0) {
		for (i = plb = lbf = lb = 0; i < d; ++i) {
			if (input[i] == ' ') {
				lb = i;
				++lbf;	
			}	
			if (((i % (COLS-1) == 0) && i != 0) || input[i] == '\n') {	
				if (input[i] == '\n' || lbf == 0)
					lb = i;
				for (j = plb; j <= lb; ++j) 
					putchar(input[j]);
				if (input[i] != '\n') 
					putchar('\n');
				if (lbf == 0) 
					plb = lb;	
				else
					plb = lb+1;
				lbf = 0;
			}	
		}
	}
}



int get_line(char str[], int max) {
	int c, i, j;

	for (i = 0; i < max-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
		if (c == '\t') {
			for (j = 0; j < TABDIST(i) && (j+i) < max-1; ++j) 
				str[i+j] = ' ';
			i += TABDIST(i);
		}
		else		
			str[i] = c;
	}
	if (c == '\n') {
		str[i] = c;
		++i;
	}
	str[i] = '\0';
	return i;
}
