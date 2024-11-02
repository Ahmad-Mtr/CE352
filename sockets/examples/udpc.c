//UDP Client
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char *argv[]){
 //Get from the command line, server IP, src and dst files.
 if (argc != 3){
	printf ("Usage: %s <ip of server> <port #> \n",argv[0]);
	exit(0);
 } 
 //Declare socket file descriptor. All Unix I/O streams are referenced by descriptors
 int sockfd; 

 //Declare sending buffer of size 1k bytes
 char sbuf[1024], rbuf[1024]; 
 
 //Declare server address
 struct sockaddr_in servAddr, clienAddr; 
 socklen_t addrLen = sizeof(struct sockaddr);

 //Converts domain names into numerical IP addresses via DNS
 struct hostent *host;
 host = (struct hostent *)gethostbyname(argv[1]); //You may use "localhost" or "127.0.0.1": loopback IP address
 
 //Open a socket, if successful, returns adescriptor associated with an endpoint 
 if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("Failure to setup an endpoint socket");
    exit(1);
 }

 //Set the server address to send using socket addressing structure
 servAddr.sin_family = AF_INET;
 servAddr.sin_port = htons(atoi(argv[2]));
 servAddr.sin_addr = *((struct in_addr *)host->h_addr);

 //Client to send messages to the server continuously using UDP socket 
 while(1){
  printf("Client: Type a message to send to Server\n");
  scanf("%s", sbuf);
  sendto(sockfd, sbuf, strlen(sbuf), 0, (struct sockaddr *)&servAddr, sizeof(struct sockaddr));
 }
 return 0;
}
