#include "linked_list.h"

int list_init(node_t **n, double val)
{
    *n = (node_t *) malloc(sizeof(node_t));

    if(*n == NULL) {
        return 1;
    }

    (*n)->val = val;
    (*n)->next = NULL;

    return 0;
}

node_t *list_last(node_t *list)
{   
    node_t *ptr = list;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    return ptr;
}

void list_append(node_t *list, double val)
{
    node_t *last = list_last(list);
    last->next = (node_t *) malloc(sizeof(node_t));
    last->next->next = NULL;
    last->next->val = val;
}

void list_print(node_t *list, FILE *stream)
{
    node_t *ptr = list;
    fprintf(stream, "%.2lf\n", ptr->val);

    while(ptr->next != NULL) {
        ptr = ptr->next;
        fprintf(stream, "%.2lf\n", ptr->val);
    };
}

uint32_t list_count(node_t *list)
{
    if(list == NULL)
        return 0;

    uint32_t counter = 1;

    while(list->next != NULL) {
        counter++;
        list = list->next;
    }

    return counter; 
}

node_t *list_moveto(node_t *list, uint32_t n) 
{
    if(n == 1)
        return list;

    uint32_t counter = 1;

    while(list->next != NULL && counter < n) 
        list = list->next, counter++;

    return list;
}

void list_insert_element(node_t *list, uint32_t place, double val)
{
    node_t *new_node;
    new_node = (node_t*) malloc(sizeof(node_t));
    list = list_moveto(list, place);
    node_t *next = list->next;
    list->next = new_node;
    new_node->next = next;
    new_node->val = val;
}

void list_push(node_t **list, double val)
{
    node_t *nd_new = (node_t *) malloc(sizeof(node_t));
    nd_new->next = *list;
    nd_new->val = val;
    *list = nd_new;
}

double list_pop(node_t **list)
{
    node_t *nd_next = NULL;
    double val = -99.0;

    if(*list != NULL) {
        nd_next =  (*list)->next;
        val = (*list)->val;
        free(*list);
        *list = nd_next;
    }

    return val;
}

void list_insert_list(node_t **list1, node_t *list2, uint32_t place)
{
    uint32_t size2 = list_count(list2);
    node_t *ptr = list2;
    for(uint32_t i = 0; i < size2; i++) {
        list_append(*list1, ptr->val);
        ptr = ptr->next;
    }
}

void list_remove(node_t **list, uint32_t place)
{
    if(place == 1)
        list_pop(list);
    
    node_t *ptr = list_moveto(*list, place - 1);

    node_t *temp_node = ptr->next;
    ptr->next = temp_node->next;

    free(temp_node);
}

void list_from_array1D(node_t **list, array1D *arr)
{
    uint32_t size = arr->size;
    *list = (node_t *) malloc(size * sizeof(node_t));
    node_t *ptr = *list;
    for(uint32_t i = 0; i < size - 1; i++) {
        ptr->val = *(arr->data + i);
        ptr->next = ptr + sizeof(node_t); //+sizof(node_t)
        ptr = ptr + sizeof(node_t);
    }
    ptr->val = arr->data[size - 1];
    ptr->next = NULL;
}