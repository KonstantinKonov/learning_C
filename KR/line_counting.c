// The programm counts amount of lines from standard input
#include <stdio.h>

int main(int argc, char **argv)
{
	int c, nl = 0;

	while( (c = getchar()) != EOF )
		if( c == '\n' )
			nl++;
	printf("%d\n", nl);

	return 0;
}
