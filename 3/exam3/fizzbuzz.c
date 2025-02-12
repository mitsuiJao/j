#include <stdio.h>

typedef struct {
	int three;
	int seven;
	int eleven;
	int ts;
	int others;
} Container;

int main(void){
	int n;
	Container c = {0};
	printf("正の整数を入力:");
	scanf("%d", &n);
	
	for (int i=1; i<n+1; i++){
		Container flg = {0};
		if (i % 3 == 0){
			flg.three = 1;
		}
		if (i % 7 == 0){
			flg.seven = 1;
		}
		if (i % 11 == 0){
			flg.eleven = 1;
		}

		//------------------
		if (flg.three == 1 && flg.seven == 1){
			printf("TS ");
			c.ts++;
		}
		else if (flg.three == 1){
			printf("Three ");
			c.three++;
		}
		else if (flg.seven == 1){
			printf("Seven ");
			c.seven++;
		}
		else if (flg.eleven == 1){
			printf("Eleven ");
			c.eleven++;
		}
		else {
			printf("%d ", i);
			c.others++;
		}
	}

	printf("\nThree:%d Seven:%d Eleven:%d TS:%d Others:%d\n",
			c.three, c.seven, c.eleven, c.ts, c.others);
	return 0;
}
