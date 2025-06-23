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
#define  PRINT_FUNC (void)printf(FUNC"%s"RESET" : ", __func__);
#else
#define PRINT_FUNC
#endif


#endif
