
HTTPServer : main.o
	clang main.o -o HTTPServer
	make clean
	./HTTPServer


main.o : src/main.c
	clang -c src/main.c -o main.o

clean:
	rm -f *.o 




