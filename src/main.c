#include "main.h"

int main (void){
    printf("Hello, world!\n");

    const int socket_fd1 = createTCPSocket();
    const int socket_fd2 = createTCPSocket();
    const int socket_fd3 = createTCPSocket();
    const int socket_fd4 = createTCPSocket();

    if (socket_fd1 < 0) return 1;
    if (socket_fd2 < 0) return 1;
    if (socket_fd3 < 0) return 1;
    if (socket_fd4 < 0) return 1;

    printf("Socket created: %d\n", socket_fd1);
    printf("Socket created: %d\n", socket_fd2);
    printf("Socket created: %d\n", socket_fd3);
    printf("Socket created: %d\n", socket_fd4);

    close(socket_fd1);
    close(socket_fd2);
    close(socket_fd3);
    close(socket_fd4);

    return 0;
}
