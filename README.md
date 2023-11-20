# Simple Multi-Threaded Server

This is a simple multi-threaded server written in C using pthreads. The server listens on a specified port and handles incoming connections concurrently by creating threads for each client.

## Compilation

To compile the program, use the following commands in your terminal:

```bash
gcc -c server.c -o server.o
gcc -c handler.c -o handler.o
gcc server.o handler.o -o myserver -pthread
```

After compilation, you can run the server:

```bash
./myserver
```

## Test

By using curl or applications like Insomnia or Postman, you can create a GET request to http://localhost:8080.
For each request, you'll get unix time as a response, If you send multiple requests, you can see how multiple request can be handled with POSIX by getting response with same unix timestamp.
