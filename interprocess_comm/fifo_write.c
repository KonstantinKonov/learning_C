#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// for open
#include <fcntl.h>

// fo write, close
#include <unistd.h>

#define BUF_SIZE		1024

int main(int argc, char **argv)
{
	if(argc != 3) {
		fprintf(stderr, "need 2 arguments\n");
		exit(1);
	}

	int fd = open(argv[1], O_WRONLY);
	if( fd == -1 ) {
		fprintf(stderr, "can't open fifo\n");
		exit(1);
	}

	write( fd, argv[2], strlen(argv[2]) + 1);

	close(fd);

	return 0;
}
