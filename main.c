#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <zlib.h>
#include "avl_tree.h"
#include "b_tree.h"

int main() {
    avl_tree *tree = create_avl_tree();
    int start_value = time(NULL);
    for (int i = 0; i < 100; i++){
        srand(start_value+i);
        insert_avl_node(tree, rand()%100);
    }
    printf("Hello World\n");
    return 0;
}
