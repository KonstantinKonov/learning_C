#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 100

int main() {
	FILE *fp;
	char filename[] = "text.txt";
	char str[] = "This is a string!";
	char buff[BUFF_SIZE];

	fp = fopen(filename, "w+");
	
	fwrite(str, strlen(str) + 1, 1, fp);

	fseek(fp, 0, SEEK_SET);

	fread(buff, strlen(str) + 1, 1, fp);
	printf("%s\n", buff);
	fclose(fp);

	return 0;
}