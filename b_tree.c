#include "b_tree.h"
#include <stdlib.h>
#include <stdio.h>

b_tree *b_tree_create(int t, int *conta){
    *conta = *conta+1;
    b_tree * tree = (b_tree *)malloc(sizeof(b_tree));
    tree->t = t;
    b_tree_node *x = allocate_b_tree_node(t, conta);
    x->leaf = 1;
    tree->root = x;
    return tree;
}

b_tree_node *allocate_b_tree_node (int t, int *conta){
    *conta = *conta+1;
    int max = t * 2;
    b_tree_node *new_node = (b_tree_node *)malloc(sizeof(b_tree_node));
    new_node->keys = (int *)malloc((max+5) * sizeof(int));
    new_node->pointers = (b_tree_node **)malloc(sizeof(b_tree_node *) * (max+5));
    new_node->leaf = 0;
    new_node->n_keys = 0;

    for (int i = 0; i < max+2; i++){
        *conta = *conta+1;
        new_node->pointers[i] = NULL;
    }

    return new_node;
}

int b_tree_insert(b_tree *tree, int k, int *conta){
    *conta = *conta+1;
    b_tree_node *r = tree->root;
    int t = tree->t;
    if (r->n_keys == 2*t-1){
        b_tree_node *s = allocate_b_tree_node(t, conta);
        tree->root = s;
        s->leaf = 0;
        s->n_keys = 0;
        s->pointers[1] = r;
        b_tree_split_child(s,1,t,conta);
        b_tree_insert_nonfull(s,k,t,conta);
    } else {
        b_tree_insert_nonfull(r,k,t,conta);
    }
    return 1;
}

int b_tree_split_child(b_tree_node *x, int i, int t, int *conta){
    *conta = *conta+1;
    b_tree_node *z = allocate_b_tree_node(t,conta);
    b_tree_node *y = x->pointers[i];
    z->leaf = y->leaf;
    z->n_keys = t-1;
    for (int j = 1; j <= t-1; j++){
        *conta = *conta+1;
        z->keys[j] = y->keys[j+t];
    }
    if (!y->leaf){
        for (int j = 1; j <= t; j++){
            *conta = *conta+1;
            z->pointers[j] = y->pointers[j+t];
            y->pointers[j+t] = NULL;
        }
    }
    y->n_keys = t-1;
    for (int j = x->n_keys+1; j >= i+1; j--){
        *conta = *conta+1;
        x->pointers[j+1] = x->pointers[j];
    }
    x->pointers[i+1] = z;
    for (int j = x->n_keys; j >= i; j--){
        *conta = *conta+1;
        x->keys[j+1] = x->keys[j];
    }
    x->keys[i] = y->keys[t];
    x->n_keys = x->n_keys+1;

    return 1;
}

int b_tree_insert_nonfull(b_tree_node *x, int k, int t, int *conta){
    *conta = *conta+1;
    int i = x->n_keys;
    if (x->leaf){
        while (i >= 1 && k < x->keys[i]){
            *conta = *conta+1;
            x->keys[i+1] = x->keys[i];
            i--;
        }
        x->keys[i+1] = k;
        x->n_keys++;
    } else {
        while (i >= 1 && k < x->keys[i]){
            *conta = *conta+1;
            i--;
        }
        i++;
        if (x->pointers[i]->n_keys == 2*t-1){
            b_tree_split_child(x,i,t,conta);
            if (k > x->keys[i]){
                i++;
            }
        }
        b_tree_insert_nonfull(x->pointers[i],k,t,conta);
    }
    return 1;
}

void print_b_tree(b_tree_node *x, int t, int d){
    printf("Profundidade %d: ", d);
    for (int i = 1; i <= x->n_keys; i++){
        printf("%d ", x->keys[i]);
    }
    printf("\n");
    for (int i = 0; i < t*2+2; i++){
        if (x->pointers[i] != NULL){
            print_b_tree(x->pointers[i], t, d+1);
        }
    }
}