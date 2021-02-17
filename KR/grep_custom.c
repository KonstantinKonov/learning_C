// The program searches lines from file where pattern occurs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define str_size 1000

// Enter line
// Parameters: none
// Return: string
char *line_dialog()
{
	printf("Enter pattern: ");

	char *str = NULL;
	size_t n = 0;
	getline(&str, &n, stdin);
	str[strlen(str) - 1] = '\0';

	return str;
}

// Size of file
// Parameters: file descriptor
// Return: unsigned file size
unsigned long file_size(FILE *fp)
{
	if(fp == NULL)
		return 0;

	fseek(fp, 0L, SEEK_END);
	unsigned long sz = ftell(fp);
	rewind(fp);

	return sz;
}

// Find pattern in a file
// Parameters: name of the file - string, pattern to search - string
// Return: string with all lines
char *find_in_file(char *fn, char *pattern)
{
	FILE *fp = fopen(fn, "r");
	if( fp == NULL )
		exit(0);

	unsigned long i = 0;
	size_t n = 0;
	char *str = (char *) malloc(file_size(fp) * sizeof(char));
	str[0] = '\0';
	char *s = NULL;

	while( (i = getline(&s, &n, fp)) != -1 ) {
		if( strstr(s, pattern) != NULL) {
			strcat(str, s);
		}
	}

	fclose(fp);

	return str;
}

int main(int argc, char **argv)
{
	if(argc != 3)
		exit(0);

	char *filename = (char *) malloc( str_size * sizeof(char) );
	strcat(filename, argv[1]);

	char *pattern = (char *) malloc( str_size * sizeof(char) );
	strcat(pattern, argv[2]);

	printf("%s", find_in_file(filename, pattern));

	return 0;
}
