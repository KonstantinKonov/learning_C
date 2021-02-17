#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// "point" - structue tag
struct point {
	int x;
	int y;
};

// "p1" etc. - variables
struct point_new {
	int x;
	int y;
} p1 = {12, 34}, p2, p3;

struct point pt1 = {1, 2};

int main()
{
	printf("%d %d\n", p1.x, p1.y);

	return 0;
}
