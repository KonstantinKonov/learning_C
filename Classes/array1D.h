#ifndef ARRAY1D_H
#define ARRAY1D_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

// Definition 1D array structure
typedef struct {
    double *data;
    uint64_t size;
} array1D;

// Callback function to compare two doubles
int comp_doubles(const void *, const void *);

// Fill in 1D array with random double values
void array1D_fill_in(array1D *, double, double );

// Print 1D array to provided stream (saving to file also)
void array1D_print(array1D *, FILE *);

// Sort 1D array with stdlib aqsort function
void array1D_qsort(array1D *);

// Save 1D array to binary file
// Binary file structure:
// 8 bytes - size
// 8 bytes * array length - data
int array1D_save_struct(array1D *, char *);

// Read 1D array from binary file
int array1D_read_struct(array1D *, char *);

// Init 1D array
void array1D_init(array1D *, uint64_t);

#endif