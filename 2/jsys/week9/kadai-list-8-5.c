#include <stdio.h>

int main(void){
	int n;
	printf("整数を入力せよ：");
	scanf("%d", &n);

	switch (n%2){
		case 0:
			puts("その数は偶数です。");
			break;
		case 1:
			puts("その数は奇数です。");
			break;
	}
	return 0;
}
