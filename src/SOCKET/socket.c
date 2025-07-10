#include "socket.h"


static RETURN_CODES _createTCPSocket(int * sockfd){


    struct sockaddr_in server_addr;

    // 1. Create socket
    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0) return SOCKET_CREATION_FAILED;

    // 2. Set socket options (optional but recommended)
    int opt = 1;
    if (setsockopt(*sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        (void)close(*sockfd);
        return SET_SOCKOPT_FAILED;
    }

    // 3. Prepare sockaddr_in structure
    (void)memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;            // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY;    // Any incoming interface
    server_addr.sin_port = htons(SERVER_PORT);          // Port in network byte order

    // 4. Bind
    if (bind(*sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        close(*sockfd);
        return SOCKET_BIND_FAILED;
    }

    return OK;  
}

int createTCPSocket(void){

    int sockfd;

    const RETURN_CODES code = _createTCPSocket(&sockfd);

    switch(code){

        case OK:
            (void)printf(GREEN"Socket created successfully\n"RESET);
            return sockfd;

        case SOCKET_CREATION_FAILED:
            (void)printf(ERROR"Socket creation failed\n"RESET);
            break;
        
        case SET_SOCKOPT_FAILED:
            (void)printf(ERROR"Setting socket options failed\n"RESET);
            break;
        
        case SOCKET_BIND_FAILED:
            (void)printf(ERROR"Socket bind failed\n"RESET);
            break;

        default:         
            (void)printf(ERROR"Unknown error\n"RESET);
    }
    return -1;
}

int listenTCPSocket(int * sockfd){
    
    if (listen(*sockfd, BACKLOG) < 0) {
        
        (void)close(*sockfd);
        
        return -1;
    }

    printf("Listening on port %d\n", SERVER_PORT);

    return 0;
}

int closeTCPSocket(int * sockfd){

    (void)close(*sockfd);

    return 0;
}

int acceptTCPRequest(int * server_fd){
    
    struct sockaddr_in client_addr;
    
    socklen_t addr_len = sizeof(client_addr);

    int client_fd;

    printf("Awaiting client connection...\n");

    while (1) {

        client_fd = accept(*server_fd, (struct sockaddr*)&client_addr, &addr_len);

        if (client_fd >= 0) {

            break;

        }
    }

    printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    return client_fd;
}