#include "connect.h"

int connectTCP(struct sockaddr * server_addr, int * client_fd){

    if (connect(*client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        
        close(*client_fd);
        
        return -1;
    }

    return 0;
}







