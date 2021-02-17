#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char **argv)
{
	if(argc != 2)
		exit(0);

	pid_t dpid = atoi(argv[1]);
	if( kill(dpid, SIGKILL) == -1 ) {
		fprintf(stderr, "Can't send signal\n");
		exit(1);
	}

	return 0;
}
