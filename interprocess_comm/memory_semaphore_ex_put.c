#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define	MEM_SIZE	1024
#define	MEM_STR		"Hello World!\n"

#define MEM_KEY		2020
#define	SEM_KEY		2020

union semnum {
	int val;
	struct semid_ds *buf;
	unsigned short *array;
} sem_arg;

int main()
{
	int mem_id;
	int sem_id;

	struct shmid_ds ds;
	struct sembuf sb[1];

	unsigned short sem_vals[1];

	mem_id = shmget(MEM_KEY, MEM_SIZE, IPC_CREAT | IPC_EXCL | 0600);
	if(mem_id == -1) {
		fprintf(stderr, "shmget() error\n");
		exit(1);
	}
	fprintf(stdout, "Memory id: %d\n", mem_id);

	sem_id = semget(SEM_KEY, 1, IPC_CREAT | IPC_EXCL | 0600);
	if(sem_id == -1) {
		fprintf(stderr, "semget() error\n");
		exit(1);
	}
	fprintf(stdout, "Semaphore id: %d\n", sem_id);

	sem_vals[0] = 1;
	sem_arg.array = sem_vals;
	if(semctl(sem_id, 0, SETALL, sem_arg) == -1) {
		fprintf(stderr, "semctl() error\n");
		exit(1);
	}

	char *mem_buf = (char *)shmat(mem_id, NULL, 0);

	shmctl(mem_id, IPC_STAT, &ds);
	fprintf(stdout, "Allocated size: %ld\n", ds.shm_segsz);

	strcpy(mem_buf, MEM_STR);

	sb[0].sem_num = 0;
	sb[0].sem_flg = SEM_UNDO;
	sb[0].sem_op = -1;
	semop(sem_id, sb, 1);

	semctl(sem_id, 1, IPC_RMID, sem_arg);
	shmdt(mem_buf);
	shmctl(mem_id, IPC_RMID, NULL);

	return 0;
}
