#include <stdio.h>
int main(void){
	int n;
	printf("整数を入力せよ：\n");
	scanf("%d",&n);
	if (n%10){
		puts("その数は10の倍数ではありません。");
	} 
	return 0;
}
