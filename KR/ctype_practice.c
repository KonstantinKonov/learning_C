#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define STR_SIZE 10

char *boolean(int n)
{
	char *ret_val = malloc(6 * sizeof(char));
	if(n != 0)
		strcpy(ret_val, "True");
	else
		strcpy(ret_val, "False");
		
	return ret_val;
}

int purge_stream(FILE *stream)
{
	int c, i;
	while( (c = getc(stream)) != '\n' && c != EOF )
		i++;

	return i;
}

int main()
{
	char c; // Don't use int here
	printf("Enter character: ");
	//scanf("%c", &c); // Don't use int here neither
	c = getchar();
	
	printf("Symbol: %c, ASCII value: %d, Is alphanumeric: %d\n", c, c, isalnum(c));
	printf("Is alphanumeric(boolean): %s\n", boolean(isalnum(c)));

	printf("Is isalpha: %d, %s\n", isalpha(c), boolean(isalpha(c)));

	printf("Is control character: %d, %s\n", iscntrl(c), boolean(iscntrl(c)));

	printf("Is decimal: %d, %s\n", isdigit(c), boolean(isdigit(c)));

	printf("Is graphical representation using locale: %d, %s\n", isgraph(c), boolean(isgraph(c)));

	printf("Is lower: %d, %s\n", islower(c), boolean(islower(c)));

	printf("Is printable: %d, %s\n", isprint(c), boolean(isprint(c)));

	printf("Is punctuation: %d, %s\n", ispunct(c), boolean(ispunct(c)));

	printf("Is space: %d, %s\n", isspace(c), boolean(isspace(c)));

	printf("Is uppercase: %d, %s\n", isupper(c), boolean(isupper(c)));

	printf("Is hexadecimal: %d, %s\n", isxdigit(c), boolean(isxdigit(c)));

	purge_stream(stdin);
	char *str = NULL;
	size_t line_size = 0, line_real_size = 0;
	printf("Enter a line of text: \n");
	line_real_size = getline(&str, &line_size, stdin); 

	char *str_up = malloc(line_real_size * sizeof(char));
	char *str_low = malloc(line_real_size * sizeof(char));
	int i = 0;
	while( str[i] != '\0' ) {
		str_up[i] = toupper( str[i] );
		str_low[i] = tolower( str[i] );
		i++;
	}

	printf("To UPPER case: %s", str_up);
	printf("To lower case: %s", str_low);

	free(str);

	return 0;
}

