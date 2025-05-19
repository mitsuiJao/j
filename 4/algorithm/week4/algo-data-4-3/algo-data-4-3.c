#include <stdio.h>
#include "BinTree.h"

int main(void) {
    BinNode *t = NULL;
    int op, v;

    while (op != 6) {
        scanf("%d", &op);

        if (op == 1) {
            scanf("%d", &v);
            search(t, v);
        } else if (op == 2) {
            scanf("%d", &v);
            t = add(t, v);
        } else if (op == 3) {
            scanf("%d", &v);
            removeNode(&t, v);
        } else if (op == 4) {
            printNode(t);
        } else if (op == 5) {
            freeTree(t);
        } 
    }
    
    return 0;
}
