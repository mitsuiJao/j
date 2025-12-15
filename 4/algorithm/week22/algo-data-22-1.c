#include <stdio.h>

#define N 10
#define CAPACITY 50

typedef struct {
    int value;
    int history; // ビットマスク
} Cell;

int main() {
    int W[N + 1]; 
    int V[N + 1]; 
    
    Cell T[N + 1][CAPACITY + 1]; 

    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &V[i], &W[i]);
    }

    //init
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= CAPACITY; j++) {
            T[i][j].value = 0;
            T[i][j].history = 0;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= CAPACITY; j++) {
            if (j >= W[i]) {
                int v1 = T[i - 1][j - W[i]].value;
                int v2 = T[i - 1][j].value;
                
                if (v1 + V[i] > v2) {
                    T[i][j].value = v1 + V[i];
                    T[i][j].history = T[i - 1][j - W[i]].history | (1 << (i - 1)); 
                } else {
                    T[i][j] = T[i - 1][j];
                }
            } else {
                T[i][j] = T[i - 1][j];
            }
        }
    }

    printf("%d\n", T[N][CAPACITY].value);

    return 0;
}