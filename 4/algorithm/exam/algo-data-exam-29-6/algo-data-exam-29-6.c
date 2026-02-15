#include <stdio.h>

int int_length(int n) {
// 整数の文字列長さ
    if (n == 0) return 1;
    int digits = 0;
    while (n != 0) {
        n /= 10;
        digits++;
    }
    return digits;
}

int main(void){
    int mode;
    int n;
    scanf("%d %d", &mode, &n);

    int total = 0;

    if (mode == 1){
        char x[n];
        for (int i = 0; i < n; i++){
            scanf(" %c", &x[i]);
        }
        
        for (int i = 0; i < n; i++) {
            int count = 1;
            while (i < n - 1 && x[i] == x[i + 1]) {
                // n-1且つさっきと同じ文字
                count++;
                i++;
            }
        
            printf("%c%d", x[i], count);
            // 1文字と桁数
            total += 1 + int_length(count);
        }

        printf("\n%d", total);
        printf("\nM/L = %d / %d = %.3f", total, n, (float)total / n);
    } else if (mode == 0){
        char x[n];
        for (int i = 0; i < n; i++){
            scanf("%c", &x[i]);
        }
        
        for (int i = 0; i < n; i++) {
            int count = 1;
            while (i < n - 1 && x[i] == x[i + 1]) {
                count++;
                i++;
            }
        
            printf("%c%d", x[i], count);
        }
    }
}