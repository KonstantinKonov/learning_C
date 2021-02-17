#include "btree.h"

struct leaf *new_node(double val)
{
    struct leaf *p;
    p = malloc(sizeof(struct leaf));
    p->val = val;
    p->l = NULL;
    p->r = NULL;

    return p;
}

struct leaf *insert(struct leaf *root, double val)
{
    if(root == NULL)
        return new_node(val);
    else if(val > root->val)
        root->r = insert(root->r, val);
    else 
        root->l = insert(root->l, val);
    return root;
}

struct leaf *find_min(struct leaf *root)
{
    if(root == NULL)
        return root;
    else if(root->l != NULL)
        return find_min(root->l);
    return root;
}

struct leaf *search(struct leaf *root, double val)
{
    if(root == NULL || root->val == val)
        return root;
    else if(val > root->val)
        return search(root->r, val);
    else 
        return search(root->l, val);
}

struct leaf *delete(struct leaf *root, double val)
{
    if(root == NULL)
        return root;
    if(val > root->val)
        root->r = delete(root->r, val);
    else if(val < root->val)
        root->l = delete(root->l, val);
    else {
        if(root->l == NULL && root->r == NULL) {
            free(root);
            return NULL;
        }

        else if(root->l == NULL || root->r == NULL) {
            struct leaf *temp_leaf;
            if(root->l == NULL)
                temp_leaf = root->r;
            else
                temp_leaf = root->l;
            free(root);
            return temp_leaf;
        }

        else
        {
            struct leaf *temp_leaf = find_min(root->r);
            root->val = temp_leaf->val;
            root->r = delete(root->r, temp_leaf->val);
        }
    }
    return root;
}

void inorder(struct leaf *root)
{
    if(root != NULL) {
        inorder(root->l);
        printf(" %.1lf ", root->val);
        inorder(root->r);
    }
}