// 1 Week

// Include
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

// External Libraries
#include "gnuplot_i/gnuplot_i.h"

// Defines

// User defined variables

// User defined functions
double log_base(double arg, double base) 
{
    return log(arg)/log(base);
}

double entr(double *p, int n)
{
    double res = 0;
    while(n) {
        res += (*p) * log_base(1/(*p), 2);
        p++;
        n--;
    }
    return res;
}

double amount_of_bits(double *a, double *b, int n)
{
    double res = 0;
    while(n) {
        res += (*b) * (*a);
        a++;
        b++;
        n--;
    }
    return res;
}

// Main
int main(int argc, char **argv)
{

    printf("H(X) = %f\n", 0.6*log_base(5.0/3.0, 2) + 0.4*log_base(5.0/2.0, 2));

    printf("I = %f\n", log_base((100.0/29.0), 2));

    double arr[5] = {0.24, 0.35, 0.21, 0.13, 0.07}, bits[5] = {2, 2, 2, 3, 3};


    printf("Entropy: %f\n", entr(arr, 4));

    signed char var1 = 0xF0, var2 = 0x80;
    signed char var3 = var1 + var2;
    printf("0x%X\n", var3);

    printf("Amount of bits: %f\n", amount_of_bits(arr, bits, 5));

    return 0;
}