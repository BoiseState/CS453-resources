#include	"myheader.h"


void dg_cli(FILE *fp, int sockfd, const struct sockaddr *pservaddr, socklen_t servlen);

int main(int argc, char **argv)
{
	int					sockfd;
	struct sockaddr_in	servaddr;

	if (argc != 2)
		err_quit("usage: udpcli <IPaddress>");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0)
	{
		perror("udpclient1:");
		exit(1);
	}

	dg_cli(stdin, sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

	exit(0);
}

#define	NDG		2000	/* #datagrams to send */
#define	DGLEN	1400	/* length of each datagram */

void dg_cli(FILE *fp, int sockfd, const struct sockaddr *pservaddr, socklen_t servlen)
{
	int		i;
	char	sendline[DGLEN], recvline[DGLEN];
	int 	status;
	int 	count=0;
	ssize_t n;
	struct sockaddr *preplyaddr;
	socklen_t len;

	preplyaddr = (struct sockaddr *) malloc(sizeof(struct sockaddr));
	if (preplyaddr == NULL) {
		perror("udpclient1: malloc for preplyaddr failed!");
		exit(1);
	}
	for (i = 0; i < NDG; i++) {
		status = sendto(sockfd, sendline, DGLEN, 0, pservaddr, servlen);
		if (status < 0) perror("udpclient1:");
		len = servlen;
		n = recvfrom(sockfd, recvline, DGLEN, 0, preplyaddr, &len);
		if (n < 0) 
			perror("udpclient1:");
		else {
			if ((len != servlen)||(memcmp(preplyaddr, pservaddr, len)!=0)) {
				printf("reply from %s (ignored)\n", Sock_ntop(preplyaddr, len)); 
			}
			count++;
			printf("Recv'd datagram #%d back from the server %s\n", 
					count, Sock_ntop(preplyaddr, len));
		}
	}
}
