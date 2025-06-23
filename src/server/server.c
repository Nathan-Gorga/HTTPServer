#include "server.h"


enum RETURN_ERROR_CODES handleClient(int client_socket) {
    const int buffer_size = 4096;
    char buffer[buffer_size] = {0};

    ssize_t bytes_received = recv(client_socket, buffer, buffer_size - 1, 0);
    if (bytes_received < 0) {
        perror("recv failed");
        close(client_socket);
        return RECV_FAILED;
    }

    printf("---- Received HTTP Request ----\n%s\n", buffer);

    const char *http_response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/plain\r\n"
        "Content-Length: 13\r\n"
        "\r\n"
        "Hello, world!";

    if(send(client_socket, http_response, strlen(http_response), 0) == -1){
        return SENDING_FAILED;
    }

    if(close(client_socket) != 0){
        return CLOSING_SOCKET_FAILED;
    }

    return SUCCESS;
}





enum RETURN_ERROR_CODES launchTCPServer(void){
    //DIVE IN DEPTH INTO THIS FUNCTION AND UNDERSTAND EVERY LINE
    int socket_fd;
    
    enum RETURN_ERROR_CODES return_code = createTCPSocket(&socket_fd);
    
    PRINTF_DEBUG

    if (listen(socket_fd, 3) != 0) {
        perror(ERROR"listen failed"RESET);
        exit(EXIT_FAILURE);
        return LISTEN_FAILED;
    }


    PRINT_FUNC(void)printf("socket %d listening...\n",socket_fd); 

    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_len = sizeof(client_address);

        int client_socket = accept(socket_fd, (struct sockaddr*)&client_address, &client_len);
        if (client_socket < 0) {
            perror("accept failed");
            continue;
        }

        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_address.sin_addr, client_ip, sizeof(client_ip));
        printf("Accepted connection from %s:%d\n", client_ip, ntohs(client_address.sin_port));
        
        enum RETURN_ERROR_CODES return_code = handleClient(client_socket);

        if(return_code != SUCCESS){
            printf("problem handling client\n");
        } else {
            printf("handled client\n");
        }
    }


    if(close(socket_fd) != 0){
        perror("Error closing socket");
        return CLOSING_SOCKET_FAILED;
    }
}

