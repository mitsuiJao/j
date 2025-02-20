#include <stdio.h>
#include <time.h>

int fibonacci_recursive(int n) {
    if (n < 2) {
        return n;
    } else {
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
    }
}

int fibonaacci_DP(int n, int memo[]) {
    if (n < 2) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = fibonaacci_DP(n - 1, memo) + fibonaacci_DP(n - 2, memo);
    return memo[n];
}

int fibonacci_arr(int n) {
    int result[n];
    result[0] = 0;
    result[1] = 1;
    for (int i = 2; i <= n; i++) {
        result[i] = result[i - 1] + result[i - 2];
    }
    return result[n];
}

int main(void) {
    int n;
    int memo[n + 1];
    while (1) {
        scanf("%d", &n);
        printf("recursive: %d\n", fibonacci_recursive(n));
        for (int i = 0; i <= n; i++) {
            memo[i] = -1;
        }
        printf("DP: %d\n", fibonaacci_DP(n, memo));
        printf("array: %d\n", fibonacci_arr(n));
    }
    return 0;
}