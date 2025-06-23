#include "definitions.h"
#include "./socket/socket.h"


#define VERBOSE true

int main (void){

    //DIVE IN DEPTH INTO THIS FUNCTION AND UNDERSTAND EVERY LINE
    int socket_fd = createTCPSocket();
    
    PRINTF_DEBUG

    if (listen(socket_fd, 3) != 0) {
        perror(ERROR"listen failed"RESET);
        exit(EXIT_FAILURE);
    }

    if(VERBOSE)
        PRINT_FUNC(void)printf("socket %d listening...\n",socket_fd); 

    if(close(socket_fd) != 0){
        perror("Error closing socket");
        return 1;
    }

    return 0;
}
