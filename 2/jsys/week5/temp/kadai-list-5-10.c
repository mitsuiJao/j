#include <stdio.h>
int main(void){
	int no;
	
	printf("整数を入力してください:");
	scanf("%d",&no);

	printf("%dから7を減じると",no);
	printf("%dです。\n",no-7);

	return 0;
}
