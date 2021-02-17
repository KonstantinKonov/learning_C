#include <stdio.h>
#include <ctype.h>

void isalnum_test(FILE *stream)
{
	char c;

	while( (c = getc(stream)) != EOF ) 
		if( c != '\n' ) printf("isalnum? %d\n", isalnum(c));
}

int main()
{
	isalnum_test(stdin);

	return 0;
}
