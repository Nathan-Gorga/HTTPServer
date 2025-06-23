#include "socket.h"

#define LOCAL_IP_ADDRESS ((in_addr_t) htonl(0x7F000001))
#define SERVER_SOCKET_PORT 8080


enum RETURN_ERROR_CODES createTCPSocket(int * socket_fd_ptr){//IPV4


    PRINT_FUNC(void)printf("initializing socket...\n");    
    int server_socket_fd;

    struct sockaddr_in address;

    // Creating socket file descriptor
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror(ERROR"socket creation failed"RESET);
        exit(EXIT_FAILURE);
        return SOCKET_CREATION_FAILED;
    }
    
    PRINT_FUNC(void)printf("socket %d created\n", server_socket_fd);    

    
    // USEFUL WHEN MULTI_THREADING OR LOAD BALANCING, FOR NOW, NOT OF USE
    // Forcefully attaching socket to the port 8080
    // if (setsockopt(server_socket_fd, SOL_SOCKET,
    //                SO_REUSEADDR | SO_REUSEPORT, &opt,
    //                sizeof(opt))) {
    //     perror("setsockopt");
    //     exit(EXIT_FAILURE);
    // }


    address.sin_family = AF_INET;
    address.sin_addr.s_addr = LOCAL_IP_ADDRESS;
    address.sin_port = htons(SERVER_SOCKET_PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_socket_fd, (struct sockaddr*)&address,
             sizeof(address))
        < 0) {
        perror(ERROR"bind failed"RESET);
        exit(EXIT_FAILURE);
        return BIND_FAILED;
    }
    char ip_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(address.sin_addr), ip_str, INET_ADDRSTRLEN);
    
    PRINT_FUNC(void)printf("socket %d successfully bound to address/port : %s:%d\n", server_socket_fd, ip_str, ntohs(address.sin_port));    

    
    *socket_fd_ptr = server_socket_fd;
    return SUCCESS;
}
