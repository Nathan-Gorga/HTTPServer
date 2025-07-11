#include "server.h"

int main (void){

    int server_fd = createTCPServerSocket();

    if (server_fd < 0) return 1;
    
    if(listenTCPSocket(&server_fd) != 0) return 1;

    int client_fd = acceptTCPRequest(&server_fd);

    if(client_fd < 0) return 1;

    if(closeTCPSocket(&server_fd) != 0) return 1;

    if(closeTCPSocket(&client_fd) != 0) return 1;

    return 0;
}
