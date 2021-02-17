#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
	if( argc == 3 )
	{
		double a = strtod(argv[1], NULL);
		double e = strtod(argv[2], NULL);
		printf("%.2lf^%.2lf = %.2lf\n", a, e, pow(a, e));
	}

	return 0;
}
