#ifndef BTREE_H
#define BTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

struct leaf {
    double val;
    struct leaf *r;
    struct leaf *l;
};

struct leaf *new_node(double);

struct leaf *insert(struct leaf *, double);

struct leaf *find_min(struct leaf *);

struct leaf *search(struct leaf *, double);

struct leaf *delete(struct leaf *, double);

void inorder(struct leaf *);

#endif