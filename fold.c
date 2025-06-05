#include <stdio.h>
#define COLS 20
#define MAX 1000
#define INIT 0
#define WORD 1
#define BLANK 2
#define TABDIST(x) TAB - ((x) % TAB)
#define TAB 8

int get_line(char str[], int max);
void reformatprint(char str[], int max);

int main() {
	int d;
	char input[MAX];
	
	while ((d = get_line(input, MAX)) > 0) 
		reformatprint(input, d);	
}

void reformatprint(char input[], int max) {
	int col, i, j, state, wi;
	char line[COLS];
       	char word[COLS];

	state = i = col = wi = INIT;
	for (i = 0; i < max; ++i) {
		if (col >= COLS) { 			/* max chars in line buffer */
			line[col] = '\0';	
			printf("%s", line);
			col = 0;
		}
		else if (state == INIT && (input[i] == ' ' || input[i] == '\t')) { 	/* initial char is blank */
			if (input[i] == ' ') {
				line[col] = input[i];
				++col;
			} else if (input[i] == '\t') {
				for (j = TABDIST(col); j > 0 && col < COLS; --j) {
					line[col] = ' ';
					++col;
				}
			}
		}	
		else if (state == INIT && input[i] != ' ' && input[i] != '\t') {	/* first non blank char */
			state = WORD;	
			word[wi] = input[i];
			++wi;
		}
		else if (state == WORD && input[i] != ' ' && input[i] != '\t') {	/* inside of a word */
			word[wi] = input[i];
			++wi;
		}
		else if (state == WORD && (input[i] == ' ' || input[i] == '\t')) {	/* end of a word */
			word[wi] = '\0';		
			state = BLANK; 
			if ((col + wi) < COLS) {
				for (j = 0; j < wi; ++j) 
					line[col+j] = word[wi];	
				col += wi;	
				wi = 0;
			}
			else {
				for (j = 0; j < (COLS - col); ++j)
					line[j] = ' ';
				col += j;

			}
		}
	}
}


int get_line(char str[], int max) {
	int c, i;

	for (i = 0; i < max-1 && (c=getchar()) != EOF && c != '\n'; ++i)
		str[i] = c;
	if (c == '\n') {
		str[i] = c;
		++i;
	}
	str[i] = '\0';
	return i;
}
