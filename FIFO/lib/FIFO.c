#include "FIFO.h"

void fifo_init(fifo_t *fifo)
{
    fifo->start = 0;
    fifo->end = 0;
    fifo->n = 0;

    for(uint16_t i = 0; i < FIFO_SIZE; i++)
        fifo->data[i] = 0;
}

bool fifo_is_full(fifo_t *fifo)
{
	return !(fifo->n < FIFO_SIZE);
}

bool fifo_is_empty(fifo_t *fifo)
{
	return !(fifo->n);
}

void fifo_push(fifo_t *fifo, double val)
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
	
    fifo->data[fifo->end] = val;
}

double fifo_pull(fifo_t *fifo)
{
	if(fifo->n == 0) 
		return 0;
	double temp = fifo->data[fifo->start];
	fifo->start++;
	fifo->start %= FIFO_SIZE;
	fifo->n--;
	
	return temp;
}