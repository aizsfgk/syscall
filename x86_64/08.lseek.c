#include "base.h"

int main(int argc, char const *argv[])
{
	const char *filename = "./file/lseek.file.txt";
	int fd = open(filename, O_CREAT|O_RDWR);
	if (fd == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	ssize_t s = write(fd, "hello-world", 11);
	if (s == -1) {
		perror("write");
		exit(EXIT_FAILURE);
	}

	off_t t = lseek(fd, 5, SEEK_SET);
	if (t == -1) {
		perror("lseek");
		exit(EXIT_FAILURE);
	}

	char buf[10];
	s = read(fd, buf, 10);
	if (s == -1) {
		perror("read");
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "buf: %s\n", buf);


	return 0;
}