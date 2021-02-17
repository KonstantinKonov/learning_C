#ifndef ARRAY1D_H
#define ARRAY1D_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

// Definition of 1D array structure
typedef struct {
    double *data;		// pointer to the array	
    uint64_t size;	    // size of the array
} array1D;

// Callback function to compare two doubles
int comp_doubles(const void *, const void *);

// Fill in 1D array with random double values
void array1D_fill_in_double(array1D *, double, double);

// Fill in 1D array with random integer values from min to max (included)
void array1D_fill_in_int(array1D *, int64_t, int64_t);

// Print 1D array to provided stream (saving to file also)
void array1D_print(array1D *, FILE *);

// Sort 1D array with stdlib aqsort function
void array1D_qsort(array1D *);

int64_t array1D_bsearch_index(array1D *, double);

double *array1D_bsearch(array1D *, double);

// Save 1D array to binary file
// Binary file structure:
// 8 bytes - size
// 8 bytes * array length - data
int array1D_save_struct(array1D *, char *);

// Read 1D array from binary file
int array1D_read_struct(array1D *, char *);

// Init 1D array
void array1D_init(array1D **, uint64_t);

#endif