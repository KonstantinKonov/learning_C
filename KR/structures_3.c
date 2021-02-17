#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 10
#define M 2

struct point {
	double x;
	double y;
};

// Array of structures
struct point arr_1[N];

// Array of structures
struct point *arr_2;

// 2D array of structures
struct point **arr_3;

// Random init
void random_init()
{
	time_t t;
	srand((unsigned) t);
}

// Fill in array with random values
void fill_in_array_rand(struct point arr[], int n)
{
	for(int i = 0; i < n; i++) {
		arr[i].x = rand() % 100 / 10.0;
		arr[i].y = rand() % 100 / 10.0;
	}

	/*
	 * for(int i = 0; i < n; i++) {
	 * (arr + i)->x = rand() % 100 / 10.0;
	 * (arr + i)->y = rand() % 100 / 10.0;
	 * }
	 * */

	for(int i = 0; i < n; i++)
		printf("{%.1lf %.1lf}\t", (arr + i)->x, (arr + i)->y);
	printf("\n");
}

// Fill in array with random values, with allocation
void fill_in_array_rand_2(struct point *arr, int n)
{
	arr = (struct point *) malloc(n * sizeof(struct point));
	for(int i = 0; i < n; i++) {
		(arr + i)->x = rand() % 100 / 10.0;
		(arr + i)->y = rand() % 100 / 10.0;
	}
	for(int i = 0; i < n; i++)
		printf("{%.1lf %.1lf}\t", (arr + i)->x, (arr + i)->y);
	printf("\n");
}

// Fill in 2D array with random values, with allocation
void fill_in_array_rand_3(struct point **arr, int n, int m)
{
	arr = (struct point **) malloc(n * sizeof(struct point*));
	for(int i = 0; i < n; i++)
		arr[i] = (struct point *) malloc(m * sizeof(struct point));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			arr[i][j].x = rand() % 100 / 10.0;
			arr[i][j].y = rand() % 100 / 10.0;
		}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) 
			printf("{%.1lf %.1lf}\t", arr[i][j].x, arr[i][j].y);
		printf("\n");
	}
}

// Fill in 2D array with random values, with allocation, pointer arithmetics
void fill_in_array_rand_3_pointer_arithmetics(struct point **arr, int n, int m)
{
	arr = (struct point **) malloc(n * sizeof(struct point*));
	for(int i = 0; i < n; i++)
		*(arr + i) = (struct point *) malloc(m * sizeof(struct point));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			(*(arr + i) + j)->x = rand() % 100 / 10.0;
			(*(arr + i) + j)->y = rand() % 100 / 10.0;
		}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) 
			printf("{%.1lf %.1lf}\t", (*(arr + i) + j)->x, (*(arr + i) + j)->y);
		printf("\n");
	}
}

void main()
{
	random_init();
	//fill_in_array_rand(arr_1, N);
	//fill_in_array_rand_2(arr_2, N);
	//free(arr_2);
	//fill_in_array_rand_3(arr_3, N, M);
	//free(arr_3);
	fill_in_array_rand_3_pointer_arithmetics(arr_3, N, M);
	free(arr_3);
}
