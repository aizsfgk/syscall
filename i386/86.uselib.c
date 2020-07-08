#include "base.h"

// uselib - load shared library
// uselib() is Linux-specific

int main(int argc, char const *argv[])
{
	const char *str_so = "./file/str.so";
	int rt = uselib(str_so);

	if (rt == 0) {
		fprintf(stdout, "%s\n", "ok");
	} else {
		perror("uselib");
		exit(EXIT_FAILURE);
	}
	return 0;
}