#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

void bt_put(struct tnode **root, char *word)
{
	// if there is no elements in the binary tree
	if(*root == NULL) {
		*root = (struct tnode *) malloc( sizeof(struct tnode) );
		(*root)->word = (char *) malloc( (strlen(word) + 1) * sizeof(char) );
		strcpy( (*root)->word, word );
		(*root)->count = 1;
		(*root)->left = NULL;
		(*root)->right = NULL;
		return;
	}

	// if there is at least one element in the binary tree
	struct tnode *current = *root;
	while( 1 ) {
		int cmp_val = strcmp( current->word, word );
		if(cmp_val < 0) {
			if( current->left == NULL ) {
				current->left = (struct tnode *) malloc( sizeof(struct tnode) );
				current->left->word = (char *) malloc( (strlen(word) + 1) * sizeof(char) );
				strcpy( current->left->word, word );
				current->left->count = 1;
				current->left->left = NULL;
				current->left->right = NULL;
				break;
		 	}
			else {
				current = current->left;
			}
		}
		else if(cmp_val > 0) { 
			if( current->right == NULL ) {
				current->right = (struct tnode *) malloc( sizeof(struct tnode) );
				current->right->word = (char *) malloc( (strlen(word) + 1) * sizeof(char) );
				strcpy( current->right->word, word );
				current->right->count = 1;
				current->right->left = NULL;
				current->right->right = NULL;
				break;
			}
			else {
				current = current->right;
			}
		}
		else {
			current->count++;
			break;
		}
	}
}

void bt_print_all(struct tnode *root)
{
	if(root == NULL)
		return;
	printf("head: %s\n", root->word);
	if(root->left != NULL) 
		printf("left: %s\n", root->left->word);
	if(root->right != NULL) 
		printf("right: %s\n", root->right->word);
	if(root->left->left != NULL) 
		printf("left: %s\n", root->left->left->word);
	if(root->left->right != NULL) 
		printf("right: %s\n", root->left->right->word);
	if(root->right->left != NULL) 
		printf("left: %s\n", root->right->left->word);
	if(root->right != NULL) 
		printf("right: %s\n", root->right->right->word);
}

int main()
{
	struct tnode *root = NULL;
	bt_put(&root, "hello");
	bt_put(&root, "world");
	bt_put(&root, "dennis_ritchie");
	bt_put(&root, "bryan_kernighan");

	bt_print_all(root);

	return 0;
}

