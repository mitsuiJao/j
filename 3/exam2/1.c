#include <stdio.h>
#include <string.h>

int func(char *x)
{
    int i = 0;

    while (*x)
    {
        i++;
        x++;
    }

    return i;
}

int main(void)
{
    char str1[3][3] = {"12", "34", "56"};
    char *str2[3] = {"a", "bc", "dcf"};

    printf("%s / %s / %d%d\n", str1[2], *str2, func(str1[0]), func(*(str2 + 2)));

    int num;
    char list[256];

    printf("整数値と255文字以内の文字列を入力：");
    scanf("%d %s", &num, list);

    return 0;
}
// int main(void)
// {
//         【1】 //配列の配列str1を定義して 12 ，34 ，56 の3つの文字列をこの順に格納する
//         【2】 //ポインタ配列str2を定義して a ，bc ，dcf の1つの文字と2つの文字列をこの順に格納する
//         //【1】と【2】ともに定義する要素数は必要最小限とすること

//         printf("%s / %s / %d%d\n", str1[2], *str2, func(str1[0]), func(*(str2+2));

//         int num;
//         char list[256];

//         printf("整数値と255文字以内の文字列を入力："); scanf("%d %s", &num, list);

//         return 0;
// }
