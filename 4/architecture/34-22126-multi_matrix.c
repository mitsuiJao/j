#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define SIZE 500  // 行列のサイズ

typedef struct {
    int (*A)[SIZE];
    int (*B)[SIZE];
    int (*C)[SIZE];
    int start;
    int end;
} ThreadArgs;

void initialize_matrices(int A[SIZE][SIZE], int B[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            A[i][j] = rand() % 10;  // 0〜9のランダムな値
            B[i][j] = rand() % 10;
        }
    }
}

void multiply_partial(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE],
                      int start_row, int end_row) {
    for (int i = start_row; i < end_row; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiply_matrices_multi(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
    pid_t pid1, pid2;  // プロセスIDを格納する変数

    // 行列計算を3分割するための値の生成
    int mid1 = SIZE / 3;
    int mid2 = 2 * SIZE / 3;

    pid1 = fork();  // 最初の子プロセスを作成

    if (pid1 < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid1 == 0) {
        // 子プロセス1: 行列Cの前半部分を計算
        multiply_partial(A, B, C, 0, mid1);
        exit(0);  // 子プロセス1終了
    }

    pid2 = fork();  // 2つ目の子プロセスを作成

    if (pid2 < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid2 == 0) {
        // 子プロセス2: 行列Cの中間部分を計算
        multiply_partial(A, B, C, mid1, mid2);
        exit(0);  // 子プロセス2終了
    }

    // 親プロセス: 行列Cの後半部分を計算
    multiply_partial(A, B, C, mid2, SIZE);

    // 子プロセスの終了を待つ
    wait(NULL);  // 子プロセス1を待つ
    wait(NULL);  // 子プロセス1を待つ
}

// I/O interface convert
void* thread_wrapper(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;

    multiply_partial(args->A, args->B, args->C, args->start, args->end);

    pthread_exit(NULL);
}

void multiply_matrices_thread(int A[SIZE][SIZE], int B[SIZE][SIZE],
                              int C[SIZE][SIZE]) {
    pthread_t tid1, tid2;

    int mid1 = SIZE / 3;
    int mid2 = 2 * SIZE / 3;

    ThreadArgs tid1_args = {A, B, C, 0, mid1};
    ThreadArgs tid2_args = {A, B, C, mid1, mid2};

    if (pthread_create(&tid1, NULL, thread_wrapper, (void*)&tid1_args) != 0) {
        perror("pthread_create failed");  // エラー処理
        exit(1);
    }
    if (pthread_create(&tid2, NULL, thread_wrapper, (void*)&tid2_args) != 0) {
        perror("pthread_create failed");  // エラー処理
        exit(1);
    }

    multiply_partial(A, B, C, mid2, SIZE);

    if (pthread_join(tid1, NULL) != 0) {
        perror("pthread_join failed");  // エラー処理
        exit(1);
    }
    if (pthread_join(tid2, NULL) != 0) {
        perror("pthread_join failed");  // エラー処理
        exit(1);
    }
}
int main() {
    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
    srand(time(NULL));  // 乱数のシードを設定
    initialize_matrices(A, B);

    clock_t start, end;  // 処理時間を格納する変数

    // シングルプロセスでの計算
    start = clock();
    multiply_partial(A, B, C, 0, SIZE);
    end = clock();
    printf("Single process time: %fs\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    // マルチプロセスでの計算
    start = clock();
    multiply_matrices_multi(A, B, C);
    end = clock();
    printf("Multi process time: %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    multiply_matrices_thread(A, B, C);
    end = clock();
    printf("Multi thread time: %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
