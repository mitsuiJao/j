#include <stdio.h>

int main(void){
	const int TAX = 110;
	int fax = 50000;
	printf("50000円から40000円に値下げします\n");
	TAX = 40000;
	printf("FAXの新価格（税込）：%d\n",fax*TAX/100);
	return 0;
	}
