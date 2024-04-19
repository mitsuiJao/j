#include <stdio.h>

int main(void){
	typedef int GemList[10];
	GemList gems;

	gems[1] = 3;
	printf("%d\n", gems[1]);
	return 0;
}
