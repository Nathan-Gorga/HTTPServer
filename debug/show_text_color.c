#include <stdio.h>
#include "text_color.h"

/*

// Background Colors
#define BG_BLACK     "\033[40m"
#define BG_RED       "\033[41m"
#define BG_GREEN     "\033[42m"
#define BG_YELLOW    "\033[43m"
#define BG_BLUE      "\033[44m"
#define BG_MAGENTA   "\033[45m"
#define BG_CYAN      "\033[46m"
#define BG_WHITE     "\033[47m"


 */

int main(void){
    
    printf(BOLD"bold\n"RESET);
    printf(DIM"dim\n"RESET);
    printf(ITALIC"italic\n"RESET);
    printf(UNDERLINE"underline\n"RESET);
    printf(BLINK"blink\n"RESET);
    printf(REVERSE"reverse\n"RESET);
    printf(HIDDEN"hidden\n"RESET);
    printf(STRIKETHROUGH"strinkethrough\n"RESET);
    
    printf(BLACK"black\n"RESET);
    printf(RED"red\n"RESET);
    printf(GREEN"green\n"RESET);
    printf(YELLOW"yellow\n"RESET);
    printf(BLUE"blue\n"RESET);
    printf(PURPLE"purple\n"RESET);
    printf(CYAN"cyan\n"RESET);
    printf(WHITE"white\n"RESET);
    
    printf(BG_BLACK"background black\n"RESET);
    printf(BG_RED"background red\n"RESET);
    printf(BG_GREEN"background green\n"RESET);
    printf(BG_YELLOW"background yellow\n"RESET);
    printf(BG_BLUE"background blue\n"RESET);
    printf(BG_PURPLE"purple\n"RESET);
    printf(BG_CYAN"background cyan\n"RESET);
    printf(BG_WHITE"background white\n"RESET);
    
    return 0;

}