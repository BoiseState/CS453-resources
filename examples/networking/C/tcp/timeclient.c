#include	<myheader.h>

int main(int argc, char **argv)
{
	int					sockfd, n;
	char				recvline[MAXLINE + 1];
	struct addrinfo hints, *res;


	if (argc != 2)
		err_quit("Usage: timeclient <hostname>");

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	getaddrinfo(argv[1], "5005" , &hints, &res);

	if ((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0)
		err_sys("socket error");

	if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0)
		err_sys("connect error");

	while ( (n = read(sockfd, recvline, MAXLINE)) > 0) {
		recvline[n] = 0;	/* null terminate */
		if (fputs(recvline, stdout) == EOF)
			err_sys("fputs error");
	}
	if (n < 0)
		err_sys("read error");

	exit(0);
}
