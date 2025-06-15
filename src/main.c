#include "definitions.h"
#include "./socket/socket.h"

int main (void){

    //DIVE IN DEPTH INTO THIS FUNCTION AND UNDERSTAND EVERY LINE
    int socket_fd = createTCPSocket();

    if(socket_fd != 0){
        return 1;
    }

    (void)printf("Socket %d listening...\n",socket_fd); 

    if(close(socket_fd) != 0){
        perror("Error closing socket");
        return 1;
    }

    return 0;
}
