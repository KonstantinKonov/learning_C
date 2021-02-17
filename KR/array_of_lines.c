#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000

// array of pointers char*, array of lines
char *lineptr[MAXLINES]; // precedence ?

int read_lines(char *lineptr[], int maxlines)
{
	int len, nlines = 0;

	char *line = NULL, *p;
	size_t n = 0;

	while( (len = getline(&line, &n, stdin)) > 1 && (p = (char *)malloc( (len + 1) * sizeof(char))) != NULL ) {
		if( nlines >= maxlines )
			return -1;
		else {
			line[len - 1] = '\0'; // delete newline symbol
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}

	return nlines;
}

int compare(const void *a, const void *b)
{
	if( *(char *)a < *(char *)b)
		return -1;
	else if( *(char *)a > *(char *)b)
		return 1;
	else 0;
}

void sort_lines(char *lineptr[], int nlines)
{
	qsort(&lineptr, nlines, sizeof(char), &compare);
}

void print_lines(char *lineptr[], int nlines)
{
	int i;

	for( i = 0; i < nlines; i++ )
		printf("%s\n", lineptr[i]);
}

int main()
{
	int nlines = read_lines(lineptr, MAXLINES);

	sort_lines(lineptr, nlines);

	print_lines(lineptr, nlines);

	return 0;
}
