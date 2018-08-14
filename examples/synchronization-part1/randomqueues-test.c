#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int stat[5] = {0,0,0,0,0};
	const int MAXNUM=5;
	int max, min;
	int i, j;

	
	for (j=0; j<100; j++) {
		for (i=0; i<100; i++) {
			stat[random()%MAXNUM]++;
		}
		min = max = stat[0];
		for (i=0; i<MAXNUM; i++) {
			if (stat[i] < min) min=stat[i];
			if (stat[i] > max) max=stat[i];
		}
		printf(" %5d   %5d  %5d  %5d  %5d ----min-max difference %5d \n",
            stat[0], stat[1], stat[2], stat[3], stat[4], max-min);
		for (i=0; i<MAXNUM; i++) {
			stat[i]=0;
		}
	}
	exit(0);
}
