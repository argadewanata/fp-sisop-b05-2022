#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <sys/stat.h> 
#include <pthread.h>
#include <dirent.h>
#include <dirent.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 8080
#define SIZE 1024

int main ()
{
    char *ip = "127.0.0.1";
    int e;

    int socketFd, new_sock;
    struct sockaddr_in serverAdd, new_addr;
    socklen_t addr_size;
    char buffer[SIZE];

    socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFd < 0) {
        perror("~Error in socket");
        exit(1);
    }
    printf("~Server socket created successfully.\n");

    serverAdd.sin_family = AF_INET;
    serverAdd.sin_port = PORT;
    serverAdd.sin_addr.s_addr = inet_addr(ip);

    e = bind(socketFd, (struct sockaddr *)&serverAdd, sizeof(serverAdd));
    if (e < 0) {
        perror("~Error in bind");
        exit(1);
    }
    printf("~Binding successfull.\n");

    if (listen(socketFd, 10) == 0) {
        printf("~Listening....\n");
    }
    else{
        perror("~Error in listening");
        exit(1);
    }

    addr_size = sizeof(new_addr);
    new_sock = accept(socketFd, (struct sockaddr *)&new_addr, &addr_size);
    printf("~Client connected.\n");

    return 0;
}
