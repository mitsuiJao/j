#include <stdio.h>

int main(void){
/*
	int n[3];
	for (int i=0; i<3; i++){
		scanf("%d", &n[i]);	
	}
	for (int i=0; i<3; i++){
		printf("%d", n[i]);
	}
*/
	
	int l[2][3] = {{0,1},{2,3},{3,4}};
	printf("%d", l[0][1]);

	return 0;
}
