#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_cpy(char *s1, char *s2)
{
	while( (*s2++ = *s1++) )
		;
}

int str_cmp(char *s1, char *s2)
{
	for( ; *s1 == *s2; s1++, s2++)
		if(*s1 == '\0')
			return 0;
	return *s1 - *s2;
}

int main()
{
	char *s1 = NULL, *s2 = NULL;
	size_t n = 0;
	getline(&s1, &n, stdin);
	s2 = (char *) malloc( (strlen(s1) + 1) * sizeof(char) );

	str_cpy(s1, s2);

	printf("%s", s2);

	printf("%d\n", str_cmp(s1, s2));

	return 0;
}

