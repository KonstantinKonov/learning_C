#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define PERMS 0666

int main(int argc, char **argv)
{
	int fp_read, fp_write;
	int n;
	char buf[BUFSIZ];

	if(argc != 3) {
		printf("need 2 arguments\n");
		exit(0);
	}
	if( (fp_read = open(argv[1], O_RDONLY, 0)) == -1 ) {
		printf("can't open file %s\n", argv[1]);
		exit(0);
	}
	if( (fp_write = creat(argv[2], PERMS)) == -1 ) {
		printf("can't open file %s\n", argv[2]);
		exit(0);
	}
	while( (n = read(fp_read, buf, BUFSIZ)) > 0)
		if( write(fp_write, buf, n) != n )
			printf("write error on file %s\n", argv[2]);
	return 0;
}
