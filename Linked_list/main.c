//

// Defines

// Libraries
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

// User's libraries

// User defines types
typedef struct llist {
    double val;
    struct llist *next;
} llist_t;

// User defined variables

// User defined functions
llist_t *llend(llist_t *lroot)
{
    while(lroot->next != NULL)
        lroot = lroot->next;
    return lroot;
}

llist_t *llseek(llist_t *lroot, uint64_t num)
{
    uint64_t cnt = 0;
    while(lroot != NULL && cnt < num) {
        lroot = lroot->next;
        cnt++;
    }
    return lroot;
}

double llseekd(llist_t *lroot, uint64_t num)
{
    uint64_t cnt = 0;
    while(lroot != NULL && cnt < num) {
        lroot = lroot->next;
        cnt++;
    }
    return lroot->val;
}

uint64_t llcount(llist_t *lroot)
{
    uint64_t cnt = 0;
    while(lroot != NULL) {
        cnt++; 
        lroot = lroot->next;
    }
    return cnt;
}

void llpush(llist_t **lroot, double data)
{
    llist_t *node = (llist_t *) malloc(sizeof(llist_t));
    node->val = data;
    node->next = *lroot;

    *lroot = node;
}

double llpop(llist_t **lroot)
{
    double val = (*lroot)->val;
    llist_t *ptr = *lroot;
    *lroot = (*lroot)->next;
    free(ptr);

    return val;
}

void llappend(llist_t **lroot, double data)
{
    llist_t *node = (llist_t *) malloc(sizeof(llist_t));
    node->val = data;
    node->next = NULL;
    
    if(*lroot == NULL) {
        *lroot = node;
        return;
    }
    
    llend(*lroot)->next = node;
}

void llinsertd(llist_t **lroot, double data, int64_t place)
{
    llist_t *node = (llist_t *) malloc(sizeof(llist_t));
    node->val = data;
    node->next = NULL;

    if(place < 0) {
        if(abs(place) > llcount(*lroot)) {
            place = (-1) * (llcount(*lroot));
        }
        place = llcount(*lroot) + place;
    }

    if(place == 0) {
        llpush(lroot, data);
        return;
    }

    if(place >= llcount(*lroot) - 1) {
        llappend(lroot, data);
        return;
    }

    node->next = llseek(*lroot, place);

    llseek(*lroot, place - 1)->next = node;
}

void llprint(llist_t *lroot, FILE *stream)
{
    llist_t *ptr = lroot;
    while(ptr != NULL) {
        fprintf(stream, "%.2lf\n", ptr->val);
        ptr = ptr->next;
    }
}

void llappendl(llist_t *lA, llist_t *lB)
{
    llend(lA)->next = lB;
}

void llinsertl(llist_t *lA, llist_t *lB, int64_t n)
{
    if(n == 0) {
        llappendl(lB, lA);
        return;
    }
    
    if(n >= llcount(lA) - 1) {
        llappendl(lA, lB);
        return;
    }

    llend(lB)->next = llseek(lA, n);
    llseek(lA, n - 1)->next = lB;
}

// Main
int main(int argc, char **argv)
{
    llist_t *lroot = NULL, *lB = NULL;

    llappend(&lroot, 0.0);
    llappend(&lroot, 1.0);
    llappend(&lroot, 2.0);
    llappend(&lroot, 3.0);
    llappend(&lroot, 4.0);
    llappend(&lroot, 5.0);

    llappend(&lB, 0.0);
    llappend(&lB, 1.0);
    llappend(&lB, 2.0);
    llappend(&lB, 3.0);
    //llpush(&lroot, -1.0);

    //llappend(&lroot, 999.0);

    //printf("pop = %.2lf\n", llpop(&lroot));
    
    //llprint(lroot, stdout);

    //printf("count = %ld\n", llcount(lroot));

    //printf("val = %.2lf\n", llseekd(lroot, 3));

    //llinsertd(&lroot, 111, 3);

    //llprint(lroot, stdout);

    llinsertl(lroot, lB, 0);

    llprint(lB, stdout);

    return 0;
}