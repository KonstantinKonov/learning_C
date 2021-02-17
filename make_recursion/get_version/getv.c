#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getv.h"

char *getv()
{
	char *str = NULL;
	size_t n = 0;

	FILE *fp;
	if( (fp = fopen("/proc/version", "r")) != NULL ) {
		getline(&str, &n, fp);
		fclose(fp);
	}

	return str;
}
