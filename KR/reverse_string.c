#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

void str_reverse(char *str, char *str_rev)
{
	long int len = strlen(str);
	for(int i = 0; i < len; i++)
		str_rev[i] = str[len - 1 - i];
	str_rev[len] = '\0';
}

int main()
{
	char *str = malloc(MAX_LENGTH * sizeof(char));
	char *str_rev = malloc(MAX_LENGTH * sizeof(char));
	size_t max = MAX_LENGTH;

	getline(&str, &max, stdin);
	long int len = strlen(str);

	//printf("%c", str[strlen(str) - 1]);
	
	if(str[len - 1] == '\n')
		str[len - 1] = '\0';

	str_reverse(str, str_rev);

	printf("%s\n", str_rev);

	return 0;
}
