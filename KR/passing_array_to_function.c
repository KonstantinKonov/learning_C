#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define N 200

void random_init()
{
	time_t t;
	srand((unsigned) t);
}

int compare(const void *a, const void *b)
{
	if( *(double *)a < *(double *)b)
		return -1;
	else if( *(double *)a > *(double *)b)
		return 1;
	else 
		return 0;
}

double *get_random_array(unsigned int n)
{
	double *arr = (double *) malloc(n * sizeof(double));

	for(unsigned int i = 0; i < n; i++)
		arr[i] = (rand() % 20000) / 100.0 - 100;

	qsort(arr, n, sizeof(*arr), &compare);

	return arr;
}

void print_arr(double *arr, unsigned int n, char *delimiter)
{
	if(delimiter == NULL)
		delimiter = " ";
	for(int i = 0; i < n; i++)
		printf("%.2lf%s", *(arr + i), delimiter);
	printf("\n");
}

void fun1(double arr[N])
{

}

void fun2(double arr[], unsigned int n)
{
	for( unsigned int i = 0; i < n; i++)
		if( arr[i] <= 10 && arr[i] >= -10)
			printf("%3.2lf ", arr[i]);
	printf("\n");
}

int main(int argc, char **argv)
{
	random_init();

	double *arr = get_random_array(N);

	print_arr(arr, N, NULL); 

	fun1(arr);
	fun2(arr, N);

	return 0;
}
