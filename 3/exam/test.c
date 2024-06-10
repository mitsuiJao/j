#include <stdio.h>

int main(void){
	int x[3][3][3];
	int a,b,c;
	int num = -13;

	int i=0;int j=0;int k=0;
	while (i < 3){
		while(j < 3){
			while(k < 3){
				x[i][j][k] = num;
				num++;
				k++;
			}
			j++;
			k = 0;
		}
		i++;
		j = 0;
	}
	printf("%d", x[0][0][3]);
	return 0;
}
