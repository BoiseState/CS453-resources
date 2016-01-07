#include <stdio.h>
#include <stdlib.h>            /* exit()                               */
#include <string.h>            /* memset(), memcpy()                   */
#include <sys/utsname.h>       /* uname()                              */
#include <sys/types.h>             
#include <sys/socket.h>        /* socket(), bind(), listen(), accept() */
#include <netinet/in.h>        /* protocol stuff and related macros    */
#include <arpa/inet.h>         /* address conversion stuff             */
#include <netdb.h>             /* hostname related functions           */
#include <unistd.h>            /* POSIX constants.                     */

void err_quit(const char *fmt, ...);
void err_msg(const char *fmt, ...);
void err_ret(const char *fmt, ...);
void err_sys(const char *fmt, ...);



const char MESSAGE[] = "Hello World\n";
const int BACK_LOG = 5;

int main(int argc, char **argv)
{
    int serverSocket = 0,
        on = 0,
        status = 0,
		childPid = 0;

	char *port;
	struct addrinfo hints, *res;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }
    port = argv[1];

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;  // use IPv4 or IPv6, whichever
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;     // fill in my IP for me

	getaddrinfo(NULL, port, &hints, &res);

	serverSocket = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	if (serverSocket < 0) 
		err_quit("Cannot create socket:");
   
    on = 1;
    status = setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));
    if (status == -1) {
        perror("setsockopt(...,SO_REUSEADDR, ...)");
        exit(1);
    }    

    /*
     *  When connection is closed, linger a bit to ensure all 
     *  data has arrived. 
     */
    {
        struct linger linger = { 0 };
        linger.l_onoff = 1;
        linger.l_linger = 30;
        status = setsockopt(serverSocket, SOL_SOCKET, SO_LINGER, (char *) &linger, sizeof(linger));
        if (status == -1) {
            perror("setsockopt(...,SO_LINGER, ...)");
            exit(1);
        }    
    }   
	
	
	if (bind(serverSocket, res->ai_addr, res->ai_addrlen) < 0) {
			err_quit("Bind error:");
    } else {
		fprintf(stderr, "%s: server bound to port %s\n", argv[0], port);    
	}

	if  (listen(serverSocket, BACK_LOG) < 0)
			err_quit("Listen error:");


    while (1) {
        struct sockaddr_in clientName = { 0 };
        int slaveSocket;
		unsigned int clientLength = sizeof(clientName);

        (void) memset(&clientName, 0,sizeof(clientName));

        slaveSocket = accept(serverSocket, (struct sockaddr *) &clientName, &clientLength);
		if (slaveSocket == -1)
	    	err_quit("accept():");

        childPid = fork();
        
        switch(childPid)
		{
        	case -1:  /* fork failed */
            	err_quit("fork()");
        
        	case 0:   /* in child */
            	close(serverSocket);
            	if (-1 == getpeername(slaveSocket, (struct sockaddr *) &clientName, &clientLength))
                	err_quit("getpeername()");
            	else
            	{
                	printf("Connection request from %s\n", inet_ntoa(clientName.sin_addr));
            	}

            /*
             *  Server application specific code goes here.
             */
            	write(slaveSocket, MESSAGE, strlen(MESSAGE));
            	close(slaveSocket);
            	exit(0);

			default:  /* in parent */
            	close(slaveSocket);
		}

    }
    exit(0);
}

