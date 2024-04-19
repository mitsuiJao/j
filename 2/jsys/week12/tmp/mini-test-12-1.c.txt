#include <stdio.h>

int main(void){
	int v[] = {1, 3, 7, 10, 15, 3, 4, 8, 10, 15, 30, 9, 11, 18, 19};
	int tmp = 0;
	for (int i=0; i<15; i++){
		tmp += v[i];
	}
	printf("%d\n", tmp);
	return 0;
}
