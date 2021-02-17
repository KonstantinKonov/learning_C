#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "choose_serial.h"

int main(int argv, char **argc)
{
    char selected[100];
    choose_serial(selected);
    printf("%s\n", selected);
}