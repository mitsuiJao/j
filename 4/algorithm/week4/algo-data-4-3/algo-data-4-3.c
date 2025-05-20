#include <stdio.h>
#include "BinTree.h"

int main(void) {
    BinNode *t = NULL;
    int op, v;

    while (op != 6) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &v);
            printf("%s\n", search(t, v) != NULL ? "YES" : "NO");
        } else if (op == 2) {
            scanf("%d", &v);
            t = add(t, v);
        } else if (op == 3) {
            scanf("%d", &v);
            removeNode(&t, v);
        } else if (op == 4) {
            if (t == NULL){
                printf("NONE\n");
            } else {
                printNode(t);
                printf("\n");
            }
        } else if (op == 5) {
            freeTree(t);
            t = NULL;           // safety
        } 
    }
    
    return 0;
}
