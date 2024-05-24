#include <stdio.h>

int main(void){
	typedef struct{
		char name[100];	
	}name;

	name Satou = {"satou"};
	name Fujiwara = {"fujiwara"};
	name Tanaka = {"tanaka"};
	name Ito = {"ito"};
	name Yamasaki = {"yamasaki"};

	name namelist[] = {Satou, Fujiwara, Tanaka, Ito	, Yamasaki};


	int number_arr[5][4][3][2];
	int numbering = 120;
	for (int o=0; o<5; o++){
		for (int p=0; p<4; p++){
			for (int q=0; q<3; q++){
				for (int r=0; r<2; r++){
					number_arr[o][p][q][r] = numbering--;
				}
			}
		}
	}
	for (int o=0; o<5; o++){
		for (int p=0; p<4; p++){
			for (int q=0; q<3; q++){
				for (int r=0; r<2; r++){
					printf("[%d][%d][%d][%d]:%d\n", o, p, q, r, number_arr[o][p][q][r]);
				}
			}
		}
	}
	return 0;
}
