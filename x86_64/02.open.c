#include "base.h"

int main(int argc, char const *argv[])
{
	fprintf(stdout, "%s\n", "start read");

	const char *filename = "./file/read.file.txt";
	int fd = open(filename, O_CREAT|O_APPEND, S_IRWXU|S_IRWXG);
	if (fd == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	char buf[100];
	int rs = read(fd, buf, 100);
	if (rs == -1) {
		perror("read");
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "read: %s\n", buf);

	close(fd);

	return 0;
}