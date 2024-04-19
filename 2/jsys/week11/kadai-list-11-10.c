#include <stdio.h>

int main(void){
	int a[5] = {5,4,3,2,1};

	for (int i=0; i<5; i++){
		printf("a[%d] = %d\n", i, a[i]);
	}
	return 0;
}
