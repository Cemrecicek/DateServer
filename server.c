#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    int address_length = sizeof(client_address);
    char buffer[1024] = {0};
    time_t current_time;
    struct tm *local_time_info;
    char date_string[30];

    
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    
    if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&address_length)) < 0) {
        perror("Accept failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

   
    time(&current_time);
    local_time_info = localtime(&current_time);
    strftime(date_string, 30, "%Y-%m-%d", local_time_info);

   
    send(client_socket, date_string, strlen(date_string), 0);
    printf("Date sent to client: %s\n", date_string);

    
    close(client_socket);
    close(server_socket);
    return 0;
}
