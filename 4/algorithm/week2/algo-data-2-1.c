#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
	char n[10001];
	scanf("%s", n);

	int sum;

	for(int i=0; i<strlen(n); i++){
		sum += n[i] - '0';	
	}

	printf("%d\n", sum);
	if (sum % 3 == 0){
		printf("YES");
	} else {
		printf("NO");
	}
	printf("\n");
	return 0;
}
