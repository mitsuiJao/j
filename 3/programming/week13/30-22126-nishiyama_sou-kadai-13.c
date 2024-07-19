#include <stdio.h>

int main(void){
	char str1[11];

	printf("配列str1に格納する文字列を入力してください．");
	scanf("%s", str1);
	printf("配列str1に格納した文字列の各文字の直前に「/」を入れて表示します．");
	for (int i=0; i<11; i++){
		if (str1[i] != '\0'){
			printf("/%c", str1[i]);
		} else {
			break;
		}
	}
	printf("\n");

	printf("配列str1に格納した文字列をポインタstr2で扱うため，\n配列str1の先頭要素のアドレスをポインタstr2に代入します．\n");
	char* str2 = str1;
	int i = 0;
	printf("配列str1に格納した文字列の各文字の前後に「+」を入れて表示します．");
	while (str2[i] != '\0'){
		printf("+%c", str2[i]);
		i += 1;
	}
	printf("\n");

	printf("ポインタstr2が示す文字列をABCDEに変更します. \n");
	str2 = "ABCDE";
	printf("ポインタstr2が示す文字列が%sから%sに変更されました. \n", str1, str2);
	return 0;
}
