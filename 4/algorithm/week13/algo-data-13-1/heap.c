#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t; (*sc)++; } while (0)

static void downheap(int a[], int left, int right, int* dhc) {
    (*dhc)++;
    int temp = a[left];
    int parent;
    int child;

    for (parent = left; parent < (right + 1) / 2; parent = child) {
        child = parent * 2 + 1;
        if (child < right && a[child] < a[child + 1]) {
            child++;
        }
        if (temp >= a[child]) {
            break;
        }
        a[parent] = a[child];
    }
    a[parent] = temp;
}

void heapsort(int a[], int n, int* dhc, int* sc) {
    for (int i = (n - 1) / 2; i >= 0; i--) {
        downheap(a, i, n - 1, dhc);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(int, a[0], a[i]);
        downheap(a, 0, i - 1, dhc);
    }
}

int main(){
    int nx;
    int sc = 0;
    int dhc = 0;

    printf("heapsort\n");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; i++) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }

    heapsort(x, nx, &dhc, &sc);

    printf("\nsorted!\n");
    for (int i = 0; i < nx; i++) {
        printf("%d ", x[i]);
    }

    printf("\n%d\n%d\n", dhc, sc);

    free(x);
    return 0;
}
