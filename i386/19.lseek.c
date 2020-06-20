#include <sys/types.h>
#include <unistd.h>

#include <sys/stat.h>
#include <fcntl.h>


#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	const char * filename = "file.hello-lseek.txt";
	int fd = open(filename, O_RDWR|O_APPEND, S_IRWXU);
	if (fd < 0 ) {
		perror("open");
		exit(1);
	}
	off_t offset = lseek(fd, 5, SEEK_SET);
	if (offset == -1) {
		perror("lseek");
		exit(1);
	}


	char buf[100];

	int size = read(fd, buf, 50);
	if (size < 0 ) {
		perror("read");
		exit(1);
	}

	fprintf(stdout, "buf: %s\n", buf);

	return 0;
}