#include <stdio.h>

#include "fifo.h"

int first = 0;
int n = 0;

void fifo_put(char c)
{
	if(n == 0) {
		n++;
		fifo_arr[ (first + n - 1) % FIFO_SIZE ] = c;
	}
	else if(n < FIFO_SIZE) {
		n++;
		fifo_arr[ (first + n - 1) % FIFO_SIZE ] = c;
	}
	else {
		fifo_arr[ first ] = c;
		first = (first + 1) % FIFO_SIZE;
	}
}

char fifo_get()
{
	char c = fifo_arr[ (first + n) % FIFO_SIZE ];
	n--;
	return c;
}

void fifo_print()
{
	for(int i = 0; i < n; i++) 
		printf("%c ", fifo_arr[ (first + i) % FIFO_SIZE ]);
	printf("\n");
}
