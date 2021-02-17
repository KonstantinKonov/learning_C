#include <stdio.h>

int main()
{
	double d = 9.0/3.0;
	int i = 3;

	printf("%d\n", d == i);

	unsigned long l = 1;
	long ii = -1;

	printf("Is the long value %ld greater than the unsigned long value %lu? Answer: %d\n", ii, l, ii > l);
	printf("The long type value %ld promonted to unsigned long value %lu\n", ii, (unsigned long) ii);


	return 0;
}
