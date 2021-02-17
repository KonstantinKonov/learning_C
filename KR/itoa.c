#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 100

void reverse(char s[])
{
	int temp, i, j;
	for(i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

void itoa_custom(int n, char s[])
{
	int i = 0, sign;
	if( (sign = n) < 0 )
		n = -n;
	do {
		s[i++] = n % 10 + '0';
	} while( ( n /= 10 ) > 0 );

	if( sign < 0 )
		s[i++] = '-';
	s[i] = '\0';
	//reverse(s);
}

int length(char s[])
{
	int i = 0;
	while( s[i] != '\0' )
		i++;
	return i;
}

int main()
{
	char str[STR_SIZE];
	int n;
	scanf("%d", &n);

	itoa_custom(n, str);
	reverse(str);

	printf("%s\n", str);

	return 0;
}

	
