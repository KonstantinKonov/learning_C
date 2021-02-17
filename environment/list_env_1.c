// list environment or print value of particular environment
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void print_env_list()
{
	extern char **environ;
	
	int i = 0;
	while( environ[i] != NULL ) // NULL string at the end of the list?
		printf("%s\n", environ[i++]);
	printf("Total amount of %d variables\n", i);
}

char *get_var_val(char *var)
{
	if( var == NULL || !strcmp(var, " ") )
		return NULL;

	extern char **environ;

	char *val = NULL;
	int i = 0;
	while( environ[i] != NULL ) {
		if( strstr(environ[i], var) != NULL ) {
			char delimiter[2] = "=";
			char *token = strtok(environ[i], delimiter);
			while( token != NULL ) {
				val = (char *) realloc( val, (strlen(token) + 1) * sizeof(token) );
				strcpy(val, token);
				token = strtok(NULL, delimiter);
			}
			break;
		}
		i++;
	}

	return val;
}

int main(int argc, char **argv)
{
	if(argc == 1) {
		print_env_list();
		exit(0);
	}
	if(argc == 2) {
		char *val = get_var_val(argv[1]);
		printf("Variable %s has value %s\n", argv[1], val);
		exit(0);
	}

	return 0;
}
	
