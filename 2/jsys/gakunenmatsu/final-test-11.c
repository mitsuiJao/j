#include <stdio.h>

int main(void){
	int x;
	printf("x?:");
	scanf("%d", &x);
	int y;
	printf("y?:");
	scanf("%d", &y);

	if (x>0 && x%y == 0){
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}
