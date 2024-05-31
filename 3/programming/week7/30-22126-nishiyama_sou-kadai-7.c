#include <stdio.h>

typedef struct{
	int a;
	int b;
}Hoge;

Hoge exchangefunc(Hoge s){
	//printf("%d,%d", s.a, s.b);
	Hoge exchanged;
	exchanged.a = s.b;
	exchanged.b = s.a;
	return exchanged; 
}

int main(void){
	Hoge any= {1, 100};
	printf("before: %d, %d \n", any.a, any.b);
	any = exchangefunc(any);
	printf("after:  %d, %d \n", any.a, any.b);
	return 0;
}
