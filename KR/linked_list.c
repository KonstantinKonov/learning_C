// the program implements linked list data structures
// problems: unable to delete the first element
#include <stdio.h>
#include <stdlib.h>

struct node {
	char data;
	struct node *next;
};

// init linked list, return - pointer to first element (head)
struct node *ll_init(char data)
{
	struct node *head = (struct node *) malloc( sizeof(struct node) );
	head->data = data;
	head->next = NULL;
	return head;
}

// returns the last node in linked list
struct node *ll_find_last(struct node *head)
{
	struct node *last = head;
	if( last->next == NULL )
		return last;
	while(last->next != NULL )
		last = last->next;
	return last;
}

// returns pointer to second from the end element
struct node *ll_find_prelast(struct node *head)
{
	struct node *last = head;
	struct node *prelast = NULL;
	if( last->next == NULL )
		return NULL;
	while(last->next != NULL ) {
		prelast = last;
		last = last->next;
	}
	return prelast;
}

// put element data to the end of linked list
void ll_put(struct node **head, char data)
{
	// linked list with no elements
	if((*head) == NULL) {
		*head = (struct node *) malloc( sizeof(struct node) );
		(*head)->next = NULL;
		(*head)->data = data;
	}
	// linked list with one or more elements
	else {
		struct node *last = ll_find_last(*head);
		last->next = (struct node *) malloc( sizeof(struct node) );
		last->next->data = data;
		last->next->next = NULL;
	}
}

// delete and return the last element of the linked list
void ll_get(struct node **head, char *c)
{
	// linked list with no elements
	if(*head == NULL) {
		c = NULL;
		return;
	}

	// linked list with first and single element
	if((*head)->next == NULL) {
		*c = (*head)->data;
		free(*head); // is it a correct memory free
		*head = NULL;
		return;
	}

	// linked list with more than one element
	struct node *last = ll_find_last(*head);
	struct node *prelast = ll_find_prelast(*head);
	*c = last->data;
	free(last); 
	prelast->next = NULL;
}

// prints out the whole linked list
void ll_print(struct node *head)
{
	if( head == NULL )
		return;
	struct node *current = head;
	do {
		printf("%c ", current->data);
	} while( (current = current->next) != NULL );
	printf("\n");
}

// delete linked list
void ll_free(struct node **head)
{
	if(*head == NULL)
		return;
	if((*head)->next == NULL) {
		free(*head);
		*head = NULL;
		return;
	}
	do {
		struct node *next = (*head)->next;
		free(*head);
		*head = next;
	}
	while(*head != NULL);
}

int main()
{
	struct node *head = ll_init('a');
	ll_put(&head, 'b');
	ll_put(&head, 'c');
	ll_put(&head, 'd');

	ll_print(head);

	char c;
	ll_get(&head, &c);

	ll_free(&head);

	ll_put(&head, 'c');
	
	ll_print(head);

	return 0;
}
