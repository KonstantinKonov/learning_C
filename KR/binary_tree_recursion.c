#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {
	char *word;
	unsigned int count;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *tnode_allocate(unsigned int word_len)
{
	struct tnode *p = (struct tnode *) malloc( sizeof(struct tnode) );
	p->word = (char *) malloc( sizeof(char) );
	p->count = 1;
	p->left = p->right = NULL;
	return p;
}

struct tnode *bt_add(struct tnode *p, char *word)
{
	int cmp_val;
	if(p == NULL) {
		p = tnode_allocate( strlen(word) + 1 );
		strcpy(p->word, word);
	}
	else if( (cmp_val = strcmp( p->word, word )) == 0 ) 
		p->count++;
	else if( cmp_val < 0 ) 
		p->left = bt_add(p->left, word);
	else 
		p->right = bt_add(p->right, word);
	return p;
}

void bt_print_all(struct tnode *p)
{
	if( p != NULL ) {
		bt_print_all(p->left);
		printf("%4d %s\n", p->count, p->word);
		bt_print_all(p->right);
	}
}

int main()
{
	struct tnode *root = NULL;
	char *str = NULL;
	size_t n = 0;
	if( getline(&str, &n, stdin) == -1 )
		return 0;
	str[strlen(str) - 1] = '\0';

	char *token = strtok(str, " ");
	while( token != NULL ) {
		root = bt_add(root, token);
		token = strtok(NULL, " ");
	}

	bt_print_all(root);

	return 0;
}
