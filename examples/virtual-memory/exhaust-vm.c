
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

const int MB=1024*1024;

int main(int argc, char **argv) {

	if (argc != 2) {
		fprintf(stderr,"Usage: %s memory chunk size (in MB)\n", argv[0]); 
		exit(1);
	}

	int count=0;
	int chunk = atoi(argv[1]);
	while (1) {
		char *tmp = malloc(sizeof(char) * chunk * MB);
		if (!tmp) {
			fprintf(stderr, "Memory exhausted!\n");
			system("free");
		}
		memset(tmp, 0, sizeof(char)*chunk*MB);
		/*sleep(1);*/
		count++;
		printf("allocated %d chunks \n", count);;
	}
}
