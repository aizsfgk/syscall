#include "base.h"

int main(int argc, char const *argv[])
{
	fprintf(stdout, "%s\n", "start write");

	const char *filename = "./file/write.file.txt";
	// O_RDWR 很重要
	int fd = open(filename, O_CREAT|O_APPEND|O_RDWR, S_IRWXU);
	if (fd == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	char buf[] = "hello-world";
	int rs = write(fd, buf, strlen(buf));
	if (rs == -1) {
		perror("write");
		exit(EXIT_FAILURE);
	} else {
		fprintf(stdout, "write: %d\n", rs);
	}

	close(fd);
	
	return 0;
}