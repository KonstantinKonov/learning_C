#include <stdio.h>

void filecopy(FILE *fp_to, FILE *fp_from)
{
	int c;
	while( (c = getc(fp_from)) != EOF )
		putc(c, fp_to);
}

int main(int argc, char **argv)
{
	FILE *fp;

	if(argc == 1)
		filecopy(stdout, stdin);
	else
		while(--argc > 0)
			if( (fp = fopen(*++argv, "r")) == NULL ) {
				printf("cat: can't open %s\n", *argv);
				return 1;
			}
			else {
				filecopy(stdout, fp);
				fclose(fp);
			}
	return 0;
}
