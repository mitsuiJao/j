#include <stdio.h>

int main(void){
	int a;
	printf("変数aに格納する整数を入力してください: ");
	scanf("%d", &a);
	printf("変数aの値は%d, アドレスは%pです\n", a, &a);

	printf("ポインタPにaのアドレスを格納します\n");
	int* P = &a;
	printf("ポインタPのアドレスは%p, 値は%p, *Pの値は%dです\n\n", &P, P, *P);

	int b;
	printf("変数bに格納する整数を入力してください: ");
	scanf("%d", &b);
	printf("変数bの値は%d, アドレスは%pです\n", b, &b);

	printf("ポインタP先のアドレスに整数bの値を格納します\n");
	*P = b;	
	printf("ポインタPのアドレスは%p, 値は%p, *Pの値は%d,\n変数aの値は%d, 変数bの値は%dになりました\n", &P, P, *P, a, b);


	return 0;
}
