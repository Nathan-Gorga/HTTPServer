# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

# Source and object files
SRCS = SERVER/server.c SOCKET/socket.c CONNECT/connect.c 
OBJS = $(SRCS:.c=.o)

# Output binary
TARGET = Server

# Default rule
all: $(TARGET)
	@make clean
	@./$(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -rf $(OBJS) 
