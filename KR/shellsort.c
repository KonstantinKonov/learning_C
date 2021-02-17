#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

void rand_init(void)
{
	time_t t;
	srand((unsigned int) time(&t));
}

int *get_rand_arr(int n)
{
	int *arr = (int *) malloc( n * sizeof(int) );
	for(int i = 0; i < n; i++)
		arr[i] = rand()%200 - 100;
	return arr;
}

void print_arr(int *arr, int n, char separator)
{
	for(int i = 0; i < n; i++)
		printf("%d%c", arr[i], separator);
	printf("\n");
}

void change(int *arr, int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void shellsort(int *arr, int n)
{
	int gap, i, j;

	for( gap = n/2; gap > 0; gap /= 2 )
		for( i = gap; i < n; i++ )
			for( j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap ) 
				change(arr, j, j + gap);
}

int main()
{
	rand_init();

	int *arr = get_rand_arr(N);
	print_arr(arr, N, ' ');

	shellsort(arr, N);

	print_arr(arr, N, ' ');

	free(arr);
	return 0;
}
