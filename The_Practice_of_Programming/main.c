#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include "lib/array1D.h"
#include "lib/linked_list.h"
#include "lib/btree.h"
#include "lib/hash.h"


int main(int argc, char **argv)
{
    struct DataItem *hashArray = (struct DataItem *) malloc(HASH_SIZE*sizeof(struct DataItem));
    hashtb_insert(&hashArray, 1, 1);
    hashtb_insert(&hashArray, 2, 2);

    hashtb_display(&hashArray);


    /*
    array1D *arr = NULL;

    array1D_init(&arr, 1000);

    array1D_fill_in_int(arr, -100, 100);

    array1D_qsort(arr);

    array1D_print(arr, stdout);

    double *val_ptr;
    if( (val_ptr = array1D_bsearch(arr, 95)) != NULL) {
        printf("index: %ld, value: %.4lf\n", (val_ptr - arr->data), *val_ptr);  // index = pointer_to_element - pointer_to_beginnig_of_the_array
    }
    else
        printf("element not found\n");
    */
    /*
    node_t *list = NULL, *list_new = NULL;   // NULL pointer что происходит при инициализации NULL?
    if(list_init(&list, 1.0) != 0) {
        perror("Can't allocate memory for list\n");
        return 0;
    }

    list_init(&list_new, 99);

    double v = 2.0;
    while(v < 5.0) {
        list_append(list, v);
        v++;
    }

    v = 98.0;
    while(v > 89.0) {
        list_append(list_new, v);
        v--;
    }

    list_insert_element(list, 2, 2.5);
    list_push(&list, 0.0);

    list_print(list, stdout);
    list_count(list);

    printf("Elements in list: %d\n", list_count(list));

    printf("Popped element: %.2lf\n", list_pop(&list));

    array1D *arr = NULL;
    node_t *list2 = NULL;
    array1D_init(&arr, 10);
    array1D_fill_in(arr, 0, 100.0);
    array1D_print(arr, stdout);

    list_from_array1D(&list2, arr);

    printf("___________________________\n");

    list_print(list2, stdout);

    printf("Number of elements: %d\n", list_count(list2));

    list_insert_list(&list, list_new, list_count(list));

    list_print(list, stdout);

    list_remove(&list, 10);

    list_print(list, stdout);
    */

    return 0;
}