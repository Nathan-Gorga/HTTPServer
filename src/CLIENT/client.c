#include "client.h"



int main(void){

    int client_fd = createTCPCLientSocket();

    sock_info client_connection = connectTCP(SERVER_IP, SERVER_PORT, &client_fd);

    if(client_connection.sockfd < 0) goto fail;

    char buffer[1024] = {0};

    while(1){
        printf("> ");
        scanf("%s",buffer);//FIXME : buffer overflow hazard

        send(client_fd, buffer, strlen(buffer), 0);

    }

    close(client_fd);

    return 0;

fail:
    close(client_fd);
    return 1;
}


