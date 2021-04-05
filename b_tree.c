#include "b_tree.h"
#include <stdlib.h>

b_tree *b_tree_create(int t){
    b_tree * tree = (b_tree *)malloc(sizeof(b_tree));
    tree->t = t;
    b_tree_node *x = allocate_b_tree_node(t);
    x->leaf = 1;
    tree->root = x;
    return tree;
}

b_tree_node *allocate_b_tree_node (int t){
    int max = t * 2;
    b_tree_node *new_node = (b_tree_node *)malloc(sizeof(b_tree_node));
    new_node->keys = (int *)malloc((max+1) * sizeof(int));
    new_node->pointers = (b_tree_node **)malloc(sizeof(b_tree_node *) * (max+2));
    new_node->leaf = 0;
    new_node->n_keys = 0;

    for (int i = 0; i < max+2; i++){
        new_node->pointers[i] = NULL;
    }

    return new_node;
}

int b_tree_insert(b_tree *tree, int k){
    b_tree_node *r = tree->root;
    int t = tree->t;
    if (r->n_keys == 2*t-1){
        b_tree_node *s = allocate_b_tree_node(t);
        tree->root = s;
        s->leaf = 0;
        s->n_keys = 0;
        s->pointers[1] = r;
        b_tree_split_child(s,1,t);
        b_tree_insert_nonfull(s,k,t);
    } else {
        b_tree_insert_nonfull(r,k,t);
    }
    return 1;
}

int b_tree_split_child(b_tree_node *x, int i, int t){
    b_tree_node *z = allocate_b_tree_node(t);
    b_tree_node *y = x->pointers[i];
    z->leaf = y->leaf;
    z->n_keys = t-1;
    for (int j = 1; j < t-1; j++){
        z->keys[j] = y->keys[j+t];
    }
    if (!y->leaf){
        for (int j = 1; j < t; j++){
            z->pointers[j] = y->pointers[j+t];
        }
    }
    y->n_keys = t-1;
    for (int j = x->n_keys+1; j >= i+1; j--){
        x->pointers[j+1] = x->pointers[j];
    }
    x->pointers[i+1] = z;
    for (int j = x->n_keys; j >= i; j--){
        x->keys[j+1] = x->keys[j];
    }
    x->keys[i] = y->keys[t];
    x->n_keys = x->n_keys+1;

    return 1;
}

int b_tree_insert_nonfull(b_tree_node *x, int k, int t){
    int i = x->n_keys;
    if (x->leaf){
        while (i >= 1 && k < x->keys[i]){
            x->keys[i+1] = x->keys[i];
            i--;
        }
        x->keys[i+1] = k;
        x->n_keys++;
    } else {
        while (i >= 1 && k < x->keys[i]){
            i--;
        }
        i++;
        if (x->pointers[i]->n_keys == 2*t-1){
            b_tree_split_child(x,i,t);
            if (k > x->keys[i]){
                i++;
            }
        }
        b_tree_insert_nonfull(x->pointers[i],k,t);
    }
    return 1;
}