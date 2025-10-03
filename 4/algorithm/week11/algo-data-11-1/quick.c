#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

void quick(int a[], int left, int right){
    int pl = left;
    int pr = right;
    int x = a[(pl+pr) / 2];

    do {
        while (a[pl] < x) {
            pl++;
        }
        while (a[pr] > x) {
            pr--;
        }

        if (pl <= pr) {
            swap(int, a[pl], a[pr]);
            pl++;
            pr--;
        }

        // 左側でピポットより大きな要素と右側でピポットより小さな要素をスワップ

    } while (pl <= pr);

    if (left < pr){
        quick(a, left, pr);
    }    
    if (pl < right){
        quick(a, pl, right);
    }
}


int main(void){
    int nx;

    printf("quicksort\n");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; i++){
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    quick(x, 0, nx-1);

    printf("sorted!\n");
    for (int i = 0; i < nx; i++){
        printf("x[%d] = %d\n", i, x[i]);
    }

    free(x);
    return 0;
}