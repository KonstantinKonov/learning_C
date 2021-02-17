#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int hour, min, sec;
    scanf("%d:%d:%d", &hour, &min, &sec);
	int seconds = sec + min * 60 + hour * 3600;
	printf("Seconds: %d\n", seconds);

	scanf("%d", &seconds);
	hour = seconds / 3600;
	min = (seconds % 3600) / 60;
	sec = seconds % 60;
	printf("%d:%d:%d\n", hour, min, sec);

    return 0;
}