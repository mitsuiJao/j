#include <stdio.h>

int main(void){
	int no;

	printf("正の整数を入力せよ：");
	scanf("%d",&no);

	if (no >= 1){
		while (no >= 1){
			printf("%d",no--);
		}
		printf("\n");
	}
	return 0;
}
