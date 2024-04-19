#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char String[1024];

int main(void){
	String answerNo;
	printf("かっこよくて最高な、C言語男子の名前は？\n");
	printf("１：ミナト　２：ミサキ　３：ツバサ　４：ミサエ\n");
	scanf("%s",answerNo);
	int n = atoi(answerNo);
	if (n == 2){
		printf("大正解！　見る目あるね！\n");
	} else {
		printf("残念\n");
	}
	return 0;
}
