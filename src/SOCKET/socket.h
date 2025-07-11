#ifndef SOCKET_H
#define SOCKET_H

#include "../definitions.h"
#include "../SERVER/server.h"

#define BACKLOG 5

int createTCPServerSocket(void);

int listenTCPSocket(int * sockfd);

int closeTCPSocket(int * sockfd);

int acceptTCPRequest(int * sockfd);



#endif



