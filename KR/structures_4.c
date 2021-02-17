// The program counts keywords in a text file
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define OUT 0
#define IN 1
#define N 11

struct key {
	char *word;
	int count;
} keytab[] = {
	"auto", 0,
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"default", 0,
	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0
};

void print_key(struct key kt[], int n)
{
	for(int i = 0; i < n; i++)
		printf("%s: %d\n", kt[i].word, kt[i].count);
}

int binsearch(char *word, struct key keytab[], int n)
{
	int low = 0;
	int high = n - 1;
	int cond;
	int mid;
	
	while( low <= high ) {
		mid = ( low + high ) / 2;
		if( (cond = strcmp(word, keytab[mid].word)) < 0 )
			high = mid - 1;
		else if( cond > 0 )
			low = mid + 1;
		else 
			return mid;
	}
	return -1;
}

// getwords
void getword(FILE *stream)
{
	char c;
	int state = OUT;
	char word[1000];
	int len = 0;

	while( (c = getc(stream)) != EOF ) {
		if( isalpha(c) ) {
			if( state == OUT ) 
				state = IN;
			word[len] = c;
			len++;
		}
		else if(state == IN) {
				word[len] = '\0';
				len = 0;
				state = OUT;

				// search the word in keytab
				int index;
				if( (index = binsearch(word, keytab, N)) != -1)
					keytab[index].count++;
		}
	}
}

//
int main()
{
	FILE *fp = fopen("structures_4.c", "r");
	getword(fp);
	fclose(fp);

	print_key(keytab, N);

	return 0;
}
