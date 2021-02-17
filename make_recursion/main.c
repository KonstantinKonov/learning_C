#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "get_version/getv.h"
#include "to_up/to_up.h"

int main()
{
	char *str = getv();
	
	printf("%s", str);

	to_up(str);

	printf("%s", str);

	return 0;
}
