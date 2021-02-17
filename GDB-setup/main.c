// Quick Sort with debugging
#define IS_DEBUGGING 0

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

#define ARR_SIZE 100

void array_print(int *arr, int n)
{
    for(int i = 0; i < n; i++) {
        printf("%02d ", arr[i]);
    }
    printf("\n");
}

void array_init(int **arr, int n)
{
    *arr = (int *)malloc(n * sizeof(int));

    struct timeval tv;
    gettimeofday(&tv, NULL);
    long ms = (long)(tv.tv_sec)*1000 + (long)(tv.tv_usec)/1000;

    srand(ms);

    for(int i = 0; i < n; i++) {
        *(*arr + i) = rand()%100;
    }

    array_print(*arr, n);
}

int partition(int *arr, int l, int r)
{
    int p = r;
    r--;
    while(1) {
        while( arr[l] <= arr[p] && l < p) {
            l++;
        }
        while( arr[r] >= arr[p] && r > 0) {
            r--;
        }
        if(l < r) {
            int temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
        }
        else break;
    }
    
    int temp = arr[l];
    arr[l] = arr[p];
    arr[p] = temp;

    if(IS_DEBUGGING) array_print(arr, ARR_SIZE);

    return l;
}

void QuickSort(int *arr, int l, int r)
{
    if( r <= l ) 
        return;
    
    int pivot = partition(arr, l, r);
    QuickSort(arr, l, pivot - 1);
    QuickSort(arr, pivot + 1, r);
}

int main(int argc, char ** argv)
{
    while(1) {
        int *arr;
        array_init(&arr, ARR_SIZE);

        QuickSort(arr, 0, ARR_SIZE - 1);

        array_print(arr, ARR_SIZE);
        
        int temp = arr[0];
        for(uint32_t i = 1; i < ARR_SIZE; i++) {
            if(arr[i] < temp) {
                printf("%s\n", "failed");
                exit(1);
            }
            temp = arr[i];
        }

        free(arr);

        clock_t ticks = clock();
        while( 1000 * (clock() - ticks) / CLOCKS_PER_SEC < 500) {};
    }


    return 0;
}