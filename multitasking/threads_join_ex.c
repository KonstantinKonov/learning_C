#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define COUNT_A 5
#define COUNT_B 10

void *p_fun(void *arg)
{
	for(int i = 0; i < *(int *)arg; i++) {
		printf("Thread reporting in %d\n", i);
		system("sleep 1");
	}

	return NULL;
}

int main()
{
	pthread_t p_id;
	int n = COUNT_B;

	pthread_create(&p_id, NULL, &p_fun, &n);

	char str[100];
	sprintf(str, "sleep %d", COUNT_A);
	system(str);

	pthread_join(p_id, NULL);

	return 0;
}
