#ifndef H_FIFO
#define H_FIFO

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define FIFO_SIZE 1000

typedef struct {
    double data[FIFO_SIZE];
    uint16_t n;
    uint16_t start;
    uint16_t end;
} fifo_t;

void fifo_push(fifo_t *, double);
double fifo_pull(fifo_t *);
bool fifo_is_empty(fifo_t *);
bool fifo_is_full(fifo_t *);
void fifo_init(fifo_t *);

#endif