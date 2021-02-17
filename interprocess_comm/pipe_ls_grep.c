#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	int pp[2];
	int pid_out, pid_in;

	if(argc != 3) {
		fprintf(stderr, "need 2 arguments\n");
		exit(1);
	}

	if( pipe(pp) == -1 ) {
		fprintf(stderr, "can't open pipe\n");
		exit(1);
	}

	// child ls out to pipe in
	if( (pid_out = fork()) == 0 ) {
		// pipe in <- stdout
		dup2( pp[1], 1 );
		// close pipe out, release write to pipe
		close( pp[0] );
		execlp("ls", "ls", argv[1], NULL);
		// if execlp fails
		fprintf(stderr, "exec() [1] error\n");
		exit(1);
	}

	// child pipe out to grep in
	if( (pid_in = fork()) == 0 ) {
		// pipe out -> stdin
		dup2( pp[0], 0 );
		//close pipe in, release read from pipe
		close( pp[1] );
		execlp("grep", "grep", argv[2], NULL);
		// if execp fails
		fprintf(stderr, "exe() [0] error\n");
		exit(1);
	}

	close( pp[1] );
	waitpid( pid_out, NULL, 0 );
	close( pp[0] );
	waitpid( pid_in, NULL, 0 );

	return 0;
}	
