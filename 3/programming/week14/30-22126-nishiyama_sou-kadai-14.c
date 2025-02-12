#include <stdio.h>
#include <string.h>

int main(int argc, char** argv){
	if (argc == 1){
<<<<<<< HEAD
<<<<<<< HEAD
		printf("コマンドライン引数を入力してもう一度実行してください。\n");
		return 0;
	}
	

	char str1[100];
	strcpy(str1, *(argv+1));
	printf("str1は'%s'で%u文字です", strlen(str1));

	char str2[100];
	strcpy(str2, *(argv+2));
	printf("str2は'%s'で%u文字です", strlen(str1));

	if (strcmp(str1, str2) == 0){
		printf("str1とstr2は等しいです");
	} else {
		printf("str1とstr2は等しくないです");
	}

	char str3[200];
	strcpy(str3, str1);
	printf("str1をstr3としてコピーしました。\nstr3は'%s'", str3);

	strcat(str3, str2);
	printf("str3とstr2を連結しました。\nstr3は'%s'", str3);
=======
=======
>>>>>>> 78e714058c8d10301ea92d42ac6e158154ebf6c0
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
<<<<<<< HEAD
>>>>>>> 78e714058c8d10301ea92d42ac6e158154ebf6c0
=======
>>>>>>> 78e714058c8d10301ea92d42ac6e158154ebf6c0

	return 0;
}
