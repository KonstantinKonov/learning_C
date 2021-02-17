#include "FIFO.h"

void fifo_init(fifo_t *fifo)
{
    fifo->start = 0;
    fifo->end = 0;
    fifo->n = 0;

    for(uint16_t i = 0; i < FIFO_SIZE; i++)
        strcpy( (fifo->str)[i], "");
}

bool fifo_is_full(fifo_t *fifo)
{
	return !(fifo->n < FIFO_SIZE);
}

bool fifo_is_empty(fifo_t *fifo)
{
	return !(fifo->n);
}

void fifo_push(fifo_t *fifo, char *s)
{
    // Is fifo full
    if(fifo_is_full(fifo)) {
        fifo->end++;
        fifo->end %= FIFO_SIZE;
        fifo->start++;
        fifo->start %= FIFO_SIZE;
    }
    else if(fifo_is_empty(fifo)) {
		fifo->n++;
    }
	else {
		fifo->end++;
        fifo->end %= FIFO_SIZE;
		fifo->n++;
	}
	
    strcpy( (fifo->str)[fifo->end], s );
}

void fifo_pull(fifo_t *fifo, char s[FIFO_STR_SIZE])
{
	if(fifo->n == 0) 
		return;
    strcpy( s, (fifo->str)[fifo->start] );
	fifo->start++;
	fifo->start %= FIFO_SIZE;
	fifo->n--;
}