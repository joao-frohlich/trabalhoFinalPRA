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

avl_tree *create_avl_tree();
int insert_avl_node(avl_tree *tree, int value);
int right_simple_rotation(avl_tree *tree);
int right_double_rotation(avl_tree *tree);
int left_simple_rotation(avl_tree *tree);
int left_simple_rotation(avl_tree *tree);


#endif //AVL_TREE_H
