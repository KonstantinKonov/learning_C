#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/time.h>
#include <math.h>

#define N 100
#define M 2

void set_rand()
{
	struct timeval t;
	gettimeofday(&t, NULL);
	uint64_t us = t.tv_sec * 10E6 + t.tv_usec;
	srand(us);
}

double mean(double *arr, int n)
{
	double sum = 0;
	for(int i = 0; i < n; i++)
		sum += arr[i];
	return sum/n;
}

double standard_deviation(double *arr, int n)
{
	double m = mean(arr, n);
	double sum = 0;
	for(int i = 0; i < n; i++)
		sum += pow( (arr[i] - m), 2 );
	return sqrt(sum/n);
}

void draw1D(double *arr, int n)
{
	FILE *gp = popen("gnuplot -persist", "w");

	if(gp != NULL) {
		fprintf(gp, "plot '-' with boxes\n");
		for(int i = 0; i < n; i++)
			fprintf(gp, "%lf\n", arr[i]);
		fprintf(gp, "%s\n", "e");
		pclose(gp);
	}
}

void export1D(char *str, double *arr, int n)
{
	FILE *fp = fopen(str, "w");
	if(fp != NULL)  {
		for(int i = 0; i < n; i++)
			fprintf(fp, "%lf\n", arr[i]);
	fclose(fp);
	}
}

void export2D(char *str, double arr[N][M], int n, int m)
{
	FILE *fp = fopen(str, "w");
	if(fp != NULL)  {
		for(int i = 0; i < n; i++)
			fprintf(fp, "%lf\t%lf\n", arr[i][0], arr[i][1]);
	fclose(fp);
	}
}

int main(int argc, char **argv)
{
	set_rand();

	double arr[N];
	for(int i = 0; i < N; i++)
		arr[i] = (double)rand()/RAND_MAX;
	export1D("data.dat", arr, N);

	draw1D(arr, N);

	printf("mean: %lf\n", mean(arr, N));
	printf("standard deviation: %lf\n", standard_deviation(arr, N));

	double arr2D[N][M];
	for(int i = 0; i < N; i++) {
		arr2D[i][0] = i;
		arr2D[i][1] = (double)rand()/RAND_MAX;
	}
	export2D("data2D.dat", arr2D, N, M);

	return 0;
}
