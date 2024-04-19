#include <stdio.h>
int main(void){
	int a[10]={3,2,1,6,5,10,12,7,5,4};
	for (int i=0;i<10;i++){
		printf("%d ",a[9-i]);
	}
	printf("\n");
	return 0;
}
