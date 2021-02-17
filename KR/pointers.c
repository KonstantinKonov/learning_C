#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getint(int *pn)
{
	int c, sign;

	while( isspace(c = getchar()) )
		;

	if( !isdigit(c) && c != EOF && c != '+' && c != '-' ) {
		ungetc(c, stdin);
		return 0;
	}

	sign = ( c == '-' ) ? -1: 1;

	if( c == '+' || c == '-' )
		c = getchar();
	for( *pn = 0; isdigit(c); c = getchar() )
		*pn = 10 * (*pn) + (c - '0');
	*pn *= sign;
	if( c != EOF )
		ungetc(c, stdin);
	return c;
}

int main()
{
	int n, m, *arr[10] = {0};
	int *ptr = &n;

	printf("%ld\t%ld\t%ld\n", &m, &n, &m - &n); 
	printf("%ld\t%ld\t%ld\n", &m, &n, (int)&m - (int)&n); 

	printf("%ld\n", &arr[0]);
	printf("%p\n", arr);
	printf("%ld\n", (long)arr);

	int num;
	getint(&num);
	printf("%d\n", num);

	return 0;
}
