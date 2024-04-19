#include <stdio.h>

int main(void){
	int a[] = {1, 3, 7, 10, 15, 3, 4, 8, 10, 15};
	int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 10, 10};
	for (int i=0; i<10; i++){
		printf("%d\n", a[i]+b[i]);
	}
	return 0;
}
