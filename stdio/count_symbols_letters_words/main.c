#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
	// Count symbols, lines, words, letters, spaces in the text
	int state;
	int symbols = 0, lines = 1, words = 0, letters = 0, spaces = 0;

	char ch;

	FILE *fp = stdin;
	while ((ch = fgetc(fp)) != EOF)
	{
		symbols++;

		if (ch == '\n')
			lines++;
		else if (ch == ' ')
			spaces++;
		else if (ch != '\t')
			letters++;

		if (ch == ' ' || ch == '\n' || ch == '\t')
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			words++;
		}
	}
	printf("symbols = %d, lines = %d, words = %d, letters = %d, spaces = %d\n", symbols, lines, words, letters, spaces);

	return 0;
}