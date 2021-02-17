//

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// User's defines

// User defined structures
struct {
	uint8_t bit_1: 1;
	uint8_t bit_2: 1;	
} status;


// User defined variables

// User defined functions

// Main
int main() 
{
	status.bit_1 = 1;
	status.bit_2 = 0;

	printf("The size of the structure 'status': %d byte(s)\n", sizeof(status));

}