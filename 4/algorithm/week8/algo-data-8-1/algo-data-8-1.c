#include <stdio.h>
#include <stdlib.h>

int main(void){
    int left, right, mid, n, k;
    
    printf("n?: "); scanf("%d", &n);
    int *v = calloc(n, sizeof(int));
    for (int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
    printf("k?: "); scanf("%d", &k);

    left = 0; right = n-1; mid = (left+right)/2;
    while (left < right) {
        if (v[mid] == k){
            printf("found %d %d\n", mid, v[mid]);
            free(v);
            return 0;
        }
        else if (v[mid] < k){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        mid = (left+right) / 2;
    }
    if (v[mid] == k){
        printf("found %d %d\n", mid, v[mid]);
    } else {
        printf("not found %d\n", k);
    }
    free(v);
    return 0;
}