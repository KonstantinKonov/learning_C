#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "array1D.h"

// Main
int main(int argc, char **argv)
{
    array1D *arr = (array1D *) malloc(sizeof(array1D));
    array1D_init(arr, 1000);

    array1D_fill_in(arr, -1000, 1000);
    array1D_qsort(arr);
    array1D_save_struct(arr, "data.1Darray");
    
    array1D *arr_new  = (array1D *) malloc(sizeof(array1D));
    array1D_read_struct(arr_new, "data.1Darray");

    FILE *fp = fopen("data.dat", "w");
    if(fp != NULL) {
        array1D_print(arr, fp);
        fclose(fp);
    }
    array1D_print(arr_new, stdout);

    return 0;
}