#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	for(int i = 0; i < argc; i++) {
		printf("argc = %d, index = %d, argv = %s\n", argc, i, argv[i]);
	}

	if(argc == 3) {
		double sum = atof(argv[1]) + atof(argv[2]);
		printf("sum = %lf\n", sum);
	}

	return 0;
}

