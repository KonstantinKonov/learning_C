#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_SIZE 100

int main() {
	char filename[] = "text.txt";
	char ch;

	// cheking does the file exist
	FILE *fp;
	if(fp = fopen(filename, "r")) {
		fclose;
		printf("File %s exists and will be overwritted.\n", filename);
	}
	else printf("File %s doesnt exist and will be created.\n", filename);

	// Writing to file with every single char
	fp = fopen(filename, "w");
	while( (ch = getchar()) != EOF) {
		fprintf(fp, "%c", ch);
	}	
	fclose(fp);
	
	// Reading from the file
	printf("Reading from the file:\n");
	fp = fopen(filename, "r");
	while(1) {
		ch = fgetc(fp);
		if(feof(fp)) break;
		printf("%c", ch);
	}
	fclose(fp);
	
	// Writing to the file the entire line
	fp = fopen(filename, "w");
	char *buff = malloc(MAX_STR_SIZE * sizeof(char));
	size_t str_size;
	getline(&buff, &str_size, stdin);
	fprintf(fp, "%s", buff);
	fclose(fp);


	return 0;
}