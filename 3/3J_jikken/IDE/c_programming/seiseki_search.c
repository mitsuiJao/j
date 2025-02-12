#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    int db[n][6];
    for (int i=0; i<n; i++){
        scanf("%d %d %d %d %d %d", &db[i][0], &db[i][1], &db[i][2], &db[i][3], &db[i][4], &db[i][5]);
    }

    int search;
    scanf("%d", &search);
    for (int i=0; i<n; i++){
        if (db[i][0] == search){
            printf("%d %d %d %d %d %d\n", db[i][0], db[i][1], db[i][2], db[i][3], db[i][4], db[i][5]);
            return 0;
        }
    }
    printf("None\n");
    return 0;
}