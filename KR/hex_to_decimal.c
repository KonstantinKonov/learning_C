#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

unsigned long hex_to_dec(char *str)
{
	int len = strlen(str);
	int order = 0;
	int result = 0;
	int base = 1;
	char c;

	while( len - 1 - order >= 0 && (c = str[len - 1 - order]) != 'x' && c != 'X') {
		if( !isxdigit( str[len -1 - order] ) )
			break;
		if( str[len - 1 - order] >= '0' && str[len - 1 - order] <= '9' )
			result += (str[len - 1 - order] - 48) * base;
		else if( tolower(str[len - 1 - order]) >= 'a' && tolower(str[len - 1 - order]) <= 'f' )
			result += (tolower(str[len - 1 - order]) - 87) * base;
		base *= 16;
		order++;
	}

	return result;
}

int main()
{
	printf("Enter number in hexadecimal format: ");

	char *str = NULL;
	size_t len = 0;
	size_t real_len = 0;

	real_len = getline(&str, &len, stdin);
	str[real_len - 1] = '\0';

	printf("%lu\n", hex_to_dec(str));

	return 0;
}
