#include <stdio.h>

int main(int u, char **v)
{
    printf("コマンドラインから入力された文字列の数は%dで", u - 1);
    for (int i = 1; i < u; i++)
    {
        printf("%s/", v[i]);
    }
    printf("\n");

    int num, re;
    printf("整数値を入力：");
    scanf("%d", &num);

    re = num * -1; // numの値の正負を入れ替えてreに格納
    printf("正負を入れ替えた値：%d\n", re);

    printf("１の位の数：%d\n", re);

    int tmp = num;
    if (tmp < 0)
        tmp *= -1;
    re = 0;
    while (1)
    {
        if (tmp < 10)
        {
            re++;
            break;
        }
        tmp /= 10;
        re++;
    } // numの値の桁数を計算してreslutに格納
    printf("桁数：%d\n", re);

    return 0;
}
