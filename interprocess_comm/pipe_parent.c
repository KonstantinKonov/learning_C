#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define STR_SIZE	1024

int main(void)
{
	// pipe pointer in and out
	int pp[2];
	int pid0, pid1;

	// in and out buffer
	char spp[2][STR_SIZE];

	// open two pipe
	if(pipe(pp) == -1) {
		fprintf(stderr, "pipe() error\n");
		exit(1);
	}

	sprintf(spp[0], "%d", pp[0]);
	sprintf(spp[1], "%d", pp[1]);

	// child process put to pipe
	if( (pid0 = fork()) == 0 ) {
		close(pp[0]);
		execl("./pipe_put", "pipe_put", spp[1], NULL);
		fprintf(stderr, "exec() [put] error\n");
		return -1;
	}

	// child process get from pipe
	if( (pid1 = fork()) == 0 ) {
		close(pp[1]);
		execl("./pipe_get", "pipe1_get", spp[0], NULL);
		fprintf(stderr, "exec() [get] error\n");
		return -1;
	}

	// wait until pid1 (write to pipe)
	waitpid(pid0, NULL, 0);
	close(pp[0]);
	close(pp[1]);
	waitpid(pid1, NULL, 0);

	return 0;
}
