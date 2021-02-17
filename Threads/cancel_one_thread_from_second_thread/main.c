#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_fun1(void *vargp)
{
	int i = 0;
	while(1) {
		printf("thread 1: %d\n", i);
		i++;
		usleep(100000);
	}
}

void *thread_fun2(void *vargp)
{
	int i = 0;
	while(1) {
		printf("thread 2: %d\n", i);
		i++;
		sleep(1);

		if(i == 10) {
			pthread_cancel( *((pthread_t*)vargp) );
			printf("%s\n", "thread 1 terminated");
		}

	}
}

int main(int argc, char **argv)
{
	pthread_t thread_1;
	pthread_create(&thread_1, NULL, thread_fun1, NULL);
	pthread_t thread_2;
	pthread_create(&thread_2, NULL, thread_fun2, (void*)&thread_1);
	//pthread_join(thread_id, NULL);

	while(1) {
		printf("%s\n", "main thread");
		sleep(5);
	}

	return 0;
}
