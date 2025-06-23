CC = clang
CFLAGS = -std=c99 -Wall -Wpedantic

HTTPServer : main.o socket.o
	$(CC) main.o socket.o -o HTTPServer
	make clean
	clear
	./HTTPServer


main.o : main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

socket.o : socket/socket.c
	$(CC) $(CFLAGS) -c socket/socket.c -o socket.o

clean:
	rm -f *.o 




