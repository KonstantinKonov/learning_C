#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *str_dbl = "1234.5678";
	char *str_int = "12345";
	int i = 9876;
	double d = 987.654;

	printf("Convert string %s to double %lf\n", str_dbl, atof(str_dbl));
	printf("Convert string %s to int %d\n", str_int, atoi(str_int));

	char i_str[1000];
	char d_str[1000];
	sprintf(i_str, "%d", i);
	sprintf(d_str, "%lf", d);

	printf("Convert int %d to string %s\n", i, i_str);
	printf("Convert double %lf to string %s\n", d, d_str);

	return 0;
}
