#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

extern char **environ;

int main(int argc, char **argv)
{
	int i;

	if(argc != 2)
		return 0;

	if(unsetenv(argv[1]) != 0) 
		fprintf(stderr, "Cannot unset variable %s\n", argv[1]);
	else 
		fprintf(stdout, "Variable %s was unset successfully\n", argv[1]);
	return 0;
}
