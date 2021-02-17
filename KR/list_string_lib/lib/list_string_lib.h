#ifndef H_LIST_STRING_LIB
#define H_LIST_STRING_LIB

int test_function(int n);

struct string_list {
	char **str;
	int n;
};

void string_list_append(struct string_list **, char *);
void string_list_print_all(struct string_list *, char *, FILE *);
char *string_list_pop(struct string_list *);
void string_list_sort_by_lenght(struct string_list *);

#endif
