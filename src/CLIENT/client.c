#include "client.h"



int main(void){
    struct sockaddr_in server_addr;
    int client_fd;
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    // Convert IP string to binary form
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) return 1;

    client_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (client_fd != 0) return 1;

    if(connectTCP((struct sockaddr*)&server_addr, &client_fd) != 0){
        closeTCPSocket(&client_fd);
        return 1;
    }//BUG : connection does nothing


    return 0;
}


