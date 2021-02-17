#include "array1D.h"

// Callback function to compare two doubles
int comp_doubles(const void *n1, const void *n2)
{
    const double *a = n1;
    const double *b = n2;

    if(*a > *b)
        return 1;
    else if(*a < *b)
        return -1;
    else if(*a == *b)
        return 0;
    
    return 0;
}

// Fill in 1D array with random double values
void array1D_fill_in_double(array1D *self, double min, double max)
{
    srand(time(0));
    for(uint64_t i = 0; i < self->size; i++)
        self->data[i] = min + (max - min) * ((double)rand()/RAND_MAX);
}

// Fill in 1D array with random integer values
void array1D_fill_in_int(array1D *self, int64_t min, int64_t max)
{
    srand(time(0));
    for(uint64_t i = 0; i < self->size; i++)
        self->data[i] = min + round( (max - min) * ((double)rand()/RAND_MAX) );
}

// Print 1D array to provided stream (saving to file also)
void array1D_print(array1D *self, FILE *stream)
{
    for(uint64_t i = 0; i < self->size; i++)
        fprintf(stream, "%.4f\n", self->data[i]);
}

// Sort 1D array with stdlib aqsort function
void array1D_qsort(array1D *self)
{
    qsort(self->data, self->size, sizeof(double), comp_doubles);
}

double *array1D_bsearch(array1D *self, double val)
{
    double *low = self->data;
    double *high = self->data + self->size - 1;
    double *mid = NULL;

    while(*low <= *high) {
        mid = low + ((high - low)/2);
        if(val < *mid)
            high = mid - 1;
        else if(val > *mid) 
            low = mid + 1;
        else
            return mid;
    }

    return NULL;

    //return bsearch(&val, self->data, self->size, sizeof(double), comp_doubles);
}

// Save 1D array to binary file
// Binary file structure:
// 8 bytes - size
// 8 bytes * array length - data
int array1D_save_struct(array1D *self, char *name)
{
    FILE *fp = fopen(name, "wb");
    if(fp != NULL) {
        fwrite(&(self->size), sizeof(uint64_t), 1, fp);
        fwrite(self->data, sizeof(double), self->size, fp);
        fclose(fp);
        return 0;
    }
    return 1;
}

// Read 1D array from binary file
int array1D_read_struct(array1D *self, char *name)
{
    FILE *fp = fopen(name, "rb");
    if(fp != NULL) {
        //uint64_t *size = (uint64_t *) calloc(1, sizeof(uint64_t));
        fread(&(self->size), sizeof(int64_t), 1, fp);
        
        self->data = (double *) calloc(self->size, sizeof(double));
        //self->size = *size;

        fread(self->data, sizeof(double), self->size, fp);
        fclose(fp);
        return 0;
    }
    return 1;
}

// Init 1D array
void array1D_init(array1D **self, uint64_t size)
{
    //self->size = (uint64_t) malloc(sizeof(uint64_t));
    *self = (array1D *) malloc(sizeof(array1D));
    (*self)->size = size;
    //(*self)->size = (uint64_t) malloc(sizeof(uint64_t));
    (*self)->data = (double *) calloc(size, sizeof(double));
}