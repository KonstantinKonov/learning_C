#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char *str1 = NULL;
	char *str2 = NULL;
	size_t n = 0;

	// get lines from stdin
	while(1) {
		getline(&str1, &n, stdin);
		getline(&str2, &n, stdin);
		printf("strcmp: %d\n", strcmp(str1, str2));
	}

	return 0;
}
