#include <stdio.h>
#include <stdlib.h>

void dfs(int u, int n, int matrix[n][n], int C[n]){
    C[u] = 1;
    for (int i = 0; i < n; i++){
        if (matrix[u][i] == 1 && C[i] == 0){
            dfs(i, n, matrix, C);
        }
    }
}

int main(void){
    int n;
    int S;
    scanf("%d", &n);
    scanf("%d", &S);

    
    int matrix[n][n];
    int C[n];

    // init
    for (int i = 0; i < n; i++) {
        C[i] = 0;
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++){
        int dummy;
        scanf("%d", &dummy);
        for (int j = 0; j < n; j++){
            int val;
            scanf("%d", &val);
            if (val == 1){
                matrix[i][j] = 1;
                matrix[j][i] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++){
        C[i] = 0;
    }


    dfs(S-1, n, matrix, C);

    int result = 1;
    for (int i=0; i<n; i++){
        if (C[i] == 0){
            result = 0;
            break;
        }
    }

    if (result == 1){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

    return 0;
}