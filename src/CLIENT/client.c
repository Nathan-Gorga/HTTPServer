#include "client.h"



int main(void){

    int client_fd = createTCPCLientSocket();

    int try_connection = 5;

    sock_info client_connection;

    do{

        client_connection = connectTCP(SERVER_IP, SERVER_PORT, &client_fd);
        
        sleep(1);

        printf("Attempting connection to server...\n");
        
    }while(client_connection.sockfd < 0 && try_connection--);

    if(try_connection <= 0) printf(RED"Connection failed\n"RESET); goto fail;
    
    while(1){

        char buffer[1024] = {'\0'};

        printf("> ");
        
        fgets(buffer, sizeof(buffer), stdin);

        if (strcmp(buffer, "quit()\n") == 0) break;

        send(client_fd, buffer, strlen(buffer), 0);
    }

    close(client_fd);

    return 0;

fail:
    close(client_fd);
    return 1;
}


