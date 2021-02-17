#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main()
{
	pid_t res = fork();

	// child
	if(res == 0) {
		execlp("ls", "ls", "-l", NULL);
		fprintf(stderr, "Exec error\n");
		exit(1);
	}

	// parent wait
	int exit_status;
	pid_t childpid = wait(&exit_status);

	if( WIFEXITED(exit_status) ) 
		printf("Process with PID=%d has exited with code %d\n", childpid, WIFEXITED(exit_status));

	return 0;
}
