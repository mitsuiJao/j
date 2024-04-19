#include <stdio.h>

int main(void){
	int n;

	printf("整数値: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i += 2){
		printf("%d ", i);
	}
	putchar('\n');
	return 0;
}
