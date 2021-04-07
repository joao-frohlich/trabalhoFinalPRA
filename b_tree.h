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

b_tree *b_tree_create(int t, int *conta);
b_tree_node *allocate_b_tree_node (int t, int *conta);
int b_tree_insert(b_tree *tree, int k, int *conta);
int b_tree_split_child(b_tree_node *x, int i, int t, int *conta);
int b_tree_insert_nonfull(b_tree_node *x, int k, int t, int *conta);
void print_b_tree(b_tree_node *x, int t, int d);

#endif //B_TREE_H
