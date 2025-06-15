#include "socket.h"

#define SERVER_SOCKET_PORT 8080

int createTCPSocket(void){//IPV4

    int server_socket_fd;

    struct sockaddr_in address;

    // Creating socket file descriptor
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

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
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_socket_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    return server_socket_fd;
}
