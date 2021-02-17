#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
	char str[] = "Hello\n World!\n";
	int i = 0;

	free(NULL);

	while(str[i] != '\0')  {
		putchar(str[i++]);
		sleep(1);
	}

	return 0;
}
