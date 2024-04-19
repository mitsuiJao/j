#include <stdio.h>
#include <stdlib.h>

typedef char String[1024];

int main(void){
	String age = "29";
	int n = atoi(age);
	printf("あなたは来年%d歳になります。\n", n+1);
	return 0;
}
