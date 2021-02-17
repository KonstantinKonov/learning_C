#include <stdio.h>

#define MAX_LENGTH 1000

int getline_stdin(char line[], int maxline);
int getline_file(char line[], int maxline, char filename[]);
void copy(char to[], char from[]);

int main(int argc, char **argv)
{
	int len, max = 0;

	char line[MAX_LENGTH];
	char longest_line[MAX_LENGTH];

	if(argc == 2) {
		while( (len = getline_file(line, MAX_LENGTH, argv[1])) > 0 )
			if( len > max ) {
				max = len;
				copy(longest_line, line);
			}
	}
	else if(argc == 1) {
		while( (len = getline_stdin(line, MAX_LENGTH)) > 0 )
			if( len > max ) {
				max = len;
				copy(longest_line, line);
			}
	}
	if( max > 0 )
		printf("%s", longest_line);
	return 0;
}

// getline: read a line from file into variable 'line', return length
int getline_file(char line[], int maxline, char filename[])
{
	int c, i;

	FILE *fp = fopen(filename, "r");
	if( fp == NULL ) {
		fprintf(stderr, "%s %s\n", "Can't open the file", filename);
		return 0;
	}

	static long int filepos;
	fseek(fp, filepos, SEEK_SET);
	

	for(i = 0; i < maxline - 1 && ( c = getc(fp) ) != EOF && c != '\n'; i++)
		line[i] = c;
	if(c == '\n') {
		line[i] = c;
		i++;
	}

	filepos = ftell(fp);

	line[i] = '\0';

	fclose(fp);

	return i;
}

// getline: read a line into variable 'line', return length
int getline_stdin(char line[], int maxline)
{
	int c, i;

	for(i = 0; i < maxline - 1 && ( c = getchar() ) != EOF && c != '\n'; i++)
		line[i] = c;
	if(c == '\n') {
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return i;
}

// copy: copy string 'from' to 'to'
void copy(char to[], char from[])
{
	int i = 0;

	while( (to[i] = from[i]) != '\0' )
		++i;
}
