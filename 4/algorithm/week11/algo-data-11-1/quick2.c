#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; swap_count++; } while (0)

int sort3elem_count = 0;
int quick_count = 0;
int swap_count = 0;


int sort3elem(int x[], int a, int b, int c){
    sort3elem_count++;
    if (x[b] < x[a]) swap(int, x[b], x[a]);
    if (x[c] < x[b]) swap(int, x[c], x[b]);
    if (x[b] < x[a]) swap(int, x[b], x[a]);
    return b;
}

void quick(int a[], int left, int right){
    quick_count++;
    int pl = left;
    int pr = right;
    int m = sort3elem(a, pl, (pl+pr) / 2, pr);
    int x = a[m];

    swap(int, a[m], a[right - 1]);
    pl++;
    pr -= 2;

        do {
        while (a[pl] < x) pl++;
        while (a[pr] > x) pr--;

        if (pl <= pr) {
            swap(int, a[pl], a[pr]);
            pl++;
            pr--;
        }

        // 左側でピポットより大きな要素と右側でピポットより小さな要素をスワップ

    } while (pl <= pr);

    if (left < pr)  quick(a, left, pr); 
    if (pl < right) quick(a, pl, right);
}

int main(void){
    int nx;

    printf("quicksort\n");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; i++){
        printf("x[%d] : ", i);
        printf("\n");
        scanf("%d", &x[i]);
    }

    quick(x, 0, nx-1);

    printf("sorted!\n");
    for (int i = 0; i < nx; i++){
        printf("%d ", x[i]);
    }
    printf("\n%d\n%d\n%d\n", quick_count, sort3elem_count, swap_count);

    free(x);
    return 0;
}