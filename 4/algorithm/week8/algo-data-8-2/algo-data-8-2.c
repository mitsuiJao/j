#include <stdio.h>
#include "HashList.h"

int main(void){
	HashList hash;
	Initialize(&hash, 20);
	Bucket *temp;
	int op = 1;
	int v, result, opCounter;
	scanf("%d", &opCounter);

	for (int i=opCounter; i!=0; i--){
		scanf("%d", &op);
		if (op == 1){
			scanf("%d", &v);
			result = Add(&hash, v);
			if (result) {
				printf("error Add func\n");
			}
		}
		else if (op == 2){
			scanf("%d", &v);
			result = Remove(&hash, v);
			if (result == 1){
				printf("Not found\n");
			}
		}
		else if (op == 3){
			scanf("%d", &v);
			temp = Search(&hash, v);
			if (temp == NULL){
				printf("Not found\n");
			} else {
				printf("%d\n", temp->data);
			}
		}
		else if (op == 4){
			Clear(&hash);
		}
		else if (op == 5){
			Dump(&hash);
		}
		else if (op == 0){
			break;
		}
	}

	Terminate(&hash);
	return 0;
}
