#include <stdio.h>

void dec2bin(unsigned int decimal){
	unsigned int buf[32];
	for (int i=0; i<32; i++){
		buf[i] = decimal%2;
		decimal /= 2;
	}
	for (int i=0; i<32; i++){
		printf("%d", buf[31-i]);
	}
	printf("\n");
}

int main(void){
	unsigned int a;
	unsigned int b;
	printf("非負の整数を2つ入力\n");
	printf("a: "); scanf("%d", &a); 
	printf("b: "); scanf("%d", &b);

	printf("a     = ");dec2bin(a);
	printf("b     = ");dec2bin(b);
	printf("a & b = ");dec2bin(a&b);
	printf("a | b = ");dec2bin(a|b);
	printf("a ^ b = ");dec2bin(a^b);
	printf("~a    = ");dec2bin(~a);
	printf("~b    = ");dec2bin(~b);

	return 0;
}
