#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "lib/array1D.h"

// user's defines

// user defined types

// user defined variables

// user defined functions


// main
int main(int argc, char **argv)
{
	array1D *arr;
	array1D_init(&arr, 1000);

	array1D_fill_in_int(arr, -100, 100);
	array1D_qsort(arr);
	array1D_print(arr, stdout);
	printf("index of the element 3: %ld\n", array1D_bsearch_index(arr, 3));

	return 0;
}

int main(int argc, char **argv) 
{
	
	
	return 0;
}