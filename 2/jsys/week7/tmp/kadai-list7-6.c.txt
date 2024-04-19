#include <stdio.h>

int main(void){
	int point;

	printf("点数：");
	scanf("%d", &point);

	if (point < 0 || point > 100){
		puts("不正な点数です。");
	} else if (point <= 59){
		puts("不可");
	} else if (point <= 69){
		puts("可");
	} else if (point <= 79){
		puts("良");
	} else {
		puts("優");
	} 
	return 0;
}
