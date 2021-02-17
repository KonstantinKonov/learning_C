// Reverse string with recursion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strcut(char *str, int from, int to)
{
	if( from > to )
		return NULL;
	if( to > strlen(str) - 1 )
		to = strlen(str) - 1;
	if( from < 0 )
		from = 0;
	if( str == NULL || strlen(str) == 0 )
		return NULL;

	char *result = (char *) malloc( (to - from + 2) * sizeof(char) );
	result[(to - from + 1)] = '\0';
	for(int i = 0; i < to - from + 1; i++)
		result[i] = str[from + i];
	return result;
}

char *reverse(char *str, int len)
{
	if( len == 2 ) {
		char temp = str[0];
		str[0] = str[1];
		str[1] = temp;
		return str;
	}
	else if( len == 1 ) 
		return str;

	char temp = str[0];
	str[0] = str[len - 1];
	str[len - 1] = temp;

	return reverse(str + 1, len - 2);
}

int main()
{
	char str[100] = "Hello World!";
	//printf( "%s\n", strcut(str, 6, strlen(str)) );
	reverse(str, strlen(str));
	printf("%s\n", str);

	return 0;
}
