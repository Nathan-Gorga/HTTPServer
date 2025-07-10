#ifndef CLIENT_H
#define CLIENT_H

#include "../definitions.h"

int connectTCP(struct sockaddr * server_addr, int * client_fd);

#endif

