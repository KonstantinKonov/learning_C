#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define filename "text.txt"

char *read_file_to_str(char *fn)
{
	unsigned long ss = 10;
	unsigned long i = 0;
	char c;
	char *str = (char *) malloc(ss * sizeof(char));

	FILE *fp = fopen(filename, "r");
	if( fp == NULL )
		return NULL;

	while( (c = getc(fp)) != EOF ) {
		if( i >= ss - 1 ) {
			ss *= 2;
			str = (char *) realloc(str, ss * sizeof(char));
			if(str == NULL) 
				return NULL;
		}
		str[i] = c;
		i++;
	}
	str[i] = '\0';

	fclose(fp);
	return str;
}

unsigned long read_file_to_str_2(char *fn, char **str)
{
	unsigned long ss = 10;
	unsigned long i = 0;
	char c;
	*str = (char *) malloc(ss * sizeof(char));

	FILE *fp = fopen(filename, "r");
	if( fp == NULL )
		return -1;

	while( (c = getc(fp)) != EOF ) {
		if( i >= ss - 1 ) {
			ss *= 2;
			*str = (char *) realloc(*str, ss * sizeof(char));
			if(*str == NULL) 
				return -1;
		}
		(*str)[i] = c;
		i++;
	}
	(*str)[i] = '\0';

	fclose(fp);
	return i - 1;
}


int main()
{
	char *str = read_file_to_str(filename);

	printf("%s\n", str);

	free(str);

	char *str2 = NULL;

	unsigned long bytes_read = read_file_to_str_2(filename, &str2);

	printf("%s\n", str2);
	printf("Bytes read: %lu\n", bytes_read);

	free(str2);

	return 0;
}
