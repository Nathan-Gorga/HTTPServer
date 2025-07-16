#include "server.h"

int main (void){

    char username[64] = {'\0'};

    FILE * conversationFile = openFile();

    sock_info server_info = createTCPServerSocket();

    int server_fd = server_info.sockfd;
    // struct sockaddr_in server_addr = server_info.addr;

    if (server_fd < 0) return 1;
    
    if(listenTCPSocket(&server_fd) != 0) return 1;

    int client_fd = acceptTCPRequest(&server_fd, username);

    if(client_fd < 0) return 1;
    
    char buffer[1024] = {'\0'};

    while (1) {

        receiveMessage(client_fd, buffer);
        
        if(buffer[0] == '\0') break;

        if(writeToFile(conversationFile, buffer) != 0) return 1;

        printf("%s: %s",username, buffer);
    }

    if(closeTCPSocket(&server_fd) != 0) return 1;

    if(closeTCPSocket(&client_fd) != 0) return 1;

    if(closeFile(conversationFile) != 0) return 1;

    return 0;
}
