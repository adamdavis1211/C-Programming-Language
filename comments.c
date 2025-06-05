#include <stdio.h>
#define IC 0 	/* in comment */
#define RT 1 	/* in regular text */
#define SL 2	/* in string literal */
#define ICC 3 	/* in char const */
#define CE 4 	/* comment entry */
#define CX 5 	/* comment exit */
#define MAX 1000

int main() {
	int c, state;

	state = RT;
	while ((c = getchar()) != EOF) {
		if (state == RT) {
			if (c == '/') 
				state = CE;
			else if (c == '"') {
				putchar(c);
				state = SL;
			}
			else if (c == '\'') {
				putchar(c);
				state = ICC;
			}
			else 
				putchar(c);
		}
		else if (state == CE) {
			if (c == '*') {
				state = IC;
			}
			else { 
				state = RT;
				putchar('/');
				putchar(c);
			}
		}
		else if (state == IC) { 
			if (c == '*')
				state = CX;
		}
		else if (state == CX) {
			if (c == '/') {
				state = RT;
			}
			else { 
				state = IC;
				putchar('*');
				putchar(c);
			}
		}					
		else if (state == SL) {
			if (c == '"') {
				state = RT;
				putchar(c);
			}
			else 
				putchar(c);
		}
			
		else if (state == ICC) {
			if (c == '\'') {
				state = RT;	
				putchar(c);
			}
			else 
				putchar(c);
		}
	}
}
