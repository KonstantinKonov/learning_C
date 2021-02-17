#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	pid_t dpid = getpid();

	if( kill(dpid, SIGABRT) == -1 ) {
		fprintf(stderr, "Can't send signal\n");
		exit(1);
	}

	return 0;
}
