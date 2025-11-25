#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int* v = calloc(n, sizeof(int));
    int** g = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) {
        g[i] = (int*)calloc(n, sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j]) {
                v[i]++;
            }
        }
    }

    int flg = 1;
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){ // 重複無し
            if (g[i][j] == 0){ // 経路がない、隣接していない
                if (v[i] + v[j] < n){
                    flg = 0;
                    break;
                }
            }
        }
        if (flg == 0){break;}
    }

    if (flg) {
        printf("Hamilton\n");
    } else {
        printf("possible Hamilton\n");
    }

    for (int i = 0; i < n; i++) {
        free(g[i]);
    }

    free(g); free(v);
    return 0;
}