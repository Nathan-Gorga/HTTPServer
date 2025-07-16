#ifndef FILE_H
#define FILE_H

#include "../definitions.h"

#define SAVE_TO_FILE_NAME "conversation.txt"

int closeFile(FILE * fp);

FILE * openFile(void);

int writeToFile(FILE * fp, char * message);


#endif

