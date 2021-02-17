#include <stdio.h>
#include <stdlib.h>
#include "myenv.h"

void mysetenv(const char *name, const char *value)
{
	printf("setting variable %s\n", name);
	setenv(name, value, 1);
}
