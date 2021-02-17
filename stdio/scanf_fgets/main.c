#include <stdio.h>
#include <stdlib.h>

#define STR_MAX 10

int main() 
{
	char *buffer = (char *) malloc(STR_MAX);
	if(buffer == NULL) {
		perror("Unable to allocate buffer");
		exit(1);
	}
	size_t size = STR_MAX;	

	// // Scanf is not safe
	// scanf("%s", buffer);
	// printf("Scanf read: %s\n", buffer);

	// // Fscanf is not safe
	// FILE *fp = fopen("text.txt", "w+");
	// fputs("Some demo text here.", fp);
	// rewind(fp);
	// fscanf(fp, "%s", buffer);
	// printf("First word read by fscanf: %s\n", buffer);
	// fclose(fp);

	// Clear stdin buffer
	char *buf;
	size_t buf_size = 0;
	getline(&buf, &buf_size, stdin);

	// getline
	getline(&buffer, &size, stdin);
	printf("Getline() read string: %s", buffer);

	// Fgets
	fgets(buffer, size, stdin);
	fputs(buffer, stdout);
	fputc('\n', stdout);

	return 0;
}