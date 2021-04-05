#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <zlib.h>
#include "avl_tree.h"
#include "b_tree.h"

int main() {
    avl_tree *avlTree = create_avl_tree();
    b_tree *bTree = b_tree_create(2);
    int start_value = time(NULL);
    for (int i = 0; i < 10; i++){
        srand(start_value+i);
        b_tree_insert(bTree,rand()%100);
        insert_avl_node(avlTree, rand()%100);
    }
    printf("Hello World\n");
    return 0;
}
