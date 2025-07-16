#include "file.h"

FILE * openFile(void){

    FILE * fp = fopen(SAVE_TO_FILE_NAME, "w");

    if (fp == NULL) {

        printf("File could not be opened\n");

        return NULL;

    }   

    return fp;
}

int closeFile(FILE * fp){

    return fclose(fp);

}


int writeToFile(FILE * fp, char * message){
    
    if(fprintf(fp, "%s\n", message) < 0) return -1;
    
    return 0; 
}



