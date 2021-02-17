// The program prints out amount of words which consist of definite amount of letters
#include <stdio.h>
#include <stdlib.h>

#define filename "text.txt"
#define MAX_SYMBOLS_IN_WORD 20
#define IN 1
#define OUT 0

int main()
{
	int c, state = OUT;
	int spectrum[MAX_SYMBOLS_IN_WORD] = {0};
	int nc = 0;
	
	FILE *fp = fopen(filename, "r");
	if( fp == NULL )
		exit(1);

	while( ( c = getc(fp) ) != EOF )
	{
		if( c == ' ' || c == '\n' || c == '\t' || c == ',' || c == '.' || c == ';' || c == ':')
		{
			if( state == IN )
			{
				spectrum[nc]++;
				printf(" %d\n", nc);
				nc = 0;
			}
			state = OUT;
		}
		else if( state == OUT )
		{
			state = IN;
			nc++;
			putchar(c);
		}
		else 
		{
			nc++;
			putchar(c);
		}
	}

	fclose(fp);

	for(int i = 0; i < MAX_SYMBOLS_IN_WORD; i++)
		printf("%d\t%d\n", i, spectrum[i]);

	FILE *gp = popen("gnuplot -persist", "w");
	if(gp != NULL)
	{
		fprintf(gp, "plot '-' with boxes\n");
		for(int i = 0; i < MAX_SYMBOLS_IN_WORD; i++)
			fprintf(gp, "%d\n", spectrum[i]);
		fflush(gp);
	}

	return 0;
}
