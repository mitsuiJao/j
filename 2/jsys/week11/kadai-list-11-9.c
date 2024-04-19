#include <stdio.h>

int main(void){
	int a[5];

	for (int i=0; i<5; i++){
		a[i] = 5-i;
	}
	for (int i=0; i<5; i++){
		printf("a[%d] = %d\n", i, a[i]);
	}
	return 0;
}
