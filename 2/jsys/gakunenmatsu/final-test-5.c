#include <stdio.h>

int main(void){
	int n, v;
	scanf("%d", &n);
	scanf("%d", &v);

	int array[n];
	for (int i=0; i<n; i++){
		scanf("%d", &array[i]);
	}


	array[n-1] += v;
	
	for (int i=1; i<n; i++){
		if (array[n-i] >= 10){
			array[n-i] = array[n-i] % 10;
			array[n-i-1] += 1;
		}
	}

	for (int i=0; i<n; i++){
		printf("%d", array[i]);
	}
	
	return 0;
}
