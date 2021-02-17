#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *fun(void *vargp)
{
	unsigned long i = 0;

	while(1) {
		printf("%ld\n", i);
		i++;
		sleep(1);
	}
}


int main()
{
	pthread_t my_thread;
	pthread_create(&my_thread, NULL, fun, NULL);
	pthread_join(my_thread, NULL);

	while(1);

	return 0;
}
