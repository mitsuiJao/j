#include <stdio.h>
#include "linkedList.h"

int main(void){
    List l;
    initialize(&l);

    int op = 0, v = 0;
    while (op != 11) {
        scanf("%d", &op);

        if (op == 1) {
            scanf("%d", &v);
            insertFront(&l, v);
            printf("%d\n", v);
            printf("op1\n");
        } else if (op == 2) {
            scanf("%d", &v);
            insertRear(&l, v);
            printf("%d\n", v);
            printf("op2\n");
        } else if (op == 3) {
            removeFront(&l);
            printf("op3\n");
        } else if (op == 4) {
            removeRear(&l);
            printf("op4\n");
        } else if (op == 5) {
            scanf("%d", &v);
            printf("%d\n", removeSearch(&l, v));
            printf("op5\n");
        } else if (op == 6) {
            scanf("%d", &v);
            printf("%d\n", searchIndex(&l, v));
            printf("op6\n");
        } else if (op == 7) {
            printf("%d\n", size(&l));
            printf("op7\n");
        } else if (op == 8) {
            print(&l);
            printf("op8\n");
        } else if (op == 9) {
            clear(&l);
            printf("%d\n", size(&l));
            printf("op9\n");
        } else if (op == 10) {
            terminate(&l);
            printf("op10\n");
            return 0;
        }
    }
    return 0;
}