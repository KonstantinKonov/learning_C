#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main()
{
	char filename[] = "test.txt";
	int fd = open(filename, O_RDONLY);
	if(fd == -1)  {
		perror("Can't open file\n");
		exit(1);
	}

	struct iovec *vector = NULL;

	if( readv(fd, vector, 10) <= 0 ) {
		perror("Can't read from file\n");
		exit(2);
	}

	printf("%d\n", vector->iov_base);

	return 0;
}

