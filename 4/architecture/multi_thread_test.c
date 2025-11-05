#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// 各スレッドで実行される関数
void* thread_function(void* arg) {
    int thread_num = *((int*)arg); // スレッド番号を取得
    printf("Thread %d is running.\n", thread_num);
    return NULL;
}

int main() {
    pthread_t threads[3]; // スレッドIDを格納する配列
    int thread_args[3];   // スレッドに渡す引数
    int i;

    // スレッドを作成
    for (i = 0; i < 3; i++) {
        thread_args[i] = i + 1; // スレッド番号を設定
        if (pthread_create(&threads[i], NULL, thread_function, &thread_args[i]) != 0) {
            perror("pthread_create failed"); // エラー処理
            exit(1);
        }
    }

    // 全てのスレッドの終了を待機
    for (i = 0; i < 3; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join failed"); // エラー処理
            exit(1);
        }
    }

    printf("All threads have finished.\n");
    return 0;
}