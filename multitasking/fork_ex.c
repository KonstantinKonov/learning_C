#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t fork_id = fork();

	//child
	if( fork_id == 0 )
		printf("Message from child, pid = %d, ppid = %d\n", getpid(), getppid());
	else
		printf("Message from parent, pid = %d, ppid = %d, child pid = %d\n", getpid(), getppid(), fork_id);

	return 0;
}
