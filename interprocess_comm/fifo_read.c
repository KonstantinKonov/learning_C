#include <stdio.h>
#include <stdlib.h>

// for mkfifo
#include <sys/types.h>
#include <sys/stat.h>

// for unlink
#include <unistd.h>

#define BUF_SIZE		1024

int main(int argc, char **argv)
{
	if( mkfifo(argv[1], 0640) == -1 ) {
		fprintf(stderr, "can't create fifo\n");
		exit(1);
	}

	FILE *fp = fopen(argv[1], "r");
	if( fp == NULL ) {
		fprintf(stderr, "can't open fifo\n");
		exit(1);
	}

	char *buf = (char *) malloc( BUF_SIZE * sizeof(char) );
	if( buf == NULL ) {
		fprintf(stderr, "can't allocate memory\n");
		exit(1);
	}

	size_t n = 0;
	char *str;
	while( getline(&str, &n, fp) != -1 )
		fprintf(stdout, "%s\n", str);
	//fscanf(fp, "%s", buf);
	//printf("%s\n", buf);

	fclose(fp);
	free(buf);

	// delete fifo channel
	unlink(argv[1]);

	return 0;
}
