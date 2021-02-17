#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 20

typedef struct DataItem {
    int data;
    int key;
} DataItem;

int hash_code(int);

//struct DataItem *hash_search(struct DataItem **, int);

void hashtb_insert(struct DataItem **, int, int);

void hashtb_display(struct DataItem **);

#endif