/*

*/

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "../lib/FIFO.h"


// Defines

// Types

// Variables
fifo_t fifo;

// Function Declarations

// Function Definitions


// Main
int main(int argc, char **argv)
{
	fifo_init(&fifo);
	for(int i = 1; i < 2 * FIFO_SIZE + 1; i++) {
		char str[FIFO_STR_SIZE] = "";
		sprintf(str, "string %d", i);
		fifo_push(&fifo, str);
	}

	printf("n = %d, start = %d, end = %d, is full = %d\n", fifo.n, fifo.start, fifo.end, fifo_is_full(&fifo));

	char str[FIFO_STR_SIZE] = "";
	fifo_pull(&fifo, str);
	printf("%s\n", str);
	printf("%s\n", str);

	printf("n = %d, start = %d, end = %d, is full = %d\n", fifo.n, fifo.start, fifo.end, fifo_is_full(&fifo));

	fifo_init(&fifo);

	printf("n = %d, start = %d, end = %d, is full = %d\n", fifo.n, fifo.start, fifo.end, fifo_is_full(&fifo));

    return 0;
}