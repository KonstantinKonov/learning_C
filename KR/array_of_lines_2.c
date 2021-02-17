#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **get_array_of_strings(int *amount_of_lines, FILE *stream)
{
	int len = 0, nlines = 0;
	char *line = NULL, **lines = NULL;
	size_t n = 0;

	while( (len = getline(&line, &n, stream)) > 1 ) {
		line[len - 1] = '\0';
		nlines++;
		lines = (char **) realloc(lines, sizeof(char *));
		lines[nlines - 1] = (char *) malloc( len * sizeof(char) );
		strcpy( lines[nlines - 1], line );
	}

	*amount_of_lines = nlines;

	return lines;
}

void print_array_of_strings(char **lines, int nlines, FILE *stream)
{
	for(int i = 0; i < nlines; i++)
		fprintf(stream, "%s\n", lines[i]);
}

int main()
{
	int n;
	char **lines = get_array_of_strings(&n, stdin);

	print_array_of_strings(lines, n, stdout);

	return 0;
}
