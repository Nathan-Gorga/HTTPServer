#ifndef SOCKET_H
#define SOCKET_H

#include "../definitions.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
/* THIS IS HOW SOCKET CREATION WORKS:*/

/*- 1. Socket Creation 

sockfd = socket(domain, type, protocol)

(sockfd) int: the OS assigns a file descriptor to the socket 

(domain) int: specified the communication domain 

AF_LOCAL for systems on the same host

AF_INET for IPv4

AF_INET6 for IPv6

(type) : specifies the socket type

SOCK_STREAM for TCP

SOCK_DGRAM for UDP

(protocol) : specifies the protocol (number in the IP header)*/



/* - 2 (Optional) Set Socket Options

int ret = setsockopt(sockfd, level, optname, optval, socklen_t optlen);

sockfd identifies the socket

level specifies the level for which the option is being set

optname the name of a specified socket option like GETSOCKOPT/SETSOCKOPT

optval the pointer to option data

optlen the length of the option data

https://pubs.opengroup.org/onlinepubs/000095399/functions/setsockopt.html*/



/* - 3. Binding 

After the creation of the socket, we bind it to an address and a port 

bind(sockfd, sockaddr *addr, socklen_t addrlen);

this information is specified in addr*/

/* - 4. Listen

listen(sockfd, backlog);

the server puts the socket in a passive state to wait for a client connection

The backlog, defines the maximum length to which the queue of pending connections for sockfd may grow.*/



/* - 5. Accept

the server extracts the first connection request from the queue

once the accept function is called, the server creates a new socket and returns its file descriptor

the connection is established with the client*/



/* - 6. Send/Receive

can send data to the client or receive data from the client.*/



/* - 7. Close

Close the socket*/

enum RETURN_ERROR_CODES createTCPSocket(int*);

enum RETURN_ERROR_CODES{ 
    SUCCESS,
    SOCKET_CREATION_FAILED,
    BIND_FAILED,    
    LISTEN_FAILED,
    RECV_FAILED,
    SENDING_FAILED,
    CLOSING_SOCKET_FAILED,
    NUM_ERROR_CODES      
};


#endif
