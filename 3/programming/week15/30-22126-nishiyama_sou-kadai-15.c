#include <stdio.h>

int main(int u, char** v){
	//u-1
	//"%s/"
	printf("コマンドラインから入力された文字列の数は%dで", u-1);
	for(int i=1; i<u; i++){
		printf("%s/", v[i]);
	}
	printf("\n");

	int num, re;
	printf("整数値を入力: "); scanf("%d", &num);

	re = -1* num;
	printf("正負を入れ替えた値: %d\n", re);

	re = num%10;
	printf("1の位の数: %d\n", re);
	
	int temp = num;
	if(temp<0){temp*=-1;}re=0;while(1){if(temp<10){re++;break;}temp/=10;re++;}
	printf("桁数: %d\n", re);

	return 0;
}
