#include "client.h"

int main(void){

    char username[64] = {'\0'};

    setUsername(username, 64);

    int client_fd = createTCPCLientSocket();

    printf("client fd : %d\n", client_fd);

    if(client_fd < 0){

        printf(RED"Socket creation failed\n"RESET); 
        goto fail;
    }

    int try_connection = 5;

    sock_info client_connection;

    do{

        printf("Attempting connection to server...\n");
        
        sleep(1);

        client_connection = connectTCP(SERVER_IP, SERVER_PORT, &client_fd, username);
        
    }while(client_connection.sockfd < 0 && --try_connection);

    if(try_connection <= 0){

        printf(RED"Connection failed\n"RESET);
        goto fail;
    }
    
    while(1){

        char buffer[1024] = {'\0'};

        printf("> ");

        fgets(buffer, sizeof(buffer), stdin);

        if(sendMessage(buffer, client_fd) == -1) break;
    }

    close(client_fd);

    return 0;

fail:
    close(client_fd);
    return 1;
}


