#include <stdio.h>

int main(void){
	int n;
	printf("n?:");
	scanf("%d", &n);

	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			printf("%d", i*j);
		}
		printf("\n");
	}
}
