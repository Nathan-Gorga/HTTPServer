#include "socket.h"


static int createTCPSocket(int * sockfd){

    *sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(*sockfd < 0) return SOCKET_CREATION_FAILED;

    return OK;
}

static int setTCPSocketOptions(int * sockfd){

    int opt = 1;

    if (setsockopt(*sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {

        (void)close(*sockfd);

        return SET_SOCKOPT_FAILED;
    }

    return OK;
}

static int bindTCPSocket(int * sockfd, struct sockaddr_in * addr){

    (void)memset(addr, 0, sizeof(struct sockaddr_in));

    addr->sin_family = AF_INET;            

    addr->sin_addr.s_addr = INADDR_ANY;    

    addr->sin_port = htons(SERVER_PORT);   
    
    if (bind(*sockfd, (struct sockaddr*)addr, sizeof(struct sockaddr)) < 0) {

        close(*sockfd);
        
        return SOCKET_BIND_FAILED;
    }

    return OK;
}


static int _createTCPServerSocket(int * server_fd, struct sockaddr_in * server_addr){

    if (createTCPSocket(server_fd) != OK) return SOCKET_CREATION_FAILED;
    
    if (setTCPSocketOptions(server_fd) != OK) return SET_SOCKOPT_FAILED;
    
    if (bindTCPSocket(server_fd, server_addr) != OK) return SOCKET_BIND_FAILED;
    
    return OK;  
}

sock_info createTCPServerSocket(void){

    int sockfd;

    struct sockaddr_in server_addr;

    const int code = _createTCPServerSocket(&sockfd, &server_addr);

    switch(code){

        case OK:
            (void)printf(GREEN"Socket created successfully\n"RESET);
            return (sock_info){sockfd, server_addr};

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
    return (sock_info){-1, {}};
}

int createTCPCLientSocket(void){

    int sockfd;
    
    if (createTCPSocket(&sockfd) != OK) return -1;
    
    return sockfd;
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

int acceptTCPRequest(int * server_fd, char * restrict username){
    
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

    receiveMessage(client_fd, username, NULL);

    return client_fd;
}