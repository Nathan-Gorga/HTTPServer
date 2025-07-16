#include "username.h"

int setUsername(char username[], const size_t username_size){

    printf("Set username : ");

    if (fgets(username, username_size, stdin) != NULL) {
        
        username[strcspn(username, "\n")] = '\0';
        
        printf("Hello, %s\n", username);
        
        return 0;
    }

    return -1;

}



