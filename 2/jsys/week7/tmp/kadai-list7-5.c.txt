#include <stdio.h>

int main(void){
	int n1, n2, n3;

	puts("３つの整数を入力せよ。");
	printf("整数１：");		scanf("%d", &n1);
	printf("整数２：");		scanf("%d", &n2);
	printf("整数３：");		scanf("%d", &n3);

	int min = n1;
	if (n2 < min){
		min = n2;
	}
	if (n3 < min){
		min = n3;
	}
	printf("最小値は%dです。\n", min);
	return 0;
}
