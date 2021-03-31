#ifndef B_TREE_H
#define B_TREE_H

typedef struct b_node{
    int n_keys;
    int *keys;
    int leaf;
    struct b_node **pointers;
} b_tree_node;

typedef struct {
    b_tree_node *root;
    int t;
} b_tree;

b_tree *b_tree_create(int t);
int b_tree_insert(b_tree *tree, int value);
int b_tree_split_child(b_tree_node *x, int i);
int b_tree_insert_nonfull(b_tree_node *x, int k);


#endif //B_TREE_H
