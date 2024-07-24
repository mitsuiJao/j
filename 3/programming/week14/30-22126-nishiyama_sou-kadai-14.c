#include <stdio.h>
#include <string.h>

int main(int argc, char** argv){
	if (argc == 1){
		printf("英数字のコマンドライン引数を入力してもう一度実行してください。\n");
		return 0;
	}

	printf("argv1とargv2はそれぞれコマンドラインを通じて入力された文字列です\n\n");
	
	int argv1_len = strlen(*(argv+1));
	int argv2_len = strlen(*(argv+2));
	printf("argv1は'%s'で%d文字です\n", *(argv+1), argv1_len);
	printf("argv2は'%s'で%u文字です\n", *(argv+2), argv2_len);

	printf("\n");

	if (argv1_len >= 99){
		printf("argv1を100文字以内にしてください\n");
		return 0;
	}
	if (argv2_len >= 99){
		printf("argv2を100文字以内にしてください\n");
		return 0;
	}

	if (strcmp(*(argv+1), *(argv+2)) == 0){
		printf("argv1とargv2は等しいです\n");
	} else {
		printf("argv1とargv2は等しくないです\n");
	}

	printf("\n");

	char str1[100];
	strcpy(str1, *(argv+1));
	printf("argv1をstr1としてコピーしました\nstr1は'%s'です\n", str1);

	printf("\n");

	char str2[200];
	strcat(str1, *(argv+2));
	printf("str1とargv2を連結しました\nstr1は'%s'です", str1);

	return 0;
}
