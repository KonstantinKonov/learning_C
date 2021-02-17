// Pass double type value to this programm to convert Fahr value to Celcius
#include <stdio.h>
#include <stdlib.h>

#define f_to_c(n) 5 * (fahr - 32) / 9.0

int main(int argc, char **argv)
{
	// debug passing arguments argc, argv
	/*
	printf("argc = %d\n", argc);
	for(int i = 1; i < argc; i++)
		printf("argv[%d] = %s\n", i, argv[i]);
	*/

	if (argc == 2)
	{
		double fahr = strtod(argv[1], NULL);
		double celc = f_to_c(fahr);
		//double celc = 5 * (fahr - 32) / 9.0;
		printf("Fahr\tCelcius\n");
		printf("%.2lf\t%.2lf\n", fahr, celc);
	}

	return 0;
}
