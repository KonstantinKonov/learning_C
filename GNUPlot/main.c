#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

#define N 10
#define FREQ 10
#define NOISE 0.25

void rand_init()
{
	struct timeval t;
	long ms = t.tv_sec * 1000 + t.tv_usec / 1000;
	srand(ms);
}

int main()
{
	double data_y[N], data_x[N];

	remove("sin.dat");
	double x = 0;
	while(1) {
	FILE *fp = fopen("sin.dat", "a");
	for(int i = 0; i < N; i++) {
		data_x[i] = x * 0.001;
		data_y[i] = sin( (2 * M_PI * FREQ) * x * 0.001 ) + ( ((double)rand()/RAND_MAX) - 0.5 ) * NOISE; 
		fprintf(fp, "%.3lf\t%.3lf\n", data_x[i], data_y[i]);
		x++;
	}
	fclose(fp);

	sleep(1);
	}

}
