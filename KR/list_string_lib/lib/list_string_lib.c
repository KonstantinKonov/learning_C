#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list_string_lib.h"

int compare_by_lenght(const void *a, const void *b)
{
	int len_a = strlen( (char *) a );
	int len_b = strlen( (char *) b );
	if( len_a > len_b )
		return -1;
	else if( len_a < len_b )
		return 1;
	else
		return 0;
}

void string_list_append(struct string_list **strlst, char *str)
{
	if( *strlst == NULL ) {
		*strlst = (struct string_list*)malloc(sizeof(struct string_list));
		(*strlst)->n = 0;
	}

	int n = ++(*strlst)->n;
	(*strlst)->str = (char **)realloc((*strlst)->str, n * sizeof(char *) );

	int len = strlen(str);
	(*strlst)->str[n - 1] = (char *)malloc( (len + 1) * sizeof(char) );
	strcpy((*strlst)->str[n - 1], str);
}

void string_list_print_all(struct string_list *strlst, char *delimiter, FILE *stream)
{
	if(strlst == NULL)
		return;
	int n = strlst->n;
	for(int i = 0; i < n; i++)
		printf("%s%s", (strlst->str)[i], delimiter);
	printf("\n");
}

char *string_list_pop(struct string_list *strlst)
{
	if(strlst == NULL)
		return NULL;
	if(strlst->n == 0)
		return NULL;
	
	int n = strlst->n;
	int len = strlen(strlst->str[n - 1]);
	char *str = (char *) malloc( len * sizeof(char) );
	strcpy(str, strlst->str[n - 1]);

	strlst->n--;

	return str;
}

void string_list_sort_by_lenght(struct string_list *strlst)
{
	size_t n = strlst->n;
	qsort(strlst->str, n, sizeof(int), &compare_by_lenght);
}

	

		

