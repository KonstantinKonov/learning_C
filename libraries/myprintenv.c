#include <stdio.h>
#include <stdlib.h>
#include "myenv.h"

void myprintenv(const char *name)
{
	char *value = getenv(name);
	if(value == NULL) {
		printf("Variable %s doesn't exist\n", name);
		return;
	}
	printf("%s=%s\n", name, value);
}
