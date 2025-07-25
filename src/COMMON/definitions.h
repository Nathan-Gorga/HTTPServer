#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <arpa/inet.h>
#include "../../debug/debug.h"

typedef enum {
    OK,
    SOCKET_CREATION_FAILED,
    SET_SOCKOPT_FAILED,
    SOCKET_BIND_FAILED,
    NUM_CODES,
}RETURN_CODES;

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
}sock_info;



#endif




