#include <stdio.h>

int main(void){
	int count;
	int v[5][10] = {{0, 1, 0, 1, 1, 1, 0, 0, 1, 1},
{0, 1, 0, 1, 1, 1, 0, 0, 1, 1},
{0, 1, 1, 1, 1, 1, 0, 1, 1, 1},
{1, 1, 0, 1, 0, 1, 0, 0, 1, 1},
{0, 1, 0, 1, 1, 1, 0, 1, 1, 0}};

	for (int i=0; i<5; i++){
		count = 0;
		for (int j=0; j<10; j++){
			if (v[i][j] == 1){
				count++;
			}
		} 
		printf("1 = %d\n", count);
	}
	return 0;
}
