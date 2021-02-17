#include <stdio.h>
#include <stdlib.h>

struct node {
	char data;
	struct node *prev;
	struct node *next;
};

struct node *dl_find_last(struct node *head)
{
	if(head == NULL)
		return NULL;
	while(head->next != NULL) {
		head = head->next;
	}
	return head;
}

int dl_count(struct node *head)
{
	if(head == NULL)
		return 0;
	int count = 1;
	while(head->next != NULL) {
		head = head->next;
		count++;
	}
	return count;
}

void dl_put(struct node **head, char data)
{
	if(*head == NULL) {
		*head = (struct node *) malloc( sizeof(struct node) );
		(*head)->prev = NULL;
		(*head)->next = NULL;
		(*head)->data = data;
		return;
	}

	struct node *last = dl_find_last(*head);
	last->next = (struct node *) malloc( sizeof(struct node) );
	last->next->prev = last;
	last->next->next = NULL;
	last->next->data = data;
}

char dl_get(struct node **head)
{
	if(*head == NULL) {
		return EOF;
	}

	struct node *last = dl_find_last(*head);
	char c = last->data;
	if(last->prev == NULL) {
		free(*head);
		*head = NULL;
		return c;
	}
	else {
		struct node *prev = last->prev;
		prev->next = NULL;
		free(last);
		return c;
	}
}

void dl_print_all(struct node *head)
{
	if(head == NULL)
		return;
	while(head != NULL) {
		printf("%c ", head->data);
		head = head->next;
	}
	printf("\n");
}

void dl_insert(struct node *head, unsigned int index, char data)
{
	unsigned int len = dl_count(head);
	if(index > len + 1)
		return;
	if(index == len + 1) {
		dl_put(&head, data);
		return;
	}

	int count = 1;
	while(head->next != NULL && index != count) {
		head = head->next;
		count++;
	}

	struct node *current = (struct node *) malloc( sizeof(struct node) );
	head->prev->next = current;
	current->prev = head->prev;
	head->prev = current;
	current->next = head;
	current->data = data;
}

void dl_free(struct node **head)
{
	while(*head != NULL) {
		struct node *next = (*head)->next;
		free(*head);
		(*head) = next;
	}
}
	
int main()
{
	struct node *head = NULL;
	dl_put(&head, 'a');
	dl_put(&head, 'b');
	dl_put(&head, 'c');
	dl_put(&head, 'd');
	dl_insert(head, 6, 'z');
	dl_free(&head);

	dl_print_all(head);
	printf("count = %d\n", dl_count(head));

	printf("get = %c\n", dl_get(&head));
	printf("get = %c\n", dl_get(&head));
	printf("get = %c\n", dl_get(&head));
	printf("get = %c\n", dl_get(&head));
	printf("get = %c\n", dl_get(&head));

	dl_print_all(head);

	return 0;
}
