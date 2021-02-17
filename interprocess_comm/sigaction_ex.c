#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sig_func(int snum)
{
	fprintf(stderr, "Signal to exit received\n");
	exit(1);
}

int main(void)
{
	struct sigaction sig_act;
	
	// delete previously set signal mask
	sigemptyset( &sig_act.sa_mask );

	// function on received signal
	sig_act.sa_handler = &sig_func;

	// flags
	sig_act.sa_flags = 0;

	if( sigaction(SIGINT, &sig_act, NULL) == -1 ) {
		fprintf(stderr, "sigaction() error\n");
		return 1;
	}

	while(1);

	return 0;
}
