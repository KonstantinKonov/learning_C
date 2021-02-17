#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 200
#define N_MIN -100
#define N_MAX 100

int compare_int(const void *a, const void *b)
{
	return ( *(int *)a - *(int *)b );
}

int *rand_array(int n, int min, int max)
{
	int *arr = (int*) malloc(n * sizeof(int));

	for(int i = 0; i < n; i++)
		arr[i] = rand() % 200 - 100;
	return arr;
}

void print_array(int *arr, int n, char sep)
{
	for(int i = 0; i < n; i++)
		printf("%3d%c", arr[i], sep);
	printf("\n");
}

void sort_array(int *arr, int n)
{
	qsort(arr, n, sizeof(int), compare_int);
}

void free_array(int *arr)
{
	free(arr);
}

int binsearch(int *arr, int n, int search)
{
	int low = 0;
	int high = n - 1;
	int mid;

	while(low <= high) {
		mid = low + (high - low)/2;
		if(arr[mid] == search)
			return mid;
		if(search < arr[mid]) 
			high = mid - 1;
		else if(search > arr[mid])
			low = mid + 1;
	}

	return -1;
}

int main()
{
	time_t t;
	srand((unsigned) time(&t));

	int *arr = rand_array(N, N_MIN, N_MAX);
	print_array(arr, N, ' ');

	sort_array(arr, N);

	print_array(arr, N, ' ');

	int index;
	int search = 10;
	if( (index = binsearch(arr, N, search)) != -1 )
		printf("%d: %d\n", index, arr[index]);

	free_array(arr);
	return 0;
}
