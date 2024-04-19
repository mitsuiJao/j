#include <stdio.h>

int main(void){
	int num;

	printf("整数を入力せよ：");
	scanf("%d",&num);

	if (num < 0){
		num = -num;
	}
	printf("絶対値は%dです。\n",num);
	return 0;
}
