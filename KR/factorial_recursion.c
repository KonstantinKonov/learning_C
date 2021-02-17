#include <stdio.h>
#include <stdint.h>

uint64_t factorial(int n)
{
	if(n == 1) return 1;
	return factorial(n - 1) * n;
}

int main()
{
	uint64_t n;

	printf("Enter number: ");
	scanf("%lu", &n);

	printf("Factorial: %lu\n", factorial(n));

	return 0;
}

