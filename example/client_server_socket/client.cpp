#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

bool connectToServer(int* sockfd, char* addr, sockaddr_in* sockAddr)
{
    if((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        return false;

    if(inet_pton(AF_INET, addr, &sockAddr->sin_addr) <= 0)
        return false;
    
    if(connect(*sockfd, (struct sockaddr *)sockAddr, sizeof(sockaddr_in)) < 0)
        return false;

    return true;
}

int main(int argc, char *argv[])
{
    struct sockaddr_in serv_addr; 
    
    int sockfd = 0, n = 0;
    char recvBuff[1024];
    char message[512];

    if(argc != 2)
    {
        printf("\n Usage: %s <ip of server> \n",argv[0]);
        return 1;
    } 

    memset(recvBuff, '0',sizeof(recvBuff));

    memset(&serv_addr, '0', sizeof(serv_addr)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5000); 

    do
    {
        scanf("insert message: %s", message);
        
        if(!connectToServer(&sockfd, argv[1], &serv_addr))
        {
            printf("\n Error : Connect Failed \n");
            break;
        }

        //send(sockfd, message, strlen(message), 0);
        write(sockfd, message, strlen(message));

        if(!strcmp(message, "exit"))
            break;
        close(sockfd);
    }
    while(1);

    close(sockfd);

    return 0;
}