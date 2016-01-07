
#include <iostream>
#include <stdlib.h>

using namespace std;

const int KB=1024;

int main(int argc, char **argv) {

	if (argc != 2) {
		cerr << "Usage: " << argv[0] 
				<< " <memory chunk size (in Kilobytes)> \n";
		exit(1);
	}

	int count=0;
	int chunk = atoi(argv[1]);
	while (1) {
		int *tmp = new int[chunk*KB];
		if (!tmp) 
			cerr << "Memory exhausted!" << endl;
		/*sleep(1);*/
		// system("free");  -- free is not part of the cygwin library
		count++;
		cout << "allocated " << count << " chunks \n";
	}
}
