#include "socket.h"
#define PORT 8080

RETURN_CODES _createTCPSocket(int * sockfd){//TESTME


    struct sockaddr_in server_addr;

    // 1. Create socket
    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0) return SOCKET_CREATION_FAILED;

    // 2. Set socket options (optional but recommended)
    int opt = 1;
    if (setsockopt(*sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        close(*sockfd);
        return SET_SOCKOPT_FAILED;
    }

    // 3. Prepare sockaddr_in structure
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;            // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY;    // Any incoming interface
    server_addr.sin_port = htons(PORT);          // Port in network byte order

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
            printf(GREEN"Socket created successfully\n"RESET);
            return sockfd;

        case SOCKET_CREATION_FAILED:
            printf(ERROR"Socket creation failed\n"RESET);
            break;
        
        case SET_SOCKOPT_FAILED:
            printf(ERROR"Setting socket options failed\n"RESET);
            break;
        
        case SOCKET_BIND_FAILED:
            printf(ERROR"Socket bind failed\n"RESET);
            break;

        default:         
            printf(ERROR"Unknown error\n"RESET);
    }
    return -1;
}



