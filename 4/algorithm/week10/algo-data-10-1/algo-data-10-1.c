#include <stdio.h>
#include <stdlib.h>

void insertion(int a[], int n, int *b) {
    *b = 0;
    for (int i=1; i<n; i++) { 
        int tmp = a[i];
        int j;
        for (j = i; j > 0 && a[j-1] > tmp; j--){
            a[j] = a[j-1];
            (*b)++;
        }
        a[j] = tmp;
    }
}

int main(void){
    int n, counter;
    scanf("%d", &n);
    int *x = calloc(n, sizeof(int));

    for (int i=0; i<n; i++){
        scanf("%d", &x[i]);
    }

    insertion(x, n, &counter);

    for (int i=0; i<n; i++){
        printf("%d ", x[i]);
    }
    printf("\n%d\n", counter);
    free(x);
    return 0;
}