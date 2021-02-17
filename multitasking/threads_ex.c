#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <pthread.h>

struct times_delay {
	int times;
	int delay;
};

void *thread_function(void *args)
{
	struct times_delay n = *(struct times_delay *)args;

	for(int i = 0; i < n.times; i++) {
		printf("Thread function: %d\n", i);
		char str[100];
		sprintf(str, "sleep %d", n.delay);
		system(str);
	}

	return NULL;
}

int main()
{
	pthread_t p_id;

	struct times_delay n;
	n.times = 5;
	n.delay = 1;

	pthread_create(&p_id, NULL, &thread_function, &n);
	
	system("sleep 10");

	return 0;
}
