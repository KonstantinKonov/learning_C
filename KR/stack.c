#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAXVAL 100

uint32_t ptr = 0;
double stack[MAXVAL] = {0};

void push(double val)
{
	if(ptr < MAXVAL)
		stack[ptr++] = val;
	else
		perror("Error: stack full\n");
}

double pop(void)
{
	if(ptr > 0)
		return stack[--ptr];
	else {
		perror("Error: stack empty\n");
		return 0;
	}
}

int main()
{
	char *str = NULL;
	char *operation = NULL;
	char *value = NULL;
	char delimiter[2] = " ";

	size_t n = 0;

	while(1) {
		printf("Operation: ");
		getline(&str, &n, stdin);
		str[strlen(str) - 1] = '\0';

		operation = strtok(str, delimiter);

		if( !strcmp(operation, "push") ) {
			value = strtok(NULL, delimiter);
			push(atof(value));
		}
		else if( !strcmp(operation, "pop") ) {
			printf("%lf\n", pop());
		}
		else if( !strcmp(operation, "info") ) {
			printf("Amout: %d\n", ptr);
			for(int i = 0; i < ptr; i++)
				printf("%lf\n", stack[i]);
		}
		else if( !strcmp(operation, "exit") ) {
			exit(0);
		}
	}

	return 0;
}
			

