#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const size_t sz = sizeof(int);

int v_sum(int *v, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
    }
    return sum;
}

void split(int *v, int n, int *a, int *b){
    int p = n / 2;
    for (int i = 0; i < p; i++) {
        a[i] = v[i];
    }
    for (int i = 0; i < n - p; i++) {
        b[i] = v[i + p];
    }
}

int elem(int n, int ind){
    if (n % 2 == 0) {
        return n / 2;
    } else {
        if (ind == 0) {
            return n / 2;
        } else {
            return n / 2 + 1;
        }
    }
}

void nRight(int **v, int *v2, int *n, int n2) {
    free(*v);
    *v = malloc(n2 * sz);
    memmove(*v, v2, n2 * sz);
    *n = n2;
}

void nLeft(int **v, int *v1, int *n, int n1) {
    free(*v);
    *v = malloc(n1 * sz);
    memmove(*v, v1, n1 * sz);
    *n = n1;
}

void afree(int *v1, int *v2) {
    free(v1);
    v1 = NULL;
    free(v2);
    v2 = NULL;
}

int main(void) {
    int *v, *v1, *v2;
    int n, n1, n2, r, arcn;

    scanf("%d", &n);
    arcn = n;

    v = malloc(n * sz);
    int arcv[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        arcv[i] = v[i];
    }

    printf("%d\n", v_sum(v, n));

    while (n != 1) {
        n1 = elem(n, 0);
        n2 = elem(n, 1);
        v1 = malloc(n1 * sz);
        v2 = malloc(n2 * sz);

        split(v, n, v1, v2);

        if (v_sum(v1, n1) % 100 == 0) {
            r = v_sum(v2, n2);
            printf("%d\n", r);
            nRight(&v, v2, &n, n2);
            afree(v1, v2);
        } else {
            r = v_sum(v1, n1);
            printf("%d\n", r);
            nLeft(&v, v1, &n, n1);
            afree(v1, v2);
        }
    }

    for (int i = 0; i < arcn; i++) {
        if (r == arcv[i]) {
            printf("%d\n", i + 1);
        }
    }
    return 0;
}
