#include <stdio.h>

int main(void) {
    int n = 10000; // nを10000に設定
    printf("%d\n", n);

    for (int i = 0; i < n; i++) {
        printf("100\n");  // 100ごとに改行
    }

    return 0;
}

