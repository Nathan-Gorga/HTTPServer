#ifndef MYWSASTARTUP_H
#define MYWSASTARTUP_H
#include "../definition.h"

/*after a bit of research, everything I see online uses a library like sys/sockets or winsock to handle the sockets

lame

this might be arrogant or stupid or both, but I want to use NO libraries...

so I'm going to make my own socket library that I can use on this server.

on linux, the first step is for the OS to creatte a file descriptor.

on windows it seems the first step is to use WSAStartup()

https://learn.microsoft.com/fr-fr/windows/win32/api/winsock/nf-winsock-wsastartup

since it's windows, I don't think i'll be able to see the source code 

If I understand what the function does I could replicate it's behavior

let me create it's prototype*/

int myWSAStartup(WORD, WSADATA*);

/* here is an example of the function being called

WORD wVersionRequested;
WSADATA wsaData;
int err;

//Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h
wVersionRequested = MAKEWORD(2, 2);

err = WSAStartup(wVersionRequested, &wsaData);
if (err != 0) {
    // Tell the user that we could not find a usable 
    // Winsock DLL.                                  
    printf("WSAStartup failed with error: %d\n", err);
    return 1;
}*/


/* fundamentally, this is what the function seems to do : 

If the version requested by the application is equal to or greater than the lowest 
version supported by the Winsock DLL, the call succeeds and the Winsock DLL returns 
detailed information in the WSADATA structure pointed to by the lpWSAData parameter

*/


#endif