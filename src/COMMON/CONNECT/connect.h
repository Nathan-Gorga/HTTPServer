#ifndef CONNECT_H
#define CONNECT_H

#include "../definitions.h"

sock_info connectTCP(const char * restrict server_ip, const uint16_t server_port, const int * restrict client_fd);

void receiveMessage(const int client_fd, char messageBack[]);

#endif

