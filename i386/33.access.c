#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// access - check real user’s permissions for a file

int main(int argc, char const *argv[])
{
	const char * fileName = "file/access.file.txt";
	int ret = access(fileName, F_OK);
	if (ret == -1) {
		fprintf(stderr, "%s : %s\n", fileName, "file not exists");
	}

	const char *fileName2 = "file/utime.file.txt";
	ret = access(fileName2, F_OK|R_OK|W_OK);
	if (ret == 0) {
		fprintf(stdout, "%s\n", "can rw");
	} else {
		perror("access");
		exit(EXIT_FAILURE);
	}

	return 0;
}