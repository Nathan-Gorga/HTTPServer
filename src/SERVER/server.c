#include "server.h"

int main (void){

    sock_info server_info = createTCPServerSocket();

    int server_fd = server_info.sockfd;
    // struct sockaddr_in server_addr = server_info.addr;

    if (server_fd < 0) return 1;
    
    if(listenTCPSocket(&server_fd) != 0) return 1;

    int client_fd = acceptTCPRequest(&server_fd);

    if(client_fd < 0) return 1;

    while (1) {

        char buffer[1024] = {0};
        
        int bytes_received = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
    
        if (bytes_received <= 0) {

            printf("Client disconnected or error occurred\n");

            break;
        }
    
        buffer[bytes_received] = '\0';
    
        printf("Client says: %s\n", buffer);
    
        // Echo back
        send(client_fd, buffer, bytes_received, 0);
    }

    if(closeTCPSocket(&server_fd) != 0) return 1;

    if(closeTCPSocket(&client_fd) != 0) return 1;

    return 0;
}
