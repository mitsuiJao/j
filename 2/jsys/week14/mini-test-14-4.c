#include <stdio.h>

int main(void){
	int n, v;
	int array[n];
	
	scanf("%d", &n);
	scanf("%d", &v);
	for (int i=0; i<n; i++){
		scanf("%d", &array[i]);	
	}

	array[n-1] += v;
	for (int i=0; i<n-1; i++){
		if (array[n-i-1] > 9){
			array[n-i-1] = array[n-i-1] % 10;
			array[n-i-2] += 1;
		}
	}

	for (int i=0; i<n; i++){
		printf("%d", array[i]);
	}
	return 0;
}


