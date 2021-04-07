#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <zlib.h>
#include "avl_tree.h"
#include "b_tree.h"

int main() {
    int conta_op_avl_tree = 0, conta_op_b_tree = 0;
    avl_tree *avlTree = create_avl_tree(&conta_op_avl_tree);
    b_tree *bTree = b_tree_create(2, &conta_op_b_tree);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        insert_avl_node(avlTree,x,&conta_op_avl_tree);
        b_tree_insert(bTree,x,&conta_op_b_tree);
    }

    printf("%d\n", conta_op_avl_tree);
    printf("%d\n", conta_op_b_tree);
    return 0;
}
