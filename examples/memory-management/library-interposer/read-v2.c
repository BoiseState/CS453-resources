#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <dlfcn.h>

ssize_t read(int fd, void *buf, size_t count) {
	ssize_t (*func)(int, void *, size_t);
	void *handle;
	char *error;

    fprintf(stderr, "Haha system call read got interposed!\n");

	handle = dlopen("libc.so.6", RTLD_LAZY);	
	if ((error = dlerror())) {
		fprintf(stderr, "%s\n", error);
	}
	func = dlsym(handle, "read");
	if ((error = dlerror())) {
		fprintf(stderr, "%s\n", error);
	}
	int result = (*func)(fd, buf, count);
	return result;
}

