#include "socket.h"

#define SERVER_SOCKET_PORT 8080
#define VERBOSE true

int createTCPSocket(void){//IPV4

    if(VERBOSE)
        (void)printf(FUNC"%s"RESET" : initializing socket...\n", __func__);    
    int server_socket_fd;

    struct sockaddr_in address;

    // Creating socket file descriptor
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror(ERROR"socket creation failed"RESET);
        exit(EXIT_FAILURE);
    }
    if(VERBOSE)
        (void)printf(FUNC"%s"RESET" : socket %d created\n", __func__, server_socket_fd);    

    
    // USEFUL WHEN MULTI_THREADING OR LOAD BALANCING, FOR NOW, NOT OF USE
    // Forcefully attaching socket to the port 8080
    // if (setsockopt(server_socket_fd, SOL_SOCKET,
    //                SO_REUSEADDR | SO_REUSEPORT, &opt,
    //                sizeof(opt))) {
    //     perror("setsockopt");
    //     exit(EXIT_FAILURE);
    // }


    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(SERVER_SOCKET_PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_socket_fd, (struct sockaddr*)&address,
             sizeof(address))
        < 0) {
        perror(ERROR"bind failed"RESET);
        exit(EXIT_FAILURE);
    }
    if(VERBOSE)
        (void)printf(FUNC"%s"RESET" : socket %d successfully bound to address/port : %d/%d\n", __func__, server_socket_fd, address.sin_addr.s_addr, address.sin_port);    

    if (listen(server_socket_fd, 3) < 0) {
        perror(ERROR"listen failed"RESET);
        exit(EXIT_FAILURE);
    }

    if(VERBOSE)
        (void)printf(FUNC"%s"RESET" : socket %d listening...\n", __func__,server_socket_fd); 

    
    return server_socket_fd;
}
