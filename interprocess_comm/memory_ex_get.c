#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>

int main(int argc, char **argv)
{
	int mem_id;
	char *mem_buf;

	if( argc < 2 ) 
		exit(1);

	// attach memory buffer to shared memory with segment id
	mem_id = atoi(argv[1]);
	mem_buf = (char *) shmat( mem_id, NULL, 0 );
	if( mem_buf == (char *) -1 ) {
		fprintf(stderr, "shmar() error\n");
		exit(1);
	}

	printf("Message: %s\n", mem_buf);
	shmdt(mem_buf);

	return 0;
}
