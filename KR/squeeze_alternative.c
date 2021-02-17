#include <stdio.h>
#include <stdlib.h>

void squeeze_alt(char *str1, char *str2)
{
	int state = 0;
	int k = 0;
	for(int i = 0; str1[i] != '\0'; i++) {
		for(int j = 0; str2[j] != '\0'; j++)
			if( str1[i] == str2[j] ) {
				state = 1;
				break;
			}
		if(!state) 
			str1[k++] = str1[i];
		else
			state = 0;
	}
	str1[k] = '\0';
}

int main()
{
	char str1[] = "This is a line";
	char str2[] = "as";

	squeeze_alt(str1, str2);

	printf("%s\n", str1);

	return 0;
}
