#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>

#define SHARED_SIZE 1024
#define SHARED_STR "Hello World!\n"

int main(void)
{
	// shared memory id
	int mem_id;

	// shared memory buffer
	char *mem_buf;

	// allocated shared memory size
	int mem_size;

	// shared memory data structure
	struct shmid_ds mem_ds;

	// shmget - allocate memory
	mem_id = shmget( IPC_PRIVATE, SHARED_SIZE, IPC_CREAT | IPC_EXCL | 0600 );
	if( mem_id == -1 ) {
		fprintf(stderr, "shmget() error\n");
		exit(1);
	}

	// shmat - perform operations with shared memory, attach
	mem_buf = (char *) shmat( mem_id, NULL, 0 );
	if( mem_buf == (char *) -1 ) { // NULL?
		fprintf( stderr, "shmat() error\n");
		exit(1);
	}

	// get information about shared memory, write it to structure mem_ds
	shmctl( mem_id, IPC_STAT, &mem_ds );

	// get size of the segment
	mem_size = mem_ds.shm_segsz;
	fprintf(stdout, "Size of allocated segment: %d\n", mem_size);
	if( mem_size < strlen(SHARED_STR) ) {
		fprintf(stderr, "allocated size is less than requested\n");
		exit(1);
	}

	// copy string to buffer
	strcpy(mem_buf, SHARED_STR);

	fprintf(stdout, "ID: %d\n", mem_id);
	fprintf(stdout, "Press any key to exit\n");
	fgetc(stdin);

	// shared memory detach 
	shmdt(mem_buf);
	// remove segment
	shmctl( mem_id, IPC_RMID, NULL );

	return 0;
}
