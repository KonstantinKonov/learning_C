/*

*/

// Includes
#include <stdio.h>
#include <stdlib.h>

// Defines

// Variables

// Functions
int factorial(int x)
{
    int res = 1;
    for(int i = 1; i <= x; i++) {
       res *= i; 
    }

    return res;
}

double add(double x, double y)
{
    return x + y;
}

double sub(double x, double y)
{
    return x - y;
}

double mult(double x, double y)
{
    return x * y;
}

double divide(double x, double y)
{
    if(y != 0)
        return x/y;
}

double action(double x, double y, double (*f)(double, double))
{
    return (*f)(x, y);
}

// Main
int main(int argc, char **argv)
{
    // Pointer to a function
    int (*fact_ptr)(int) = factorial;

    printf("fact of %d: %d\n", 10, (*fact_ptr)(10));

    // Array of pointer to the functions
    double (*func_arr[])(double, double) = {add, sub, mult, divide};

    double x = 10, y = 5;
    printf("x = %lf, y = %lf, add: %lf, sub: %lf, mult: %lf, div: %lf\n", x, y, (*func_arr[0])(x, y), (*func_arr[1])(x, y), (*func_arr[2])(x, y), (*func_arr[3])(x, y));
    
    // Passing pointer of a function as an argument to a function
    printf("action = %lf\n", action(x, y, func_arr[3]));


    return 0;
}
