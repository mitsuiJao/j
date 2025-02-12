#include <stdio.h>

#define N 10

int main(void){
    int v[N] = {0};

    for (int i=0; i<N; i++){
        printf("v[%d]?: ", i);
        scanf("%d", &v[i]);
    }

    for (int i=0; i<N; i++){
        printf("v[%d] = %d\n", i, v[i]);
    }

    return 0;
}