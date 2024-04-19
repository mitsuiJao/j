#include <stdio.h>

int main(void){
	int sum = 0;
	int n;

	printf("nの値: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		sum += i;
	} 
	printf("1から%dまでの和は%dです。\n", n, sum);
	return 0;
}
