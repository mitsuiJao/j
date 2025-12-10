#include <stdio.h>

int flg_a[8];
int flg_b[15];
int flg_c[15];
int pos[8];
int counter = 0;

void print(void){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (pos[i] == j) {
                printf("%d ", 1);
            } else {
                printf("%d ", 0);
            }
        }
        printf("\n");
    }
    printf("%d\n---------------\n", counter++);
}

void set(int i) {
    for (int j = 0; j < 8; j++){
        if (!flg_a[j] && !flg_b[i+j] && !flg_c[i-j+7]) {
            pos[i] = j;
            
            if (i == 7) {
                print();
            } else {
                flg_a[j] = 1;
                flg_b[i+j] = 1;
                flg_c[i-j+7] = 1;

                set(i+1);

                flg_a[j] = 0;
                flg_b[i+j] = 0;
                flg_c[i-j+7] = 0;
            }
        }
    }
}

int main(void) {
    for (int i = 0; i < 8; i++){
        flg_a[i] = 0;
    }
    for (int i = 0; i < 15; i++){
        flg_b[i] = flg_c[i] = 0;
    }
    set(0);
    return 0;
}