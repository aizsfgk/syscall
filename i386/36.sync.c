#include "base.h"

#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	

	int fd = open("./file/sync.file.txt", O_CREAT|O_APPEND|O_RDWR, S_IRWXU);

	if (fd < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	char *buf = "hello-sync-test";
	write(fd, buf, strlen(buf));

	sync();

	return 0;
}