// The program reads standard input, deletes multiple spaces, prints to standard output
#include <stdio.h>

#define IN 1
#define OUT 0

int main(int argc, char **argv)
{
	int c, state = OUT;

	while( (c = getchar()) != EOF )
	{
		if( c == ' ' )
		{
			if( state == OUT)
			{
				putchar(c);
				//printf("%c", c);
			}
			state = IN;
		}
		else
		{
			state = OUT;
			putchar(c);
			//printf("%c", c);
		}
	}

	return 0;
}




