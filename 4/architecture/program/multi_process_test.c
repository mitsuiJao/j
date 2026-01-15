#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;

    // 1つ目の子プロセスを作成
    pid1 = fork();
    if (pid1 < 0) {
        perror("fork failed");
        return 1;
    } else if (pid1 == 0) {
        // 子プロセス1のコード
        printf("Hello from Child Process 1 (PID: %d)\n", getpid());
        return 0;
    }

    // 2つ目の子プロセスを作成
    pid2 = fork();
    if (pid2 < 0) {
        perror("fork failed");
        return 1;
    } else if (pid2 == 0) {
        // 子プロセス2のコード
        printf("Hello from Child Process 2 (PID: %d)\n", getpid());
        return 0;
    }

    // 親プロセスのコード
    printf("Hello from Parent Process (PID: %d)\n", getpid());

    // 子プロセスの終了を待機
    wait(NULL); // 1つ目の子プロセス終了待機
    wait(NULL); // 2つ目の子プロセス終了待機

    printf("Parent Process: All child processes have finished.\n");

    return 0;
}