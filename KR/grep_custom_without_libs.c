// The program searches pattern in a file. This program does not use string.h library
#include <stdio.h>
#include <stdlib.h>

// get_line reads file to a string variable
// Parameters: pointer to string, file descriptor
// Return: bytes read - unsigned long
unsigned long get_line(char **, FILE *);

// str_len counts characters in a string
// Parameters: string
// Return: amount of characters in string - unsigned long
unsigned long str_len(char *);

// the function counts size of a file
// Parameters: string
// Return: size of a file in bytes
unsigned long file_size(char *);

// search the first occurences of string
// Parameters: string where to find, string what to find
// Return: index of first occurence string, -1 if not found
long str_str(char *, char *);

unsigned long get_line(char **str, FILE *stream)
{
	char c;
	unsigned long i = 0;
	size_t allocated = 10;
	*str = (char *) malloc(allocated * sizeof(char));

	while( (c = getc(stream)) != EOF && c != '\n') {
		if( allocated <= i - 1 ) {
			allocated *= 2;
			*str = realloc(*str, allocated * sizeof(char));
			if( *str == NULL ) {
				free(*str);
				exit(0);
			}
		}
		(*str)[i++] = c;
	}

	(*str)[i] = '\0';

	return i;
}

unsigned long str_len(char *str)
{
	char c;
	unsigned long i = 0;

	while( str[i++] != '\0' );

	return i - 1;
}

unsigned long file_size(char *fn)
{
	unsigned long i = 0;
	int c;

	FILE *fp = fopen(fn, "r");
	if(fp == NULL)
		return -1;
	
	while( (c = getc(fp)) != EOF )
		i++;

	fclose(fp);

	return i;
}

long str_str(char *where, char *what)
{
	unsigned long i = 0, j = 0;
	long ptr = -1;

	while( where[i] != '\0' ) {
		while( where[i] == what[j] && what[j] != '\0' ) {
			if( ptr == -1 )
				ptr = i;
			
			if( where[i] == '\0' )
				return -1;

			j++;
			i++;
		}
		if( j > 0 && what[j] == '\0' ) 
			return ptr;
		j = 0;
		ptr = -1;
		i++;
	}

	return -1;
}

int main()
{
	char *str = NULL;
	char *s = NULL;

	printf("%s", "Enter text where to search: ");
	get_line(&str, stdin);
	printf("%s", "Enter pattern to search: ");
	get_line(&s, stdin);

	printf("%s\n", str);

	printf("%ld\n", str_str(str, s)); 

	return 0;
}
