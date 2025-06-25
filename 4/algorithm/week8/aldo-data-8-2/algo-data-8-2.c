#include <stdio.h>
#include "HashList.h"

int main(void){
	HashLish hash;
	Initialize(&hash, 10000);
	Bucket *temp;
	int op = 1;
	int v, result;

	while (op != 0){
		scanf("%d", &op);
		if (op == 1){
			scanf("%d", &v);
			retult = Add(&hash, v);
			if (result) {
				printf("error Add func");
				break;
			}
		}
		else if (op == 2){
			scanf("%d", &v);
			result = Remove(&hash, v);
			if (result == 1){
				printf("Not found");
				break;
			}
		}
		else if (op == 3){
			scanf("%d", &v);
			temp = Search(&hash, v);
			if (temp == NULL){
				printf("Not fount");
			} else {
				printf("%d", temp->data);
			}
		}
		else if (op == 4){
			Clear(&hash);
		}
		else if (op == 5){
			Dump(&hash);
		}
	}

	Terminate(&hash);
	return 0;
}
