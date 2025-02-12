#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BROADCAST_PORT 9000
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024
#define BROADCAST_MESSAGE "DISCOVER_SERVER"

void start_server();
void start_client(const char *server_ip);
int send_broadcast(char *server_ip);
extern void *connectCS(void);

void *connectCS() {
    char server_ip[INET_ADDRSTRLEN];

    // ブロードキャストを送信して応答を待つ
    if (send_broadcast(server_ip) == 0) {
        printf("Server found at %s. Connecting...\n", server_ip);
        start_client(server_ip); // 応答があったサーバーに接続
    } else {
        printf("No server found. Starting as server...\n");
        start_server(); // サーバーとして起動
    }
}

// ブロードキャストメッセージを送信し、応答を待つ
int send_broadcast(char *server_ip) {
    int sock;
    struct sockaddr_in broadcast_addr, recv_addr;
    socklen_t addr_len = sizeof(recv_addr);
    char buffer[BUFFER_SIZE];

    // UDP ソケットを作成
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        return -1;
    }

    // ブロードキャストを有効化
    int broadcast = 1;
    setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast));

    memset(&broadcast_addr, 0, sizeof(broadcast_addr));
    broadcast_addr.sin_family = AF_INET;
    broadcast_addr.sin_port = htons(BROADCAST_PORT);
    broadcast_addr.sin_addr.s_addr = INADDR_BROADCAST;

    // ブロードキャストメッセージを送信
    printf("Sending broadcast...\n");
    sendto(sock, BROADCAST_MESSAGE, strlen(BROADCAST_MESSAGE), 0,
           (struct sockaddr *)&broadcast_addr, sizeof(broadcast_addr));

    // 応答を待つ
    struct timeval timeout = {5, 0}; // 5秒間待機
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    if (recvfrom(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&recv_addr, &addr_len) > 0) {
        // 応答があればサーバーの IP アドレスを取得
        inet_ntop(AF_INET, &recv_addr.sin_addr, server_ip, INET_ADDRSTRLEN);
        close(sock);
        return 0;
    }

    close(sock);
    return -1; // 応答なし
}

// サーバーとして起動し、クライアントからの接続を待つ
void start_server() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    char buffer[BUFFER_SIZE];

    // TCP ソケットを作成
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(SERVER_PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 1);

    printf("Server is running on port %d. Waiting for a connection...\n", SERVER_PORT);

    // クライアントからの接続を待機
    client_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);
    printf("Client connected.\n");

    // クライアントとの通信を処理
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int recv_bytes = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (recv_bytes <= 0) {
            printf("Client disconnected.\n");
            break;
        }
        printf("Client: %s", buffer);
        send(client_socket, buffer, recv_bytes, 0); // エコー
    }

    close(client_socket);
    close(server_fd);
}

// クライアントとしてサーバーに接続
void start_client(const char *server_ip) {
    int sock;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];

    // TCP ソケットを作成
    sock = socket(AF_INET, SOCK_STREAM, 0);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, server_ip, &server_address.sin_addr);

    // サーバーに接続
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        close(sock);
        return;
    }
    printf("Connected to server at %s.\n", server_ip);

    // サーバーとの通信を処理
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        printf("Enter message: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(sock, buffer, strlen(buffer), 0);

        memset(buffer, 0, BUFFER_SIZE);
        if (recv(sock, buffer, BUFFER_SIZE, 0) <= 0) {
            printf("Server disconnected.\n");
            break;
        }
        printf("Server: %s", buffer);
    }

    close(sock);
}

