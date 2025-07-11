#include "client.h"



int main(void){

    int client_fd = createTCPCLientSocket();

    sock_info client_connection = connectTCP(SERVER_IP, SERVER_PORT, &client_fd);

    if(client_connection.sockfd < 0) goto fail;

    const char *msg = "Hello from client!";
    send(client_fd, msg, strlen(msg), 0);

    close(client_fd);

    return 0;

fail:
    close(client_fd);
    return 1;
}


