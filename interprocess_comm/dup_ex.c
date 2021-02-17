#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	if(argc != 2) {
		fprintf(stderr, "need two arguments\n");
		exit(1);
	}

	int fd;
	if( (fd = open(argv[1], O_RDWR)) == -1 ) {
		fprintf(stderr, "can't open the file\n");
		exit(1);
	}
	if( dup2(fd, 1) == -1 ) {
		fprintf(stderr, "can't redirect stream\n");
		exit(1);
	}

	char ch;
	while( read(0, &ch, 1) > 0 )
		write(1, &ch, 1);
	close(fd);

	return 0;
}
