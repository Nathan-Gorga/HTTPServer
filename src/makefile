CC=gcc
CFLAGS=-Wall -Wextra -Werror -Wpedantic
LDFLAGS=

SRCS=main.c socket/socket.c server/server.c
OBJS=$(SRCS:.c=.o)
EXEC=HTTPServer

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o
