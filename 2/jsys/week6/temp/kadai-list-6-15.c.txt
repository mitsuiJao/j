#include <stdio.h>

int main(void){
	int no;

	printf("正の整数を入力せよ");
	scanf("%d",&no);

	if (no >= 0){
		while (no >= 0){
			printf("%d",no);
			no--; //これは後置です！
		}
		printf("\n");
	}
	return 0;
}
