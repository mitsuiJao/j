#include <stdio.h>

    typedef struct {
		int num;
		char na[128];
	}LIST;

    int func(LIST, LIST, LIST, LIST, LIST);
	//このプログラムの書き方（書き順）では必要な宣言

    int main(void)
    {
        LIST list[5]; //5つ分の情報を格納可能な構造体の配列を定義する

        for (int i = 0; i<=4; i++){
            printf("%d個目の情報：",i+1); scanf("%d %s", &list[i].num, list[i].na );
        }

        printf("比較した回数：%d\n", func(list[0], list[1], list[2], list[3], list[4]));

   		return 0; 
	}

    int func(LIST temp1, LIST temp2, LIST temp3, LIST temp4, LIST temp5)
    {
        int com = 0; //比較回数を格納するための変数
        LIST temp; //最も番号が小さい情報（番号と名称）を格納するための構造体変数

        LIST list[5] = {temp1, temp2, temp3, temp4, temp5};
        temp = list[0];
		for (int i=1; i<5; i++){
			if (list[i].num < temp.num){
				temp = list[i];
			}
			com++;
		}

        printf("最も番号が小さいのは%dの%s\n",temp.num,temp.na);

        return com;
    }

