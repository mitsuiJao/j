#include <stdio.h>
#include <stdlib.h>

static int *buff;

static void __mergesort(int a[], int left, int right, int *counter){
    (*counter)++;
    if (left < right){
    int center = (left + right) / 2;
        int p = 0;
        int i;
        int j = 0;
        int k = left;
        
        __mergesort(a, left, center, counter);
        __mergesort(a, center + 1, right, counter);

        for (i = left; i <= center; i++){
            buff[p++] = a[i];
        }
        
        while (i <= right && j < p){
            if (buff[j] <= a[i]){
                a[k++] = buff[j++];
            } else {
                a[k++] = a[i++];
            }
        }

        while (j < p){
            a[k++] = buff[j++];
        }
    }
}

int mergesort(int a[], int n){
    int counter = 0;
    if ((buff = calloc(n, sizeof(int))) == NULL){
        return -1;
    }
    __mergesort(a, 0, n-1, &counter);
    free(buff);
    return counter;
}

int main(void){
    int nx;
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));

    for (int i=0; i<nx; i++){
        scanf("%d", &x[i]);
    }

    int counter = mergesort(x, nx);

    for (int i=0; i<nx; i++){
        printf("%d ",x[i]);
    }
    printf("\n%d\n", counter);
    free(x);

    return 0;
}