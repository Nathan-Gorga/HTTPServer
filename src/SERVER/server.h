#ifndef SERVER_H
#define SERVER_H

#include "../definitions.h"
#include "../SOCKET/socket.h"

#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

#define MAIN_COLOR "\033[2;36m"
#define  printf(...) (void)printf(MAIN_COLOR"%s"RESET" : ", __func__);printf(__VA_ARGS__);

#endif

