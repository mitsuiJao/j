#include <stdio.h>

void addition(int, int);
void subtraction(int, int);
void multiplication(int, int);
void division(int, int);
void surplus(int, int);

int main(void){
	int a, b, flg;
	scanf("%d", &a);
	scanf("%d", &b);
	printf("sum: 1, sub: 2, mul: 3, div: 4, surplus 5\n");
	scanf("%d", &flg);

	if (flg == 1){
		addition(a,b);
	}
	if (flg == 2){
		subtraction(a,b);
	}
	if (flg == 3){
		multiplication(a,b);
	}
	if (flg == 4){
		division(a,b);
	}
	if (flg == 5){
		surplus(a,b);
	}
	return 0;
}

void addition(int a, int b){
	printf("%d\n", a+b);
}
void subtraction(int a, int b){
	printf("%d\n", a-b);
}
void multiplication(int a, int b){
	printf("%d\n", a*b);
}
void division(int a, int b){
	printf("%d\n", a/b);
}
void surplus(int a, int b){
	printf("%d\n", a%b);
}
