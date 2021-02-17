#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define PIPE_STR	"Hello World!\n"
#define WAIT_TIME	5

int main(int argc, char **argv)
{
	if(argc < 2) 
		exit(1);

	// pipe identifies as parameter
	int fd;
	fd = atoi(argv[1]);
	
	// read file
	char ch;
	while(read(fd, &ch, 1) > 0)
		// and write to stdout
		write(1, &ch, 1);

	close(fd);

	return 0;
}
