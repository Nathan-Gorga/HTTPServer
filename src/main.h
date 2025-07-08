#ifndef MAIN_H
#define MAIN_H

#include "definitions.h"
#include "SOCKET/socket.h"





#define MAIN_COLOR "\033[2;36m"
#define  printf(...) (void)printf(MAIN_COLOR"%s"RESET" : ", __func__);printf(__VA_ARGS__);


#endif

