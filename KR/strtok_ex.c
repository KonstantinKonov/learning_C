#include <stdio.h>
#include <string.h>

int main()
{
	char *str = NULL;
	char delimiter[2] = " ";
	char *token = NULL;
	size_t n = 0;
	
	getline(&str, &n, stdin);

	token = strtok(str, delimiter );

	while( token != NULL ) {
		printf( "%s\n", token );
		token = strtok(NULL, delimiter);
	}

	return 0;
}

