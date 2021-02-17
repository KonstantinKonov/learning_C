#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	if(argc != 2) 
		return 0;
	char *val = getenv(argv[1]);
	printf("Variable %s has value: %s\n", argv[1], val);

	return 0;
}
