#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int number_of_entities = 0;

typedef struct str_struct {
    int number;
    char *str;
} str_struct;

void add_to_struct(str_struct **strct, char *str)
{
    *strct = (str_struct *) realloc( *strct, (number_of_entities + 1) * sizeof(str_struct) );
    (*strct)[number_of_entities].number = number_of_entities + 1;
    strcpy( (*strct)[number_of_entities].str, str );
    number_of_entities++;
}

int main(int argc, char **argv)
{
    str_struct *strct = NULL;

    add_to_struct(&strct, "Hello ");

    return 0;
}