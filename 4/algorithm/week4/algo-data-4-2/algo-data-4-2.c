#include <stdio.h>
#include <math.h>

int recursive(int *arr, int size) {
    if (size == 1){
        return arr[0];
    }
    int asize =(int)floor(size/2.0);
    int a[asize], b[size-asize];
    for (int i=0; i<=floor((size-1)/2); i++){

    }
}

int main(void){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    
}