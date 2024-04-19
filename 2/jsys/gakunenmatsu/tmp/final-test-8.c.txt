#include <stdio.h>

int main(void){
	int n, w;
	printf("n?:");
	scanf("%d", &n);
	printf("w?:");
	scanf("%d", &w);

	for (int i=1; i<n; i++){
		if (i==w){
			break;
		} else {
			printf("%d ", i);
		}
	}

	return 0;
}
