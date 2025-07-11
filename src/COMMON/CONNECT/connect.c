#include "connect.h"


sock_info connectTCP(const char * restrict server_ip, const uint16_t server_port, const int * restrict client_fd){

    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;

    server_addr.sin_port = htons(server_port);

    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) return (sock_info){-1, {}};

    if (connect(*client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) return (sock_info){-1, {}};

    printf("Connected to server at %s:%d\n", server_ip, server_port);

    return (sock_info){*client_fd, server_addr};

}






