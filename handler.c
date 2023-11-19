// handler.c
#include "server.h"

void *handle_client(void *arg) {
    int client_socket = *((int *)arg);
    time_t current_time;
    char time_string[50];

    // Get current time
    time(&current_time);
    snprintf(time_string, sizeof(time_string), "%ld", current_time);

    // Build an HTTP response
    char response[200];
    snprintf(response, sizeof(response), "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\n\r\n%s", strlen(time_string), time_string);

    // Send the HTTP response to the client
    send(client_socket, response, strlen(response), 0);

    // Close the client socket
    close(client_socket);

    pthread_exit(NULL);
}
