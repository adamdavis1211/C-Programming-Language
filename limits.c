#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	printf("max size of int: %d\n", INT_MAX);
	printf("bits in an int: %d\n\n", INT_MIN);

	printf("max size of a char: %d\n", CHAR_MAX);
	printf("min size of a char: %d\n\n", CHAR_MIN); 
	
	printf("max size of a short int: %d\n", SHRT_MAX);
	printf("min size of a short int: %d\n\n", SHRT_MIN);

	printf("max size of a long int: %ld\n", LONG_MAX);
	printf("min size of a long int: %ld\n\n", LONG_MIN);

	printf("max size of unsigned int: %u\n\n", UINT_MAX);
	printf("max size of unsigned char: %u\n\n", UCHAR_MAX);
	printf("max size of unsiged short int: %u\n\n", USHRT_MAX);
	printf("max size of unsigned long int: %lu\n\n", ULONG_MAX);	


	printf("max float: %f\n", FLT_MAX);
	printf("max float: %e\n\n", FLT_MAX);

	printf("max double precision float: %lf\n", DBL_MAX);
	return 0;
}
