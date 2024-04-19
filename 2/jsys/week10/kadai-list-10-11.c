#include <stdio.h>

int main(void){
	int height;

	puts("正方形を作ります。");
	printf("段数: ");
	scanf("%d", &height);

	for (int i = 1; i <= height; i++){
		for (int j = 1; j <= height; j++){
			putchar('*');
		}
		putchar('\n');
	}
	return 0;
}
