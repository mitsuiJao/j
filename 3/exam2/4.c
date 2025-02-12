#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int i, num, sei = 0, fu = 0;
    int *z;

    printf("数値の数");
    scanf("%d", &num);
    printf("%d", num);

    z = (int *)malloc(num * 4);
    // 動的にメモリ領域を確保してその先頭のアドレスをポインタzに代入（確保する領域は必要最小限とすること，int型のサイズは4バイトとする）

    for (i = 1; i <= num; i++)
    {
        printf("%d個目の数値: ", i);
        scanf("%d", z[i - 1]);
    }

    for (i = 0; i < num; i++)
    {
        if (*(z + i) >= 0)
        {
            sei++;
        }
        else
        {
            fu++;
        }
        // 入力された数値から正の数と負の数を数える
    }

    printf("正の数は%d個，負の数は%d個です．\n", sei, fu);

    printf("なお，動的に確保したメモリ領域の先頭のアドレスは%pでした．\n", z);

    // 動的に確保したメモリ領域の全てを20で埋める
    for (i = 0; i < num; i++)
    {
        *(z + i) = 20;
    }

    free(z); // 動的に確保したメモリ領域を明示的に解放する

    return 0;
}
