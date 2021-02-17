// The program counts chars, words, lines from file
#include <stdio.h>

#define filename "text.txt"
#define IN 1
#define OUT 0

int main(int argc, char **argv)
{
	int c, state = OUT;
	int nc = 0, nw = 0, nl = 0;

	FILE *fp = fopen(filename, "r");

	while( (c = getc(fp)) != EOF )
	{
		nc++;
		if( c == '\n' )
			nl++;
		if( c == ' ' || c == '\n' || c == '\t' )
			state = OUT;
		else if( state == OUT )
		{
			state = IN;
			nw++;
		}
	}

	fclose(fp);

	printf("%d\t%d\t%d\n", nc, nw, nl);

	return 0;
}


