// The program reads text from file and deletes multiple spaces, prints to stdout
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define filename "text.txt"
#define IN 1
#define OUT 0

int main(int argc, char **argv)
{
	int c;
	int state = OUT;

	FILE *fp = fopen(filename, "r");

	if(fp == NULL)
		exit(0);

	while( (c = getc(fp)) != EOF )
	{
		if( c == ' ')
		{
			if( state == OUT )
				putchar(c);
			state = IN;
		}
		else
		{
			putchar(c);
			state = OUT;
		}
	}

	fclose(fp);

	return 0;
}

