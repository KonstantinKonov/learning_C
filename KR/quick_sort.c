#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define N 200
#define MIN -100
#define MAX 100

double *arr_random_create(uint32_t n, double min, double max)
{
	double *arr = (double *) malloc(n * sizeof(double));
	for(uint32_t i = 0; i < n; i++)
		arr[i] = (rand() % 20000)/100.0 - 100;
	return arr;
}

void arr_print(double *arr, uint32_t n, char *delimiter)
{
	for(uint32_t i = 0; i < n; i++)
		printf("%.2lf%s", arr[i], delimiter);
	printf("\n");
}

void swap(double *arr, uint32_t a, uint32_t b)
{
	double temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void quick_sort(double *arr, uint32_t left, uint32_t right)
{
	uint32_t i, last;

	if(left >= right)
			return;
	swap(arr, left, (left+right)/2);
	last = left;
	for( i = left + 1; i <= right; i++ )
			if( arr[i] < arr[left] )
					swap( arr, ++last, i );
	swap(arr, left, last);
	quick_sort(arr, left, last);
	quick_sort(arr, last + 1, right);
}

int main()
{
	time_t t;
	srand((unsigned) time(&t));

	double *arr = arr_random_create(N, MIN, MAX);

	quick_sort(arr, 0, N - 1);

	arr_print(arr, N, " ");

	return 0;
}
