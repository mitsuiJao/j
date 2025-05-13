#include <stdio.h>

#include "IntQueue.h"

int main(void) {
    IntQueue q;
    if (Initialize(&q, 10000) == -1) {
        return 1;
    }

    int op = 0, v = 0;
    while (op != 11) {
        scanf("%d", &op);

        if (op == 1) {
            scanf("%d", &v);
            Enque(&q, v);
            printf("%d\n", v);
            printf("op1: Enque executed\n");
        } else if (op == 2) {
            Deque(&q, &v);
            printf("%d\n", v);
            printf("op2: Deque executed\n");
        } else if (op == 3) {
            Peek(&q, &v);
            printf("%d\n", v);
            printf("op3: Peek executed\n");
        } else if (op == 4) {
            Print(&q);
            printf("op4: Print executed\n");
        } else if (op == 5) {
            Clear(&q);
            printf("%d\n", Size(&q));
            printf("op5: Clear executed\n");
        } else if (op == 6) {
            printf("%d\n", Capacity(&q));
            printf("op6: Capacity executed\n");
        } else if (op == 7) {
            printf("%d\n", Size(&q));
            printf("op7: Size executed\n");
        } else if (op == 8) {
            printf("%d\n", IsEmpty(&q));
            printf("op8: IsEmpty executed\n");
        } else if (op == 9) {
            printf("%d\n", IsFull(&q));
            printf("op9: IsFull executed\n");
        } else if (op == 10) {
            scanf("%d", &v);
            printf("%d\n", Search(&q, v));
            printf("op10: Search executed\n");
        } else if (op == 11) {
            printf("op11: Exit executed\n");
            return 0;
        }
    }
    return 0;
}
