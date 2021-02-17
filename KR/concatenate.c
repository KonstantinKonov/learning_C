#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1000

void concatenate(char *str1, char *str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	
	if( realloc(str1, len1 + len2 + 1) != NULL )
		for(int i = 0; i < len2; i++)
			str1[i + len1] = str2[i];
	str1[len1 + len2] = '\0';
}

void concatenate_KR(char *str1, char *str2)
{
	if( realloc(str1, MAX_STR_LEN) == NULL )
		return;

	int i = 0, j = 0;

	while( str1[i] != '\0' )
		i++;
	while( (str1[i++] = str2[j++]) != '\0' )
		;
}

int main()
{
	char *str1 = NULL, *str2 = NULL;
	size_t len = 0;
	printf("Enter line 1: ");
	getline(&str1, &len, stdin);
	printf("Enter line 2: ");
	getline(&str2, &len, stdin);

	concatenate_KR(str1, str2);

	printf("Concatenated str: %s", str1);

	return 0;
}

