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
        } else if (op == 2) {
            scanf("%d", &v);
            insertRear(&l, v);
            printf("%d\n", v);
        } else if (op == 3) {
            removeFront(&l);
        } else if (op == 4) {
            removeRear(&l);
        } else if (op == 5) {
            scanf("%d", &v);
            printf("%d\n", removeSearch(&l, v));
        } else if (op == 6) {
            scanf("%d", &v);
            printf("%d\n", searchIndex(&l, v));
        } else if (op == 7) {
            printf("%d\n", size(&l));
        } else if (op == 8) {
            print(&l);
        } else if (op == 9) {
            clear(&l);
            printf("%d\n", size(&l));
        } else if (op == 10) {
            terminate(&l);
            return 0;
        }
    }
    return 0;
}