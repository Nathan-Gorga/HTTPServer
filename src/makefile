# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

# Source and object files
SRCS = main.c SOCKET/socket.c
OBJS = $(SRCS:.c=.o)

# Output binary
TARGET = HTTPServer

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
