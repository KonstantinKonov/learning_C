#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX_LEN 100

char *reverse(char *str)
{
	int temp;
	int i = 0, j = strlen(str) - 1;
	while( i < j ) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}

	return str;
}

char *itob(int n, int b)
{
	char *str = (char *) malloc( STR_MAX_LEN * sizeof(char) );

	int i = 0;
	while(n != 0) {
		if(n % b > 9)
			str[i] = n % b - 10 + 'A';
		else
			str[i] = n % b + '0';
		n /= b;
		i++;
	}
	str[i] = '\0';
	str = reverse(str);

	return str;
}

int main(int argc, char **argv)
{
	if(argc != 3)
		exit(0);

	int n = atoi(argv[1]);
	int base = atoi(argv[2]);

	char *str = itob(n, base);

	printf("%s\n", str);

	free(str);
	return 0;
}
