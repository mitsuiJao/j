#include <stdio.h>

int Matrix_Chain(int *row, int *column, int n) {
    int M[n][n];
    for (int i = 0; i < n; i++) {
        M[i][i] = 0;
    }
    for (int w = 1; w < n; w++) {
        for (int i = 0; i < n-w; i++) {
            int j = i + w;
            M[i][j] = -1;
            for (int k = i; k < j; k++) {
                int m = M[i][k] + M[k+1][j] + row[i]*column[k]*column[j];
                if (m < M[i][j] || M[i][j] == -1) {
                    M[i][j] = m;
                }
            }
        }
    }
    return M[0][n-1];
}

int main(void) {
    int n;
    scanf("%d", &n);
    int row[n], column[n];
    for (int i = 0; i < n; i++){
        scanf("%d %d", &row[i], &column[i]);
    }

    int res = Matrix_Chain(row, column, n);
    printf("%d\n", res);

    return 0;
}