#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
	char str[] = "Hello\nWorld!\n";
	int i = 0;

	while(str[i] != '\0')  {
		putchar(str[i++]);
		sleep(1);
	}

	return 0;
}
