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

#define	NDG		8000	/* #datagrams to send */
#define	DGLEN	1400	/* length of each datagram */

void dg_cli(FILE *fp, int sockfd, const struct sockaddr *pservaddr, socklen_t servlen)
{
	int		i;
	char	sendline[DGLEN];
	int 	status;
	/*int		j;*/
	/*long x;*/

	for (i = 0; i < NDG; i++) {
		status = sendto(sockfd, sendline, DGLEN, 0, pservaddr, servlen);
		if (status < 0)
			perror("udpclient1:");
		printf("Sent datagram #%d\n", i);
		/*usleep(1);*/
		/*for (j=1; j<100; j++)*/
			/*x = random() % j;*/
	}
}
