#include <stdio.h>

int main(void){
	double a, b;

	puts("２つの実数を入力せよ。");
	printf("実数a:"); scanf("%lf", &a);
	printf("実数b:"); scanf("%lf", &b);

	printf("aの値はbの%f%%です。\n", a / b * 100);

	return 0;
}
