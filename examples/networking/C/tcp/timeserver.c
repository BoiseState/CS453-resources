#include	<myheader.h>
#include	<time.h>

int main(int argc, char **argv)
{
	int					listenfd, connfd;
	char				buff[MAXLINE];
	time_t				ticks;
	struct addrinfo hints, *res;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;  // use AF_INET for IPv4 or AF_INET6 for IPv6, whichever
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;     // fill in my IP for me

	getaddrinfo(NULL, "5005", &hints, &res);

	listenfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	if (listenfd < 0) err_quit("Cannot create socket:");

	if (bind(listenfd, res->ai_addr, res->ai_addrlen) < 0)
			err_quit("Bind error:");

	if  (listen(listenfd, LISTENQ) < 0)
			err_quit("Listen error:");

	for (;;) {
		connfd = accept(listenfd, (struct sockaddr *) NULL, NULL);
		if (connfd < 0) err_ret("Accept error: ");

        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        write(connfd, buff, strlen(buff));

		close(connfd);
	}
}
