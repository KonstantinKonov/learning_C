#include <stdio.h>

#include "../lib/list_string_lib.h"

int main()
{
	struct string_list *strlst_1 = NULL;
	string_list_append(&strlst_1, "Hello");
	string_list_append(&strlst_1, "World!");

	string_list_print_all(strlst_1, " ", stdout);

	string_list_sort_by_lenght(strlst_1);

	char *str = string_list_pop(strlst_1);
	if(str != NULL) printf("%s\n", str);
	str = string_list_pop(strlst_1);
	if(str != NULL) printf("%s\n", str);
	str = string_list_pop(strlst_1);
	if(str != NULL) printf("%s\n", str);

	string_list_print_all(strlst_1, " ", stdout);

	return 0;
}
