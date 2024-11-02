//step 2: TCP client requesting a file transfer from the server.
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
    //Get from the command line, server IP, src and dst files.
    if (argc != 5){
		printf ("Usage: %s <ip of server> <port #> <src_file> <dest_file>\n",argv[0]);
		exit(0);
    } 
    //Declare socket file descriptor and buffer
    int sockfd;
    char buf[10];

    //Declare server address to accept
    

   //Declare host
    

    //get hostname
    

    //Open a socket, if successful, returns
    

    //Set the server address to send using socket addressing structure
    

    //Connect to the server
    
    //Client sends the name of the file to retrieve from the server
    

    //Client begins to write and read from the server
    
    //Close socket descriptor
    
    return 0;
}