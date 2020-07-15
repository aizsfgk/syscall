#include "base.h"
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{

	const char *file = "./file/ftruncate.txt";
	int fd = open(file, O_RDWR, S_IRWXU);

	if (fd < 0) {
		perror("open");
		exit(-1);
	}

	int rt = ftruncate(fd, 3);
	

	if (rt == 0) {
		fprintf(stdout, "%s\n", "ok");
	} else {
		perror("truncate");
		exit(-1);
	}
	return 0;
}