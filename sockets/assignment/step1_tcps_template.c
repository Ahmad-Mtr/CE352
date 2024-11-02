//step 1: TCP server that accepts a client connection for file transfer.
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

//Declare socket file descriptor.


//Declare receiving and sending buffers of size 10 bytes


//Declare server address to which to bind for receiving messages and client address to fill in sending address


//Connection handler for servicing client request for file transfer
void* connectionHandler(void* sock){
   //declate buffer holding the name of the file from client

   //get the connection descriptor
   
   //Connection established, server begins to read and write to the connecting client
   printf("Connection Established with client IP: %s and Port: %d\n", inet_ntoa(clienAddr.sin_addr), ntohs(clienAddr.sin_port));
   
	//receive name of the file from the client
	
   //open file and send to client
   
   //read file and send to connection descriptor
   
   printf("File transfer complete\n");
   
   //close file
    
   //Close connection descriptor
   
   return 0;
}


int main(int argc, char *argv[]){
 //Get from the command line, server IP, src and dst files.
 if (argc != 2){
	printf ("Usage: %s <port #> \n",argv[0]);
	exit(0);
 } 
 //Open a TCP socket, if successful, returns a descriptor

 //Setup the server address to bind using socket addressing structure

 //bind IP address and port for server endpoint socket 

 // Server listening to the socket endpoint, and can queue 5 client requests
 printf("Server listening/waiting for client at port 5000\n");

 //Server accepts the connection and call the connection handler

 
 //close socket descriptor

 return 0;
}