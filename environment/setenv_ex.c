#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int ov_flag = 1; // enable overwrite variables

	if(argc != 3) 
		return 0;
	
	setenv(argv[1], argv[2], ov_flag);
	char *var = getenv(argv[1]);
	if(var == NULL)
		printf("Variable %s doesn't exist\n", argv[1]);
	else
		printf("Variable %s was set to %s\n", argv[1], var);
	return 0;
}
