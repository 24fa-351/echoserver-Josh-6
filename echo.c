#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

int main(int argc, char *argv[]) 
{
    int server_socket, client_socket, port;
    struct sockaddr_in server_address, client_address;
    socklen_t client_len = sizeof(client_address);

    // Argument parsing for -p
    if (argc != 3 || strcmp(argv[1], "-p") != 0) {
        fprintf(stderr, "Format: %s -p <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    port = atoi(argv[2]);
    
    // Create a TCP socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0)
    {
        fprintf(stderr, "Socket creation failed");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Socket successfully created..\n"); 
        bzero(&server_address, sizeof(server_address)); 
    }

    // assign ip to port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    // Binding newly created socket to given IP and verification 
    if ((bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address))) != 0) { 
        printf("socket bind failed...\n"); 
        close(server_socket);
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 

    

    return 0;
}

