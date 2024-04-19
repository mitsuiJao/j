#include <stdio.h>

int main(void){
	int n;
	scanf("%d", &n);

	int matrixA[n][n], matrixB[n][n], sum[n][n];
	//Ainput
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &matrixA[i][j]);
		}
	}

	//Binput
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &matrixB[i][j]);
		}
	}

	//sum
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			sum[i][j] = matrixA[i][j] + matrixB[i][j];
		}
	}

	//output
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			printf("%d ", sum[i][j]);	
		}
		printf("\n");
	}

	return 0;

}
