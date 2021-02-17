#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

typedef unsigned char BYTE;

char *decimal_to_binary(BYTE b, int bits)
{
	char *str = (char *) malloc( (bits + 1) * sizeof(char) );
	for(int i = 0; i < bits; i++) 
		str[i] = '0' + ( ( b >> (bits - i - 1) ) & 0x01 );
	str[bits] = '\0';
	return str;
}

char *decimal_to_binary_2(BYTE b, int bits)
{
	char *str = (char *) malloc( (bits + 1) * sizeof(char) );
	int i, j = 0;
	for(i = pow(2, bits - 1); i > 0; i /= 2) 
		if(b & i)
			str[j++] = '1';
		else
			str[j++] = '0';
	str[bits] = '\0';
	return str;
}

int main()
{
	BYTE b = 0;
	while(1) {
		printf("\033[A\33[2KT\r0b%s\n", decimal_to_binary_2(b, 8));
		usleep(100000UL);
		b++;
	}

	return 0;
}
