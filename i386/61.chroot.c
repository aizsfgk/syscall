#include "base.h"

int main(int argc, char const *argv[])
{
	int rt = chroot(".");
	if (rt == -1) {
		perror("chroot");
		exit(EXIT_FAILURE);
	}

	rt = chdir("/");
	if (rt == -1) {
		perror("chdir");
		exit(EXIT_FAILURE);
	}

	char *arrays[]={"hello-chroot",NULL};
    execvp("/output/42.pipe", arrays);

	return 0;
}