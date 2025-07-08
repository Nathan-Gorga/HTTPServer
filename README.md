# HTTP Server Project

## Objective

The objective of this project is to build an HTTP Server in C so that I may understand better how they work and learn more about networking. 

This project will be considered completed when :
- The server will host a chat room. 
- The chat room can be connected to with a regular login, and anyone from any device can access this server on the internet.
- The server also hosts a simple webpage
- The server handles navigation
- The server is secure to most web attacks

## Components

TODO : update
- **src/main.c**: The entry point of the application that starts the TCP server.
- **src/socket/socket.c**: Contains functions related to socket creation and management.
- **src/server/server.c**: Manages the server operations, including accepting client connections and handling requests.
- **debug/text_color.h**: Provides macros for colored text output for debugging purposes.


## Build Instructions

To build the project, execute the following command in the root directory:

```sh
make -f src/makefile
```

## Usage

After building the project, run the server using:

```sh
./HTTPServer
```

The server listens on port 8080 by default. You can connect to it using a web browser or tools like `curl`:

```sh
curl http://localhost:8080
```

## Contributing

Contributions are welcome! Please open issues or submit pull requests on GitHub.

