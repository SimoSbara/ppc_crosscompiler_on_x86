#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 

int main(int argc, char *argv[])
{
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr; 

    char sendBuff[1025];
    time_t ticks; 

    int sockErr = 0;
    int sockRet = 0;
    socklen_t len = sizeof (sockErr);
    char recvBuff[1024];
    int n = 0;

    bool blockmode = 1; //non bloccante

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5000); 

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 

    do
    {
        listen(listenfd, 10); 
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); 

        int length = 0;   
        while ((n = read(connfd, recvBuff, sizeof(recvBuff)-1)) > 0)
        {

            length += n;

           // printf("lunghezza messaggio %d\n", length);
        }

        recvBuff[length] = 0;

        if(length > 0)
            printf("message from client: %s\n", recvBuff);

        close(connfd);
        sleep(1);
    }
    while(strcmp(recvBuff, "exit"));

    printf("disconnection...\n");
}