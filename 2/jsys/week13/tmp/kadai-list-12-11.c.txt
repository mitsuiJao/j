#include <stdio.h>

typedef char String[1024];

int main(void){
	int age= 29;
	String name = "かいとう";
	printf("私の名前は%d歳の%sです。\n", age, name);
	return 0;
}
