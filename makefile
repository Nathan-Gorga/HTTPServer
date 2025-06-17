CC = clang
CFLAGS = -std=c99 -Wall -Wpedantic

HTTPServer : main.o socket.o
	$(CC) main.o socket.o -o HTTPServer
	make clean
	./HTTPServer


main.o : src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o main.o

socket.o : src/socket/socket.c
	$(CC) $(CFLAGS) -c src/socket/socket.c -o socket.o

clean:
	rm -f *.o 




