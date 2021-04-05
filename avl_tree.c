#include "avl_tree.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

avl_tree *create_avl_tree(){
    avl_tree *tree = (avl_tree*)malloc(sizeof(avl_tree));
    tree->root = NULL;
    return tree;
}

int insert_avl_node(avl_tree *tree, int value){
    avl_tree_node *node = (avl_tree_node*)malloc(sizeof(avl_tree_node));
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    node->value = value;
    if (tree->root == NULL){
        tree->root = node;
    } else {
        avl_tree_node *aux_node = tree->root;
        while ((value <= aux_node->value && aux_node->left != NULL) || (value > aux_node->value && aux_node->right != NULL)){
            if (value <= aux_node->value){
                aux_node = aux_node->left;
            } else {
                aux_node = aux_node->right;
            }
        }
        node->parent = aux_node;
        if (value <= aux_node->value){
            aux_node->left = node;
        } else {
            aux_node->right = node;
        }
        balancing(tree, node);
    }
    return 1;
}

avl_tree_node *right_simple_rotation(avl_tree *tree, avl_tree_node *node){
    avl_tree_node *parent = node->parent;
    avl_tree_node *left = node->left;

    node->left = left->right;
    if (left->right != NULL){
        left->right->parent = node;
    }
    node->parent = left;

    left->right = node;
    left->parent = parent;

    if (parent == NULL){
        tree->root = left;
    } else {
        if (parent->left == node){
            parent->left = left;
        } else {
            parent->right = left;
        }
    }

    return left;
}

avl_tree_node *right_double_rotation(avl_tree *tree, avl_tree_node *node){
    node->left = left_simple_rotation(tree, node->left);
    return right_simple_rotation(tree, node);
}

avl_tree_node *left_simple_rotation(avl_tree *tree, avl_tree_node *node){
    avl_tree_node *parent = node->parent;
    avl_tree_node *right = node->right;

    node->right = right->left;
    if (right->left != NULL){
        right->left->parent = node;
    }
    node->parent = right;

    right->left = node;
    right->parent = parent;

    if (parent == NULL){
        tree->root = right;
    } else {
        if (parent->left == node){
            parent->left = right;
        } else {
            parent->right = right;
        }
    }

    return right;
}

avl_tree_node *left_double_rotation(avl_tree *tree, avl_tree_node *node){
    node->right = right_simple_rotation(tree, node->right);
    return left_simple_rotation(tree, node);
}

int compute_node_height(avl_tree_node *node){
    int height = 0;
    if (node->left != NULL){
        height = compute_node_height(node->left)+1;
    }
    if (node->right != NULL){
        height = max(height,compute_node_height(node->right)+1);
    }
    return height;
}

int compute_node_balance_factor(avl_tree_node *node){
    int balance_factor = 0;
    if (node->left != NULL){
        balance_factor += compute_node_height(node->left)+1;
    }
    if (node->right != NULL){
        balance_factor -= (compute_node_height(node->right)+1);
    }
    return balance_factor;
}

int balancing(avl_tree *tree, avl_tree_node *node){
    while (node != NULL){
        int balance_factor = compute_node_balance_factor(node);
        if (balance_factor > 1){
            if (compute_node_balance_factor(node->left) > 0){
                node = right_simple_rotation(tree, node);
            } else {
                node = right_double_rotation(tree, node);
            }
        } else if (balance_factor < -1){
            if (compute_node_balance_factor(node->right) < 0){
                node = left_simple_rotation(tree, node);
            } else {
                node = left_double_rotation(tree, node);
            }
        }
        node = node->parent;
    }
    return 1;
}

void print_avl_tree(avl_tree_node *node){
    if (node == NULL) return;
    printf("%d ", node->value);
    print_avl_tree(node->left);
    print_avl_tree((node->right));
}