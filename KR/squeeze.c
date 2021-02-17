#include <stdio.h>
#include <stdlib.h>

void squeeze(char *str, char c)
{
	int i, j;
	for(i = j = 0; str[i] != '\0'; i++)
		if(str[i] != c)
			str[j++] = str[i];
	str[j] = '\0';
}

int main()
{
	char *str = NULL;
	size_t len = 0;
	getline(&str, &len, stdin);

	squeeze(str, ' ');

	printf("%s", str);

	return 0;
}
