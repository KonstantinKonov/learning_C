#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 10

void reverse_string(char *str)
{
    int len = strlen(str);
    for(int i = 0; i < len/2; i++) {
        char c = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = c;
    }
}

int main(int argc, char **argv)
{
    char c;
    int size = INIT_SIZE;
    int n = 0;
    char *str = (char *) malloc(size * sizeof(char));

    while( (c = getchar()) != EOF )
        if( c != '\n' ) {
            if( size < n + 2 ) {
                size *= 2;
                str = realloc( str, size * sizeof(char) );
            }
            str[n] = c;
            n++;
        }

    str[n] = '\0';

    printf("%s\n", str);
    reverse_string(str);
    printf("%s\n", str);

    return 0;
}