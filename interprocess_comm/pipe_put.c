#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define PIPE_STR	"Hello World!\n"
#define WAIT_TIME	5

int main(int argc, char **argv)
{
	if(argc < 2) 
		exit(1);

	// file descriptor as parameter
	int fd;
	fd = atoi(argv[1]);
	fprintf(stderr, "Wait ");

	// wait WAIT_TIME seconds
	for(int i = 0; i < WAIT_TIME; i++) {
		sleep(1);
		fprintf(stderr, ".");
	}
	fprintf(stderr, "\n");

	// write to pipe
	if( write(fd, PIPE_STR, strlen(PIPE_STR)) == -1 ) {
		fprintf(stderr, "put: write() error\n");
		exit(1);
	}

	close(fd);

	return 0;
}
