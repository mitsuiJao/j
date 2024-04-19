#include <stdio.h>

int main(void){
	int n;
	scanf("%d", &n);
	int m;
	scanf("%d", &m);


	int A[n][m];
	//a
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			scanf("%d", &A[i][j]);
		}
	}

	int k;
	scanf("%d", &k);

	for (int i=0; i<m; i++){
		printf("%d ", A[k-1][i]);	
	}

	printf("\n");
	return 0;
}
