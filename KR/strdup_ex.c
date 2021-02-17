#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *str1 = "Hello World!";

	char *str2 = strdup(str1);

	printf("%s\n%s\n", str1, str2);

	return 0;
}
