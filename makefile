
HTTPServer : main.o
	clang main.o -o HTTPServer
	make clean
	./HTTPServer


main.o : main.c
	clang -c main.c -o main.o

clean:
	rm -f *.o 




