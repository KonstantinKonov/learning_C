#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define filename "text.txt"
#define BUFF_SIZE 10000

char *read_from_file(char *fn, unsigned int str_size)
{
	unsigned long i = 0;
	unsigned long bytes_read = 0;
	size_t n = 0;
	char *s = NULL;
	char *str = malloc(str_size * sizeof(int));

	FILE *fp = fopen(fn, "r");

	while( (i = getline(&s, &n, fp)) != -1 ) {
			strcat(str, s);
			bytes_read += i;
	}

	fclose(fp);
	str[bytes_read] = '\0';
	return str;
}

int main()
{
	char *str = read_from_file(filename, BUFF_SIZE);

	printf("%s", str);

	return 0;
}
