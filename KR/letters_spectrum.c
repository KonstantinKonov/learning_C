// The program prints out frequency of appearing letters
#include <stdio.h>
#include <stdlib.h>

#define filename "text.txt"
#define AMOUNT_OF_LETTERS 26
#define IN 1
#define OUT 0

int main()
{
	int c;
	int spectrum[AMOUNT_OF_LETTERS] = {0};
	
	FILE *fp = fopen(filename, "r");
	if( fp == NULL )
		exit(1);

	while( ( c = getc(fp) ) != EOF )
	{
		if( c >= 'a' && c <= 'z' )
			spectrum[c - 'a']++;
		else if( c >= 'A' && c <= 'Z' )
			spectrum[c - 'A']++;
	}

	fclose(fp);

	for(int i = 0; i < AMOUNT_OF_LETTERS; i++)
		printf("%d\t%d\n", i, spectrum[i]);

	FILE *gp = popen("gnuplot -persist", "w");
	if(gp != NULL)
	{
		fprintf(gp, "plot '-' with boxes\n");
		for(int i = 0; i < AMOUNT_OF_LETTERS; i++)
			fprintf(gp, "%d\n", spectrum[i]);
		fflush(gp);
	}

	return 0;
}
