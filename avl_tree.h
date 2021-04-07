#ifndef AVL_TREE_H
#define AVL_TREE_H

typedef struct avl_node{
    struct avl_node *parent;
    struct avl_node *left;
    struct avl_node *right;
    int value;
} avl_tree_node;

typedef struct{
    avl_tree_node *root;
} avl_tree;

avl_tree *create_avl_tree(int *conta);
int insert_avl_node(avl_tree *tree, int value, int *conta);
avl_tree_node *right_simple_rotation(avl_tree *tree, avl_tree_node *node, int *conta);
avl_tree_node *right_double_rotation(avl_tree *tree, avl_tree_node *node, int *conta);
avl_tree_node *left_simple_rotation(avl_tree *tree, avl_tree_node *node, int *conta);
avl_tree_node *left_double_rotation(avl_tree *tree, avl_tree_node *node, int *conta);
int compute_node_height(avl_tree_node *node, int *conta);
int compute_node_balance_factor(avl_tree_node *node, int *conta);
int balancing(avl_tree *tree, avl_tree_node *node, int *conta);
void print_avl_tree(avl_tree_node *node);

#endif //AVL_TREE_H
