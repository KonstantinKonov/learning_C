#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STR_SIZE 100

int atoi_custom(char *s)
{
	int i, n, sign;
	
	for( i = 0; isspace(s[i]); i++ )
		;

	sign = (s[i] == '-') ? -1 : 1;
	while(s[i] == '+' || s[i] == '-')
		i++;
	for(n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	
	return sign * n;
}

int main()
{
	char *s = malloc(STR_SIZE * sizeof(char));
	scanf("%s", s);

	printf("%d\n", atoi_custom(s));

	free(s);
	return 0;
}
