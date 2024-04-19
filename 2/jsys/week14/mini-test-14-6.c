#include <stdio.h>

int main(void){
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);

	int matrixA[n][m];
	//Ainput
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			scanf("%d", &matrixA[i][j]);
		}
	}
	
	int k;
	scanf("%d", &k);
	for (int i=0; i<m; i++){
		printf("%d ", matrixA[k-1][i]);
	}

	printf("\n");
	return 0;
}

