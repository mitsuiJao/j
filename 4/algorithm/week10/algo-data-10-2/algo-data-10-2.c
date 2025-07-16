#include <stdlib.h>
#include <stdio.h>

void swap(int a[], int from, int to){
    int tmp = a[to];
    a[to] = a[from];
    a[from] = tmp;
}

void selection (int a[], int n, int *b){
    *b = 0;
    for (int i=0; i<n-1; i++){
        int min = i;
        for (int j=i+1; j<n; j++){
            (*b)++;
            if (a[j] < a[min]){
                min = j;
            }
        }
        swap(a, i, min);
    }
}

int main (void){
    int n, b;

    scanf("%d", &n);
    int *x = calloc(n, sizeof(int));
    if (x == NULL) {
        return 1;
    }

    for (int i=0; i<n; i++){
        scanf("%d", &x[i]);
    }

    selection(x, n, &b);

    for (int i=0; i<n; i++){
        printf("%d%c", x[i], (i == n - 1) ? '\0' : ' ');
    }
    printf("\n");
    printf("%d\n", b);
    
    free(x);
    return 0;
}
