#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <errno.h> // errno
#include <string.h> // strerror()

int main(int argc, char const *argv[])
{
	int ret = mknod("hello-nod.file.txt", S_IFREG, 0);
	if (ret == 0) {
		fprintf(stdout, "%s\n", "mknod success");
	} else {
		fprintf(stderr, "errno: %d, error: %s\n", errno, strerror(errno));
		exit(1);
	}
	return 0;
}