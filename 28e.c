#include <stdio.h>
#define BITS (8 * sizeof(unsigned))

unsigned rightrot(unsigned x, int n);

int main() {
	printf("%u\n", rightrot(240, 5));
}

unsigned rightrot(unsigned x, int n) {
	n = n % BITS;
	if (n == 0)
		return x;
	return (x >> n) | (x << (BITS - n));
}

