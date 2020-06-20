#include <unistd.h>
#include <stdio.h>  // fsprintf
#include <stdlib.h> // exit, NULL

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> // O_CREAT|O_APPEND, S_IRWXU

#include <errno.h>


int main(int argc, char const *argv[])
{

	// fprintf(stdout, "SSIZE_MAX: %ld\n", (long) SSIZE_MAX);

	int fd = open("./file.txt", O_CREAT|O_APPEND, S_IRWXU);
	if (fd < 0 ) {
		fprintf(stderr, "%s\n", "open err");
		exit(1);
	}

	char buf[100];
	int read_size = read(fd, buf, 100);
	if (read_size > 0) {
		fprintf(stdout, "read_ret: %s\n", buf);
	} else if (read_size == 0) {
		fprintf(stdout, "read EOL\n");
	} else {

		// 错误码处理
		
		if (errno == EAGAIN) {

		}

		fprintf(stderr, "%s\n", "read err");
	}
	return 0;
}
