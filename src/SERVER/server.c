#include "server.h"

int main (void){

    sock_info server_info = createTCPServerSocket();

    int server_fd = server_info.sockfd;
    // struct sockaddr_in server_addr = server_info.addr;

    if (server_fd < 0) return 1;
    
    if(listenTCPSocket(&server_fd) != 0) return 1;

    int client_fd = acceptTCPRequest(&server_fd);

    if(client_fd < 0) return 1;

    char buffer[1024] = {0};

    int bytes_received = recv(client_fd, buffer, sizeof(buffer) - 1, 0); // leave space for '\0'

    if (bytes_received > 0) {

        buffer[bytes_received] = '\0'; // Null-terminate
        
        printf("Received from client: %s\n", buffer);

    } else if (bytes_received == 0) {

        printf("Client disconnected\n");
    } else {
        
        perror("recv failed");
    }

    if(closeTCPSocket(&server_fd) != 0) return 1;

    if(closeTCPSocket(&client_fd) != 0) return 1;

    return 0;
}
