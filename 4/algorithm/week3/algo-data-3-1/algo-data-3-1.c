#include <stdio.h>

#include "IntStack.h"

int main(void) {
    IntStack s;
    if (Initialize(&s, 10000) == -1) {
        return 1;
    }

    int op = 0, v = 0;
    while (op != 11) {
        scanf("%d", &op);

        if (op == 1) {
            scanf("%d", &v);
            printf("%d\n", Push(&s, v));
        } else if (op == 2) {
            Pop(&s, &v);
            printf("%d\n", v);
        } else if (op == 3) {
            Peek(&s, &v);
            printf("%d\n", v);
        } else if (op == 4) {
            Print(&s);
        } else if (op == 5) {
            Clear(&s);
            printf("%d\n", Size(&s));
        } else if (op == 6) {
            printf("%d\n", Capacity(&s));
        } else if (op == 7) {
            printf("%d\n", Size(&s));
        } else if (op == 8) {
            printf("%d\n", IsEmpty(&s));
        } else if (op == 9) {
            printf("%d\n", IsFull(&s));
        } else if (op == 10) {
            scanf("%d", &v);
            printf("%d\n", Search(&s, v));
        } else if (op == 11) {
            return 0;
        }
    }
    return 0;
}
