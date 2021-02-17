#include <stdio.h>
#include <ctype.h>

#include "to_up.h"

void to_up(char *str) 
{
	int i = 0;
	while( str[i] != '\0' ) {
		str[i] = toupper(str[i]);
		i++;
	}
}
