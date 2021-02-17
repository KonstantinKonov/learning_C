#ifndef H_FIFO
#define H_FIFO

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define FIFO_SIZE 1000
#define FIFO_STR_SIZE 20

typedef struct {
    char str[FIFO_SIZE][FIFO_STR_SIZE];
    uint16_t n;
    uint16_t start;
    uint16_t end;
} fifo_t;

void fifo_push(fifo_t *, char *);
void fifo_pull(fifo_t *, char s[FIFO_STR_SIZE]);
bool fifo_is_empty(fifo_t *);
bool fifo_is_full(fifo_t *);
void fifo_init(fifo_t *);

#endif