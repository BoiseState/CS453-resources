#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <myheader.h>


int main(int argc, char **argv)
{
    int clientSocket, status = 0;
    int len, i;
	struct addrinfo hints, *res;
    char buffer[256] = "";
    char *remoteHost = NULL;
	char *remotePort = NULL;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <Serverhost> <serverPort>\n", argv[0]);
        exit(1);
    }
    remoteHost = argv[1];  
    remotePort = argv[2];
   
	memset(&hints, 0, sizeof(hints));
	/* AF_INET is for IPv4, AF_INET6 for IPv6, AF_UNSPEC for either */
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
    status = getaddrinfo(remoteHost, remotePort, &hints, &res);
	if (status < 0) {
		fprintf(stderr, "%s: %s\n", argv[0], gai_strerror(status));
		exit(1);
	}

    clientSocket = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (clientSocket == -1) {
        herror("socket()");
		exit(1);
	}
    
    status = connect(clientSocket, res->ai_addr, res->ai_addrlen );
    if (status == -1)
        err_quit("Error: connect");

    /* Get message from server */
	/* 
	   Note that we loop over read since with TCP, we may get a 50 byte
	   message from the server as a single message or 5 10 byte messages 
       or 50 1 byte messages depending upon the buffering the network 
	   protocol stack in the kernel.
	*/
	while ((status = read(clientSocket, buffer, sizeof(buffer)-1)) > 0) {
    	if (status < 0 )
			err_quit("read()");
    	len = strlen(buffer);
    	for (i=0; i<len; i++)
        	putchar(buffer[i]);
	}
	exit(0);
}
