#include <unistd.h>
#include <string.h>

ssize_t read(int fd, void *buf, size_t count) {

    static int done = 0;

    if (!done) {
        char silly_str[] = "Haha you got overriden.\n";
        size_t s = count > sizeof(silly_str) ? sizeof(silly_str) : count;
        memcpy(buf, silly_str, s);
        done = 1;
        return s;
    }
    else {
		return 0;
	}
}

