#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <pthread.h>
#include <sys/stat.h> 
#include <dirent.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 8080

int main() 
{
	char *ip = "127.0.0.1";
    int e;

    int socketFd;
    struct sockaddr_in serverAdd;

    socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFd < 0) {
        perror("~Error in socket");
        exit(1);
    }
    printf("~Server socket created successfully.\n");

    serverAdd.sin_port = PORT;
    serverAdd.sin_addr.s_addr = inet_addr(ip);
    serverAdd.sin_family = AF_INET;


    e = connect(socketFd, (struct sockaddr *)&serverAdd, sizeof(serverAdd));
    if (e == -1) {
        perror("~Error in socket");
        exit(1);
    }
    printf("~Connected to Server.\n");

	return 0;
}

