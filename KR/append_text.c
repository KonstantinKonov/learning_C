#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 10000

int main(int argc, char **argv)
{
	if(argc != 3)
		exit(1);

	FILE *fp_to = fopen(argv[1], "a");
	if(fp_to == NULL) {
		printf("Can't open file %s\n", argv[1]);
		exit(1);
	}

	FILE *fp_from = fopen(argv[2], "r");
	if(fp_from == NULL) {
		printf("Can't open file %s\n", argv[2]);
		exit(1);
	}

	char *str = malloc(MAX_STR_LEN * sizeof(char));
	int c, i = 0;
	while( (c = getc(fp_from)) != EOF && i < MAX_STR_LEN - 1 ) {
			str[i] = c;
			i++;
	}
	str[i] = '\0';
			
	fputs(str, fp_to);
	free(str);

	fclose(fp_to);
	fclose(fp_from);

	return 0;
}
