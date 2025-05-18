#include <stdio.h>
#include <math.h>

int count = 0;

int recursive(int *arr, int size) {
    if (size == 1){
        return arr[0];
    }
    int asize =(int)floor(size/2.0);
    int a[asize], b[size-asize];
    for (int i=0; i<asize; i++){
       a[i] = arr[i];
    }
    for (int i=0; i<size-asize; i++){
       b[i] = arr[i+asize];
    }

    int x = recursive(a, asize);
    int y = recursive(b, size-asize);
    
    count++;
    return x+y;
}

int main(void){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("%d\n", recursive(arr, n));
    printf("%d\n", count);

    return 0;
}