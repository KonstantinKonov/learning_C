#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	extern char **environ;

	char *ls_args[] = {
		"/bin/ls",
		"-l",
		NULL 
	};

	pid_t fork_id = fork();

	if(fork_id == -1) {
		perror("Can't create fork\n");
		exit(1);
	}

	// child
	if( fork_id == 0 ) {
		execve("/bin/ls", ls_args, environ);
		//execl("/bin/ls", "/bin/ls", "-l", NULL);
		perror("Can't run program from child process\n");
		exit(1);
	}

	// parent
	printf("Message from parent: created process with pid = %d\n", fork_id);

	return 0;
}
