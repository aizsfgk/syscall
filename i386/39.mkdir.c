#include "base.h"

#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	int ret = mkdir("file/mkdir", O_RDWR);
	if (ret == 0) {
		fprintf(stdout, "%s\n", "mkdir ok");
	} else {
		perror("mkdir");
		exit(EXIT_FAILURE);
	}
	return 0;
}