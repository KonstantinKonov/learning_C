#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 1000
#define MAXSYMBOLS 1000

struct point {
	double x;
	double y;
};

struct rectangle {
	struct point p1;
	struct point p2;
};
	
struct rectangle rect_1 = { {-1, -2}, {3, 4} };

struct rectangle make_rect(void)
{
	char *str;
	size_t n = 0;
	const char delimiter[2] = " ";
	int nlines = 0;
	char str_arr[MAXSYMBOLS][MAXLINES];

	// read rectangle's corners
	int len = getline(&str, &n, stdin);
	str[len -1] = '\0';
	char *token = strtok(str, delimiter);
	nlines++;
	strcpy(str_arr[nlines - 1], token);

	while( token != NULL ) {
		token = strtok(NULL, delimiter);
		if( token != NULL ) {
			nlines++;
			strcpy(str_arr[nlines - 1], token);
		}
	}

	struct rectangle rect;
	rect.p1.x = atof(str_arr[0]);
	rect.p1.y = atof(str_arr[1]);
	rect.p2.x = atof(str_arr[2]);
	rect.p2.y = atof(str_arr[3]);

	return rect;
}

void print_rect(struct rectangle r)
{
	printf("{ {%lf, %lf}, {%lf, %lf} }\n", r.p1.x, r.p1.y, r.p2.x, r.p2.y);
}

int main()
{
	print_rect(make_rect());

	return 0;
}
