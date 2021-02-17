#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int x;
    int y;
    int z;
} point;

typedef struct {
    int x;
    int y;
    int z;
} vector;

vector vector_mult(vector a, vector b)
{
    vector vect;
    vect.x = a.z * b.y - a.y * b.z; 
    vect.y = a.x * b.z - a.z * b.x;
    vect.z = a.y * b.x - a.x * b.y;

    return vect;
}

vector make_vector_from_points(point p1, point p2)
{
    vector vect;
    vect.x = p2.x - p1.x;
    vect.y = p2.y - p1.y;
    vect.z = p2.z - p1.z;

    return vect;
}

double vector_length(vector a)
{
    return sqrt( pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2) );
}

int main(int argc, char **argv)
{
    point a, b, c;
    printf("Enter cordinates of point A:\n");
    scanf("%d %d %d", &a.x, &a.y, &a.z);

    printf("Enter cordinates of point B:\n");
    scanf("%d %d %d", &b.x, &b.y, &b.z);

    printf("Enter cordinates of point C:\n");
    scanf("%d %d %d", &c.x, &c.y, &c.z);

    vector vect_a = make_vector_from_points(a, b);
    vector vect_b = make_vector_from_points(a, c);

    vector vect_c = vector_mult(vect_a, vect_b);

    printf("Vector c length: %lf\n", vector_length(vect_c));

    return 0;
}