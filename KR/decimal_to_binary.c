#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimal_to_binary(char *str, int n)
{
	int len = 16;
	int index = 15;

	for(int i = 0; i < len; i++)
		str[i] = '0';
	str[len] = '\0';

	while(n != 0) {
		if(n & 1)
			str[index] = '1';
		else
			str[index] = '0';
		n = (n >> 1);
		index--;
	}
}
			
int main()
{
	int n;
	char str[17];
	scanf("%d", &n);

	decimal_to_binary(str, n);
	printf("%s\n", str);

	return 0;
}
