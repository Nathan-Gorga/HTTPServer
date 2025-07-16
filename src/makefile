# Compiler and flags
CC = clang
CFLAGS = -Wall -Wextra -Werror -std=c11

# Sources
COMMON_SRC = ./COMMON/SOCKET/socket.c ./COMMON/CONNECT/connect.c ./COMMON/FILE/file.c ./COMMON/USERNAME/username.c
SERVER_SRC = ./SERVER/server.c $(COMMON_SRC)
CLIENT_SRC = ./CLIENT/client.c $(COMMON_SRC)

# Targets
SERVER_BIN = server
CLIENT_BIN = client

.PHONY: all clean

all: $(SERVER_BIN) $(CLIENT_BIN)
	@make clean
	@./$(SERVER_BIN)

$(SERVER_BIN): $(SERVER_SRC)
	$(CC) $(CFLAGS) -o $@ $^

$(CLIENT_BIN): $(CLIENT_SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf "*.o"
