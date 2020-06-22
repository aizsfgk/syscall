#include "base.h"


int main(int argc, char const *argv[])
{
	int ret = rmdir("file/mkdir");
	if (ret == 0) {
		fprintf(stdout, "%s\n", "rmdir ok");
	} else {
		perror("rmdir");
		exit(EXIT_FAILURE);
	}
	return 0;
}