//
//
//

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

// User's includes

// Defines
#define N 10

// Types

// Variables

// Functions

// Main
int main(int argc, char **argv)
{
	// allocate memory
	int *arr = (int *)malloc( (N/2) * sizeof(int) );
	for(uint32_t i = 0; i < N/2; i++) {
		arr[i] = i;
	}

	arr = (int *)realloc(arr, N * sizeof(int));

	for(uint32_t i = N/2; i < N; i++) {
		arr[i] = i;
	}

	for(uint32_t i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	} 
	printf("\n");
	
	return 0;
}