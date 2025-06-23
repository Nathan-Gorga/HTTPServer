#include "definitions.h"
#include "./socket/socket.h"


#define VERBOSE true


void handleClient(int client_socket) {
    const int buffer_size = 4096;
    char buffer[buffer_size] = {0};

    ssize_t bytes_received = recv(client_socket, buffer, buffer_size - 1, 0);
    if (bytes_received < 0) {
        perror("recv failed");
        close(client_socket);
        return;
    }

    printf("---- Received HTTP Request ----\n%s\n", buffer);

    const char *http_response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/plain\r\n"
        "Content-Length: 13\r\n"
        "\r\n"
        "Hello, world!";

    send(client_socket, http_response, strlen(http_response), 0);

    close(client_socket);
}




int main (void){

    //DIVE IN DEPTH INTO THIS FUNCTION AND UNDERSTAND EVERY LINE
    int socket_fd = createTCPSocket();
    
    PRINTF_DEBUG

    if (listen(socket_fd, 3) != 0) {
        perror(ERROR"listen failed"RESET);
        exit(EXIT_FAILURE);
    }

    if(VERBOSE)
        PRINT_FUNC(void)printf("socket %d listening...\n",socket_fd); 


    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_len = sizeof(client_address);

        int client_socket = accept(socket_fd, (struct sockaddr*)&client_address, &client_len);
        if (client_socket < 0) {
            perror("accept failed");
            continue;
        }

        if (VERBOSE) {
            char client_ip[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &client_address.sin_addr, client_ip, sizeof(client_ip));
            printf("Accepted connection from %s:%d\n", client_ip, ntohs(client_address.sin_port));
        }

        handleClient(client_socket);
    }


    if(close(socket_fd) != 0){
        perror("Error closing socket");
        return 1;
    }

    return 0;
}
