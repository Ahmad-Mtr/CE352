//TCP Client
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    //Get from the command line, server IP, src and dst files.
    if (argc != 3){
		printf ("Usage: %s <ip of server> <port #> \n",argv[0]);
		exit(0);
    } 
    //Declare socket file descriptor and buffer
    int sockfd;
    char rbuf[1024], sbuf[1024];

    //Declare server address to connect to
    struct sockaddr_in servAddr;
    struct hostent *host;

    //get hostname
    host = (struct hostent *) gethostbyname(argv[1]);

    //Open a socket, if successful, returns
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("Failure to setup an endpoint socket");
        exit(0);
    }

    //Set the server address to send using socket addressing structure
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(atoi(argv[2]));
    servAddr.sin_addr = *((struct in_addr *)host->h_addr);

    //Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servAddr, sizeof(struct sockaddr))){
        perror("Failure to connect to the server");
        exit(1);
    }
    
    //Client begins to write and read from the server
    while(1){
        printf("Client: Type a message to send to Server\n");
        scanf("%s", sbuf);
        write(sockfd, sbuf, sizeof(sbuf));
        read(sockfd, rbuf, sizeof(rbuf));
        printf("Server: sent message: %s\n", rbuf);
    }
    //Close socket descriptor
    close(sockfd);
    return 0;
}
