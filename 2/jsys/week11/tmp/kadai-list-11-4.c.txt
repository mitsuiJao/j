#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	srand((unsigned)time(NULL));
	enum {FIRE, WATER, WIND, EARTH};
	int gems[10];

	for (int i=0; i<10; i++){
		int gemType = rand() %4;
		gems[i] = gemType;
	}
	return 0;
}
