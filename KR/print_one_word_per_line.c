// The program prints one word per line
#include <stdio.h>
#include <stdlib.h>

#define filename "text.txt"
#define IN 1
#define OUT 0

int main()
{
	int c, state = OUT;

	FILE *fp = fopen(filename, "r");
	if( fp == NULL )
		exit(1);

	while( (c = getc(fp)) != EOF )
	{
		if( c == ' ' || c == ',' || c == '.' || c == '\t' || c == ':' || c == ';' || c == '-')
		{
			if( state == IN )
			{
				putchar('\n');
			}
			state = OUT;
		}
		else if( state == OUT )
		{
			state = IN;
			putchar(c);
		}
		else
		{
			putchar(c);
		}
	}

	fclose(fp);
	
	return 0;
}

			

