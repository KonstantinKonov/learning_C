#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	printf("Limits of type %s: %d to %d\n", "signed char", SCHAR_MIN, SCHAR_MAX);
	printf("Limits of type %s: %d to %d\n", "integer", INT_MIN, INT_MAX);
	printf("Limits of type %s: %ld to %ld\n", "long int", LONG_MIN, LONG_MAX);

	printf("Limits of type %s: %.10e to %.10e\n", "float", FLT_MIN, FLT_MAX);
	printf("Limits of type %s: %.10e to %.10e\n", "double", DBL_MIN, DBL_MAX);

	return 0; 
}
