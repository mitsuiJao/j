#include <stdio.h>

int sum(int i, int n){
	int tmp = 0;
	for (i; i<n+1; i++){
		tmp += i;
	}
	return tmp;
}

int mult(int i, int n){
	int tmp = 1;
	for (i; i<n+1; i++){
		tmp *= i;
	}
	return tmp;
}

int main(void){
	int i, n;
	printf("1つ目の自然数を入力："); 
	scanf("%d", &i);
	printf("2つ目の自然数を入力："); 
	scanf("%d", &n);
	

	if (i < 0){
		printf("自然数(0より大きな整数)以外が入力されました！\n");
		return 0;
	}
	if (i == n){
		printf("同じ自然数が入力されました！\n");
		return 0;
	}

	int a = sum(i, n);
	int b = mult(i, n);

	printf("%dから%dまでの全整数の和は%d\n", i, n, a);
	printf("%dから%dまでの全整数の積は%d\n", i, n, b);
	
	return 0;
}


