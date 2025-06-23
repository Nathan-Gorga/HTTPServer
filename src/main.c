#include "definitions.h"
#include "./socket/socket.h"

int main (void){

    //DIVE IN DEPTH INTO THIS FUNCTION AND UNDERSTAND EVERY LINE
    int socket_fd = createTCPSocket();
    
    PRINTF_DEBUG


    if(close(socket_fd) != 0){
        perror("Error closing socket");
        return 1;
    }

    return 0;
}
