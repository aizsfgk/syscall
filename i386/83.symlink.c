#include "base.h"

//  symlink, symlinkat - make a new name for a file


int main(int argc, char const *argv[])
{
	const char *target = "file/link_target.txt";
	const char *linkpath = "./file/link_path_file.txt";


	char cwd[100];
	char *pcwd = realpath(target, cwd);
	if (pcwd == NULL) {
		perror("realpath");
		exit(EXIT_FAILURE);
	}

	int rt = symlink(cwd, linkpath);
	if (rt == 0) {
		fprintf(stdout, "ok\n");
	} else {
		perror("symlink");
		exit(EXIT_FAILURE);
	}
	return 0;
}