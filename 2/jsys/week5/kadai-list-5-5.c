#include <stdio.h>
int main(void){
	int tax=110;
	int fax = 50000;
	printf("50000円から40000円似値下げします\n");
	tax = 40000;
	printf("faxの新価格(税込み)：%d円\n",fax*tax/100);
	return 0;
}
