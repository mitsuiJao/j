#include <stdio.h>
#include <stdlib.h>

void dfs(int u, int n, int matrix[n][n], int C[n]){
    C[u] = 1;
    printf("%d ", u+1);
    for (int i = 0; i < n; i++){
        if (matrix[u][i] == 1 && C[i] == 0){
            dfs(i, n, matrix, C);
        }
    }
}

int main(void){
    int n;
    scanf("%d", &n);

    
    int matrix[n][n];
    int C[n];
    int S;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++){
        C[i] = 0;
    }

    scanf("%d", &S);

    dfs(S-1, n, matrix, C);

    printf("\n");

    return 0;
}