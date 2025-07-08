#ifndef DEBUG_H
#define DEBUG_H

#include "../src/definitions.h"
#include "text_color.h"

// #define DEBUG_MODE
#define ASSERT_MODE
#define FUNC_IN_PRINTF

#ifdef DEBUG_MODE
#define  PRINTF_DEBUG do{(void)printf("DEBUG : %s:%d:%s: \n",__FILE__,__LINE__,__func__); (void)fflush(stdout);}while(0);
#else
#define PRINTF_DEBUG
#endif

#ifdef FUNC_IN_PRINTF
    #define  printf(...) (void)printf(FUNC"%s"RESET" : ", __func__);printf(__VA_ARGS__); (void)fflush(stdout);
#else
    #define PRINT_FUNC
#endif


#endif
