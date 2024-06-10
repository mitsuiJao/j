#include <stdio.h>

struct xyz {
    char x[10];
    double y;
    int z;
};

int main(void)
{
    struct xyz abc = {"def", 1.1, 1};
    struct xyz def = {"abc", 2.2, 2};

    abc = def;

    printf("メンバの値：%s %lf %d", abc.x, abc.y, abc.z); //構造体変数abcの各メンバの値を表示したい

    return 0;
}
