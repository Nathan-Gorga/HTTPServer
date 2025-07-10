#ifndef SOCKET_H
#define SOCKET_H

#include "../definitions.h"

#define BACKLOG 5

int createTCPSocket(void);

int listenTCPSocket(int * sockfd);

int closeTCPSocket(int * sockfd);

int acceptTCPRequest(int * sockfd);



#endif



