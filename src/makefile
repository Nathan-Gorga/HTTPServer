CC = clang
CFLAGS = -std=c99 -Wall -Wpedantic

HTTPServer : main.o socket.o server.o
	$(CC) main.o socket.o server.o -o HTTPServer
	make clean
	clear
	./HTTPServer


main.o : main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

socket.o : socket/socket.c
	$(CC) $(CFLAGS) -c socket/socket.c -o socket.o


server.o : server/server.c
	$(CC) $(CFLAGS) -c server/server.c -o server.o


clean:
	rm -f *.o 




