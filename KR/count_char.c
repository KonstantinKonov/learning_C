#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv)
{
	uint32_t nc;

	for(nc = 0; getchar() != EOF; ++nc);

	printf("%d\n", nc);

	return 0;
}
