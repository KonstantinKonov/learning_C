#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main()
{
	pid_t status_1 = fork();
	if( status_1 == 0 ) {
		system("sleep 5");
		return 0;
	}

	pid_t status_2 = fork();
	if( status_2 == 0 ) {
		system("sleep 10");
		return 0;
	}

	int exit_status;
	printf("Child 1: %d, child 2: %d\n", status_1, status_2);
	wait(&exit_status);

	return 0;
}
