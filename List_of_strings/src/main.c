/*

*/

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Defines


// Types
typedef struct{
    char **l;
    uint32_t m;
} list_t;

 
// Functions
void list_init(list_t **list)
{
    (*list) = (list_t *)malloc(sizeof(list_t));
    (*list)->m = 0;
}

void list_append(list_t *list, char *s)
{
    list->l = (char **)realloc( list->l, ( (list->m) + 1 ) * sizeof(char *) );
    (list->l)[list->m] = (char *)malloc( ( strlen(s) + 1 ) * sizeof(char) );
    strcpy( (list->l)[list->m] , s);
    list->m++;
}
// Variables


// Main
int main(int argc, char **argv)
{
    list_t *list;
    list_init(&list);
    list_append(list, "Hello World");

    list_append(list, "How are you?");
    printf("%s\n", (list->l)[0]);

    printf("%s\n", (list->l)[1]);

    return 0;
}