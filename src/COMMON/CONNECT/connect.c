#include "connect.h"


sock_info connectTCP(const char * restrict server_ip, const uint16_t server_port, const int * restrict client_fd, const char * restrict username){

    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;

    server_addr.sin_port = htons(server_port);

    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) return (sock_info){-1, {}};

    if (connect(*client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) return (sock_info){-1, {}};

    printf("Connected to server at %s:%d\n", server_ip, server_port);

    sendMessage(username, *client_fd);

    return (sock_info){*client_fd, server_addr};

}

void receiveMessage(const int client_fd, char messageBack[], const char * restrict username){

    char buffer[1024] = {0};
        
    int bytes_received = recv(client_fd, buffer, sizeof(buffer) - 1, 0);

    if (bytes_received <= 0) {

        printf("%s disconnected\n", username);

        messageBack[0] = '\0';

        return;
    }

    buffer[bytes_received] = '\0';

    strcpy(messageBack, buffer);
}


int sendMessage(const char * restrict message, const int client_fd){

    if (strcmp(message, "quit()\n") == 0) return -1;

    send(client_fd, message, strlen(message), 0);

    return 0;
}



