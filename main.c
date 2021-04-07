#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <zlib.h>
#include "avl_tree.h"
#include "b_tree.h"

int main() {
    int conta_op_avl_tree = 0;
    avl_tree *avlTree = create_avl_tree(&conta_op_avl_tree);
    //b_tree *bTree = b_tree_create(2);
    int u[100];
    for (int i = 0; i < 100; i++) u[i] = 0;
    int start_value = time(NULL);
    int tot = 0, i = 0;
    int conta_op_b_tree = 0;
    while (tot < 20){
        srand(start_value+(i++));
        int x = rand()%100;
        if (u[x]) continue;
        printf("%d ", x);
        u[x] = 1;
        tot++;
        insert_avl_node(avlTree,x,&conta_op_avl_tree);
    }
    printf("\n\n");
    print_avl_tree(avlTree->root);
    printf("\n%d\n", conta_op_avl_tree);
    printf("\n");
    return 0;
}
