#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define STR_SIZE 256

int main()
{
	// Different ways to declare a string
	char str1[] = "This is a string\n";
	char *str2 = (char *)malloc(STR_SIZE * 1);
	char str3[STR_SIZE];

	// Copy string
	memcpy(str2, str1, strlen(str1) + 1);
	// or
	strcpy(str3, str1);

	// Compare strings
	if(!strcmp(str1, str2)) {
		printf("Strings str1 and str2 are the same!\n");
	}
	else {
		printf("Strings str1 and str2 are different!\n");
	}

	// Concatenate two strings
	strcat(str2, str1);

	// Search a char in string
	char *ptr = strchr(str1, 's');
	printf("%s", ptr);

	// Search substring
	char *ptr2 = strstr(str1, "is");
	printf("%s", ptr2);

	
	return 0;
}