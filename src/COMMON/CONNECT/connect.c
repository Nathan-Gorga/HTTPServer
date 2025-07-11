#include "connect.h"


sock_info connectTCP(const char * restrict server_ip, const uint16_t server_port, const int * restrict client_fd){

    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;

    server_addr.sin_port = htons(server_port);

    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) return (sock_info){-1, {}};

    if (connect(*client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) return (sock_info){-1, {}};

    printf("Connected to server at %s:%d\n", server_ip, server_port);

    return (sock_info){*client_fd, server_addr};

}

void receiveMessage(const int client_fd, char messageBack[]){

    char buffer[1024] = {0};
        
    int bytes_received = recv(client_fd, buffer, sizeof(buffer) - 1, 0);

    if (bytes_received <= 0) {

        printf("Client disconnected\n");

        messageBack[0] = '\0';

        return;
    }

    buffer[bytes_received] = '\0';

    strcpy(messageBack, buffer);
}




