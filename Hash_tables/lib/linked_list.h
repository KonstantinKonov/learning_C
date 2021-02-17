#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "array1D.h"

typedef struct node {
    double val;
    struct node *next;
} node_t;

int list_init(node_t **, double);
node_t *list_last(node_t *);
void list_append(node_t *, double);
void list_print(node_t *, FILE *);
uint32_t list_count(node_t *);
node_t *list_moveto(node_t *, uint32_t);
void list_insert_element(node_t *, uint32_t, double);
void list_push(node_t **, double);
double list_pop(node_t **);
void list_insert_list(node_t **, node_t *, uint32_t);
void list_remove(node_t **, uint32_t);
void list_from_array1D(node_t **, array1D *);

#endif