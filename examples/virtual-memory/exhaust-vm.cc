
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

using namespace std;

const int MB=1024*1024;

int main(int argc, char **argv) {

	if (argc != 2) {
		cerr << "Usage: " << argv[0] 
				<< " <memory chunk size (in MB)> \n";
		exit(1);
	}

	int count=0;
	int chunk = atoi(argv[1]);
	while (1) {
		char *tmp = new char[chunk*MB];
		if (!tmp) {
			cerr << "Memory exhausted!" << endl;
			system("free");
		}
		memset(tmp, 0, sizeof(char)*chunk*MB);
		/*sleep(1);*/
		count++;
		cout << "allocated " << count << " chunks \n";
	}
}
