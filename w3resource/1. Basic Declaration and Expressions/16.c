#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 8

int banknotes[N] = {1, 5, 10, 20, 50, 100, 500, 1000};
int amount_of_banknotes[N] = {0};

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);

    int i = N - 1;
    while( i >= 0 ) {
        amount_of_banknotes[i] = n / banknotes[i];
        n %= banknotes[i];
        i--;
    }

    for(int j = 0; j < N; j++) {
        printf("%d: %d\n", banknotes[j], amount_of_banknotes[j]);
    }
    

    return 0;
}