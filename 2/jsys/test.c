#include <stdio.h>

int main(void){
	int n;
	scanf("%d", &n);

	int A[n][n], B[n][n], sum[n][n];
	//a
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &A[i][j]);
		}
	}

	//b	
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &B[i][j]);
		}
	}

	//sum
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			sum[i][j] = A[i][j] + B[i][j];	
		}
	}

	//out
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			printf("%d ", sum[i][j]);	
		}
		printf("\n");
	}

	return 0;
}
