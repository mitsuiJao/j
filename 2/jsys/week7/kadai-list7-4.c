#include <stdio.h>

int main(void){
	int a, b;

	puts("２つの整数を入力せよ。");
	printf("整数A：");  scanf("%d", &a);
	printf("整数B：");  scanf("%d", &b);

	if(a == b){
		puts("AとBは等しいです。");
	} else if (a > b){
		puts("AはBより大きいです。");
	} else {
		puts("AはBより小さいです。");
	}
	return 0;
}
