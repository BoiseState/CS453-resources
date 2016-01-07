
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>


int main(int argc, char **argv)
{
	struct servent *sp;
	int rem;
	char *host = "localhost";
	int rfd2;

    sp = getservbyname("shell", "tcp");
    if (sp == NULL) {
           fprintf(stderr, "rsh: shell/tcp: unknown service.\n");
           exit(1);
    }

    rem = rcmd(&host, sp->s_port, "amit", "amit", "/bin/date > /home/amit/log1", &rfd2);
    rem = rcmd(&host, sp->s_port, "amit", "amit", "/bin/date > /home/amit/log2", &rfd2);
	exit(0);
}
