#include "client.h"



int main(void){
    int sockfd;
    struct sockaddr_in server_addr;

    // 1. Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // 2. Setup server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    // Convert IP string to binary form
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // 3. Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server at %s:%d\n", SERVER_IP, SERVER_PORT);

    // 4. Send a message (optional)
    const char *msg = "Hello from client\n";
    send(sockfd, msg, strlen(msg), 0);

    // 5. Optionally receive a message
    char buffer[1024] = {0};
    int valread = read(sockfd, buffer, sizeof(buffer));
    if (valread > 0) {
        printf("Server says: %.*s\n", valread, buffer);
    }

    // 6. Close socket
    close(sockfd);
    return 0;
}


