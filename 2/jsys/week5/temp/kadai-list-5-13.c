#include <stdio.h>
int main(void){
	int a,b,h;

	puts("台形の面積を求めます。");
	printf("上辺:"); scanf("%d", &a);
	printf("下辺:"); scanf("%d", &b);
	printf("高さ:"); scanf("%d", &h);
	
	printf("面積は%fです。\n",(a + b) *h /2.0);

	return 0;

}
