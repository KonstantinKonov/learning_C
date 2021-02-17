#include <stdio.h>

struct key {
	char *name;
	int age;
};

struct key keytab[10] = {0};

int main()
{
	printf("size of keytab: %ld;\tsize of struct key: %ld;\tnumber of elements: %ld;\n", sizeof(keytab), \
			sizeof(struct key), sizeof(keytab) / sizeof(struct key));

	return 0;
}
