#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    int e[n][n];
    int D[n];   // -1 未到達 1 visited 0 unvisited
    int S[n];
    int sin;
    int i, j, k;
    scanf("%d", &sin);
    int s = sin - 1;


    for (int i = 0; i < n; i++){
        D[i] = -1;
        int dummy;
        scanf("%d", &dummy);
        for (int j = 0; j < n; j++){
            scanf("%d", &e[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        D[i] = -1;
        S[i] = 0;
    }

    D[s] = 0;

    for (i = 0; i < n; i++) {
        
        int min_dist = -1; 
        k = -1;

        for (int v = 0; v < n; v++) {
            if (S[v] == 0 && D[v] != -1) {
                if (min_dist == -1 || D[v] < min_dist) {
                    min_dist = D[v];
                    k = v;
                }
            }
        }

        if (k == -1) {
            break;
        }

        S[k] = 1;

        for (j = 0; j < n; j++) {
            if (S[j] == 0 && e[k][j] != 0) {
                
                int new_dist = D[k] + e[k][j];

                if (D[j] == -1 || new_dist < D[j]) { //よりよい
                    D[j] = new_dist;
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d %d\n", i+1, D[i]);
    }
    
    return 0;
}