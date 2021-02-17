#include <stdio.h>
#include <stdlib.h>

#include "../lib/fifo.h"

int main()
{
	int i = 0;
	int j = 0;

	for(; i < 10; i++)
		fifo_put('a' + i);
	fifo_print();
	for(; j < 5; j++)
		fifo_get();
	fifo_print();
	for(i = 0; i < 8; i++)
		fifo_put('0' + i);
	fifo_print();

	return 0;
}
