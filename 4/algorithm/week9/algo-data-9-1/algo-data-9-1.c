#include <stdio.h>
#include "ChainHash.h"

int main(void){
    ChainHash hash;
    if (Initialize(&hash, 10) == 0){
        return 1;
    };

    int n;
    scanf("%d", &n);
    if (n > 10000) n = 10000;
    for (int count = n; count != 0; count--){
        int x, op;
        Node *temp;
        scanf("%d", &op);
        if (op == 1){
            scanf("%d", &x);
            Add(&hash, x);
        }
        else if (op == 2){
            scanf("%d", &x);
            if (Remove(&hash, x) == 1){
                printf("Not Found\n");
            };
        }
        else if (op == 3){
            scanf("%d", &x);
            if (Search(&hash, x) != NULL){
                printf("Found\n");
            } else {
                printf("Not Found\n");
            }
        }
        else if (op == 4){
            Clear(&hash);
        }
        else if (op == 5){
            Dump(&hash);
        }
        else if (op == 0){
            Clear(&hash);
            break;
        }
    }
    Terminate(&hash);
    return 0;
}