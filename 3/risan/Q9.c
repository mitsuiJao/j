// https://drken1215.hatenablog.com/entry/2023/05/20/200517
// https://www.momoyama-usagi.com/entry/math-risan13#i-5

#include <stdio.h>
#include <string.h>

void arrInit(int n, int visited[]) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
}

int isClosed(int at, int from, int n, int mtx[n][n], int visited[n]) {
    visited[at] = 1;

    for (int v = 0; v < n; v++) {
        if (mtx[at][v] != 0) {      // 今いるノードからすべての辺を確認
            if (visited[v] == 0) {  // 訪れたことがないノードなら検索する
                if (isClosed(v, at, n, mtx, visited)) {
                    return 1;  // 再帰処理で返り値が伝播する
                }
            } else if (v != from) {  // 訪れたことがある且つ直前のノードではない
                return 1;
            }
        }
    }
    return 0;
}

void dfs(int at, int n, int mtx[n][n], int visited[]) {
    visited[at] = 1;

    for (int i = 0; i < n; i++) {
        if (mtx[at][i] != 0 && visited[i] == 0) {
            dfs(i, n, mtx, visited);
        }
    }
}

int concatenation(int n, int mtx[n][n]) {
    int visited[n];
    arrInit(n, visited);

    dfs(0, n, mtx, visited);

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            return 0;
        }
    }
    return 1;
}

void getWeight(int n, int mtx[n][n], int weights[]) {
    int index = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            weights[index] = mtx[i][j];
            index++;
        }
    }
}

void bubbleSord(int len, int weights[]) {
    int tmp;
    for (int i = 0; i < len - 1; i++) {
        for (int j = len - 1; j > i; j--) {
            int a = weights[j - 1];
            int b = weights[j];
            // 0を最後に
            if ((a != 0 && b != 0 && a > b) || (a == 0 && b != 0)) {
                tmp = weights[j];
                weights[j] = weights[j - 1];
                weights[j - 1] = tmp;
            }
        }
    }
}

void printMatrix(int n, int mtx[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mtx[i][j]);
        }
        printf("\n");
    }
}

int edgeCount(int n, int len, int mtx[n][n]) {
    int arr[len];
    arrInit(len, arr);
    getWeight(n, mtx, arr);
    bubbleSord(len, arr);
    int counter = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] != 0) {
            counter++;
        } else {
            return counter;
        }
    }
}

int main(void) {
    int n;
    scanf("%d", &n);

    int graph[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // int tf = isClosed(0, -1, n, tree, visited);

    int maxNode = ((n - 1) * n) / 2;
    int weights[maxNode];
    getWeight(n, graph, weights);
    bubbleSord(maxNode, weights);

    int ans[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = 0;
        }
    }

    //////////////////////////////////////
    int count = 0;
    int visited[n];
    for (int ind = 0; ind < maxNode; ind++) {  // weights
        if (edgeCount(n, maxNode, ans) == n - 1) {
            break;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {  // graph
                if (graph[i][j] == weights[ind] && weights[ind] != 0) {
                    // printf("%d, %d\n", i, j);
                    ans[i][j] = 1;
                    ans[j][i] = 1;

                    arrInit(n, visited);

                    if (isClosed(0, -1, n, ans, visited)) {
                        ans[i][j] = 0;
                        ans[j][i] = 0;
                    } else {
                        graph[i][j] = 0;
                        graph[j][i] = 0;
                        count++;
                        // printMatrix(n, ans);
                        break;
                    }
                }
            }
        }
        arrInit(n, visited);
    }

    // printf("%d\n", edgeCount(n, maxNode, graph));

    ans[7][3] = 1;
    ans[3][7] = 1;

    printMatrix(n, ans);
    int a[n];
    arrInit(n, a);
    printf("%d\n", concatenation(n, ans));
    printf("\n");
    return 0;
}